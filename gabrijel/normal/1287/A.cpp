#include <bits/stdc++.h>
using namespace std;

#define REP(i, a, b) for(int i = a; i < b; i++)

const int maxn = 100100;
const int inf = 1e9 + 100;
const int mod = 1e9 + 7;

int add(int a, int b)
{
    a += b;
    if(a >= mod) a -= mod;
    if(a < 0) a += mod;
    return a;
}

int mult(int a, int b)
{
    return (long long) a * b % mod;
}

int pot(int a, int b)
{
    int ret = 1;
    while(b)
    {
        if(b & 1) ret = mult(ret, a);
        b >>= 1;
        a = mult(a, a);
    }
    return ret;
}

int t;

string in;

int main()
{
    cin >> t;
    int n;
    REP(tt, 0, t)
    {
        cin >> n;
        cin >> in;
        int br = 0;
        bool poc = 0;
        int rj = 0;
        REP(i, 0, (int)in.size())
        {
            if(in[i] == 'A')
            {
                if(!poc)
                {
                    poc = 1;
                    br = 0;
                }
                else
                {
                    rj = max(rj, br);
                    br = 0;
                }
            }
            else
            {
                br++;
            }
        }
        rj = max(rj, br);
        if(poc) cout << rj << endl;
        else cout << 0 << endl;
    }
    return 0;
}