#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define pll pair<ll,ll>
#define fr front()
#define sqr(a) ((a)*(a))
#define y1 Enkognit

using namespace std;

const ll MOD=1000000007;

ll n, m, i, j, k, l, r;

ll f(ll h)
{
    ll l=0, z=1, p=0, a=0, b=0;

    while (l<h)
    {
        if (l+z>h) z=h-l;

        l+=z;
        if (p%2) b+=z; else a+=z;
        p++;
        z*=2;
    }
    a%=MOD;
    b%=MOD;
    return (a*a+b*(b+1))%MOD;
}

int main()
{
    //freopen("tree.in","r",stdin);
    //freopen("tree.out","w",stdout);
    cin >> n >> m;
    ll ans=(f(m)-f(n-1))%MOD;
    if (ans<0) ans+=MOD;
    cout << ans;
    return 0;
}
/*
12
src/java/Gen.java
src/cpp/main.cpp
src/java/Main.java
src/cpp/test.cpp
src/cpp/bin/main
src/python/generate.py
src/test.in
src/test.out
tests/01
tests/01.a
tests/02
tests/02.a
*/