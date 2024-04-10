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

ll n, m, W, l, r, ans, k, a[100003], b[10001];
map<ll,bool> t;

int main()
{
    //freopen("divisors.in","r",stdin);
    //freopen("divisors.out","w",stdout);
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);cout.tie(0);
    cout << "? 1 3\n";
    cin >> a[1];
    fflush(stdout);
    cout << "? 1 4\n";
    cin >> a[2];
    fflush(stdout);
    cout << "? 2 5\n";
    cin >> a[3];
    fflush(stdout);
    cout << "? 2 6\n";
    cin >> a[4];
    fflush(stdout);
    vector <ll> v;
    v.pb(4);
    v.pb(8);
    v.pb(15);
    v.pb(16);
    v.pb(23);
    v.pb(42);
    for (int i = 0; i < v.size(); i++)t[v[i]]=1;
    for (int j = 0; j < v.size(); j++)
    {
        ll i=v[j];
        if (a[1]%i==0 && a[2]%i==0 && t[a[1]/i] && t[a[2]/i] & a[1]/i!=i && a[2]/i!=i)
        {
            b[1]=i;
            b[3]=a[1]/i;
            b[4]=a[2]/i;
        }
    }
    for (int j = 0; j < v.size(); j++)
    {
        ll i=v[j];
        if (a[3]%i==0 && a[4]%i==0 && t[a[3]/i] && t[a[4]/i] && a[4]/i!=i && a[3]/i!=i)
        {
            b[2]=i;
            b[5]=a[3]/i;
            b[6]=a[4]/i;
        }
    }
    cout << "!";
    for (int i = 1; i <= 6; i++ ) cout << " " << b[i];
    cout << "\n";
    return 0;
}
/*
5
2 3 4 5 6
6
1 2 4
1 2 3
0 1 1
0 4 7
1 1 3
1 1 4
bokutachi wa benkyou ga dekinai
*/