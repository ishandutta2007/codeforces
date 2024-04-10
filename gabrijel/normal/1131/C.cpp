#include <bits/stdc++.h>
using namespace std;

#define REP(i, a, b) for(int i = a; i < b; i++)

const int maxn = 100100;
const int inf = 1e9 + 100;

int n;

vector <int> svi;

vector <int> l, r;

int main()
{
    cin >> n;
    int x;
    REP(i, 0, n)
    {
        cin >> x;
        svi.push_back(x);
    }
    sort(svi.begin(), svi.end());
    bool li = 1;
    for(int i = svi.size() - 2; i >= 0; i--)
    {
        if(li)
        {
            li = 0;
            l.push_back(svi[i]);
        }
        else
        {
            r.push_back(svi[i]);
            li = 1;
        }
    }
    for(int i = l.size() - 1; i >= 0; i--)
    {
        cout << l[i] << " ";
    }
    cout << svi.back() << " ";
    for(int i = 0; i < r.size(); i++)
    {
        cout << r[i] << " ";
    }
    return 0;
}