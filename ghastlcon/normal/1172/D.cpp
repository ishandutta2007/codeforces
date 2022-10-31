#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <utility>
#define N 1020
using namespace std;

int a[N], b[N];
vector<pair<pair<int, int>, pair<int, int> > > o;

int main(void)
{
    int n;
    int i, j;

    cin >> n;
    for(i = 0; i < n; i ++)
    {
        cin >> a[i];
        a[i] --;
    }
    for(i = 0; i < n; i ++)
    {
        cin >> b[i];
        b[i] --;
    }

    for(i = n - 1; i > -1; i --)
        if(i != a[i] || i != b[i])
        {
            o.push_back(make_pair(make_pair(i, b[i]), make_pair(a[i], i)));
            for(j = 0; j <= i; j ++)
            {
                if(a[j] == i)
                    a[j] = a[i];
                if(b[j] == i)
                    b[j] = b[i];
            }
        }
    cout << o.size() << endl;
    for(i = 0; i < (signed)o.size(); i ++)
        cout << o.at(i).first.first + 1 << ' ' << o.at(i).first.second + 1 << ' ' << o.at(i).second.first + 1 << ' ' << o.at(i).second.second + 1 << endl;

    return 0;
}