#include <bits/stdc++.h>
#define ll long long
#define fr front()
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define pu push
#define pll pair<ll,ll>


using namespace std;

ll n, m, k;
pll a[1001],b[1001];
map<pll,ll> t;

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin >> n;
    set <ll> s;
    for (int i = 1; i * i <= n; i++)
        if (n%i==0)
        {
           ll j=n/i,y=n-i+2;
           s.insert(y*j/2);
           s.insert((n-j+2)*i/2);
        }
    while (s.size()) {cout << *s.begin() << " ";s.erase(s.begin());}
    return 0;
}
/*set<ll> s;
    cin >> n;
    ll r=n/2;
    ll l=0;
    ll j=1;
    do
    {
       j+=r;
       if (j>n)j-=n;
       l+=j;
    }while(j!=1);
    ll u=1,y=n,w=0;
    while (y)
    {
        w++;
        y/=2;
    }
    s.insert(l);
    s.insert(1);
    ll o=n*(n+1)/2;
    ll p=0;
    while (p<w) {s.insert(o);o=(o-r)/2;p++;}
    while (s.size()){cout << *s.begin() << " ";s.erase(s.begin());} */