#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct qs
{
    int v, i, j;
};

int n;
vector <qs> q;
int t[1000] = {};

bool cmp(qs a, qs b)
{
    return a.v > b.v;
}

int main()
{
    cin >> n;
    n *= 2;
    for (int i = 1; i < n; i++)
        for (int j = 0; j < i; j++)
        {
            qs d;
            cin >> d.v;
            d.i = i; d.j = j;
            q.push_back(d);
        }
    sort(q.begin(), q.end(), cmp);
    for (int i = 0; i < q.size(); i++)
    {
        if (t[q[i].i] > 0 || t[q[i].j] > 0) continue;
        t[q[i].i] = q[i].j + 1;
        t[q[i].j] = q[i].i + 1;
    }
    for (int i = 0; i < n; i++) cout << t[i] << " ";
    return 0;
}