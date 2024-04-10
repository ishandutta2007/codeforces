#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define pll pair<ll,ll>
#define pii pair<int,int>

using namespace std;

ll n, m, i, j, k, b, l=1e18, r;
map<ll,bool> t;
vector <ll> v;

int main()
{
    cin >> n >> b;
    ll o=sqrt(b);
    for (int i = 2; i <= min(o,b); i++)
        if (b%i==0 && !t[i])
        {
            for (int j = i*i; j <= o; j+=i) t[j]=1;
            ll k=0;
            while (b%i==0 && b>0) k++, b/=i;
            ll p=i, an=0;
            while (p<=n)
            {
                an+=n/p;
                if (n/p<i) break;
                p*=i;
            }
            //cout << an << "\n";
            //cout << i;
            l=min(l,an/k);
        }
    if (b>1)
    {
       ll p=b, an=0;
       while (p<=n)
       {
           an+=n/p;
           if (n/p<b)break;
           p*=b;
       }
       l=min(l,an);
    }
    cout << l;
    return 0;
}