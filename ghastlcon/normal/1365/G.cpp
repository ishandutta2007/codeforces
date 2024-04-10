#pragma GCC optimize("O3,inline,unroll-loops")
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#define N 1020
#define C 13
using namespace std;

long long Query(vector<int> v)
{
    int i;
    long long o;

    if(v.empty())
        return 0;

    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    cout << "? " << v.size();
    for(i = 0; i < (signed)v.size(); i ++)
        cout << ' ' << v[i] + 1;
    cout << endl;
    cout.flush();
    cin >> o;

    return o;
}

int main(void)
{
    int n;
    int i, j, c;
    vector<int> v[C];
    long long s[C], o;

    cin >> n;
    for(i = c = 0; i < (1 << C) && c < n; i ++)
        if(__builtin_popcount(i) == C / 2)
        {
            for(j = 0; j < C; j ++)
                if(i & (1 << j))
                    v[j].push_back(c);
            c ++;
        }
    for(i = 0; i < C; i ++)
        s[i] = Query(v[i]);

    cout << '!';
    for(i = 0; i < n; i ++)
    {
        for(j = o = 0; j < C; j ++)
            if(find(v[j].begin(), v[j].end(), i) == v[j].end())
                o |= s[j];
        cout << ' ' << o;
    }
    cout << endl;

    return 0;
}