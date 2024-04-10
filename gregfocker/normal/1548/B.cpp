#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll

const int N=(int) 2e5+7;
int n, a[N], t[4*N];

void build(int v, int tl, int tr)
{
        if (tl==tr)
        {
                t[v]=a[tl];
        }
        else
        {
                int tm=(tl+tr)/2;
                build(2*v, tl, tm);
                build(2*v+1, tm+1, tr);
                t[v]=__gcd(t[2*v], t[2*v+1]);
        }
}

int get(int v, int tl, int tr, int l, int r)
{
        if (tr<l || r<tl) return 0;
        if (l<=tl && tr<=r) return t[v];
        int tm=(tl+tr)/2;
        return __gcd(get(2*v, tl, tm, l, r), get(2*v+1, tm+1, tr, l, r));
}

signed main()
{
        ios::sync_with_stdio(0); cin.tie(0);

        int tt;
        cin>>tt;
        while (tt--)
        {
                cin>>n;
                for (int i=1; i<=n; i++)
                        cin>>a[i];
                if (n==1)
                {
                        cout<<"1\n";
                        continue;
                }
                n--;
                for (int i=1; i<=n; i++)
                        a[i]=abs(a[i+1]-a[i]);
                build(1, 1, n);
                int sol=0, l=1;
                for (int i=1; i<=n; i++)
                {
                        if (a[i]==1)
                        {
                                l=i+1;
                                continue;
                        }
                        assert(a[i]>1);
                        while (get(1, 1, n, l, i)==1)
                        {
                                l++;
                                if (l>i)
                                {
                                        l=i;
                                        break;
                                }
                        }
                        sol=max(sol, i-l+1);
                }
                sol++;

                cout<<sol<<"\n";
        }



        return 0;
}