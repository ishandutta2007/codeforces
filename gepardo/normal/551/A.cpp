#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

struct stud
{
    int n, r;
};

bool comp(stud a, stud b)
{
    return a.r > b.r;
}

int main()
{
    int n;
    cin >> n;
    vector<stud> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i].r;
        v[i].n = i;
    }
    stable_sort(v.begin(), v.end(), comp);
/*
        for (int i = 0; i < n; i++)
        cout << v[i].r << " ";
        cout << endl;
*/
    int stud[5000];
    int last = 0, lnum = 0;
    for (int i = 0; i < n; i++)
    {
        if (v[i].r != last)
        {
            last = v[i].r;
            lnum = i + 1;
        }
        stud[v[i].n] = lnum;
    }
    for (int i = 0; i < n; i++)
        cout << stud[i] << " ";
}