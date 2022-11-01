#include <bits/stdc++.h>
using namespace std;

#define REP(i, a, b) for(int i = a; i < b; i++)

const int maxn = 100100;
const int inf = 1e9;
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

int n, m;

vector <string> v1, v2;

string input;

int main()
{
    cin >> n >> m;
    REP(i, 0, n)
    {
        cin >> input;
        v1.push_back(input);
    }
    REP(i, 0, m)
    {
        cin >> input;
        v2.push_back(input);
    }
    int q;
    cin >> q;
    int a;
    REP(i, 0, q)
    {
        cin >> a;
        a--;
        cout << v1[a % n] << v2[a % m] << endl;
    }
    return 0;
}