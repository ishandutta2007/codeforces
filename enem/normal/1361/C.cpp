//https://codeforces.com/contest/1361/problem/C
#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define M1 1000000007
#define M2 998244353
#define ll long long
#define pll pair<ll,ll>
#define REP(i,a,b) for(ll i=a;i<b;i++)
#define REPI(i,a,b) for(ll i=b-1;i>=a;i--)
#define F first
#define S second
#define PB push_back
#define DB pop_back
#define MP make_pair
#define MT make_tuple
#define G(a,b) get<a>(b)
#define V(a) vector<a>

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    static int n,i,x,v,t,l,r,ans,a[1<<20];
    static bool bad;
    static set<int> ad[1<<20];
    static vector<int> vans,tmp,st,res;

    cin>>n;
    ans=0;
    for(i=0;i<(n<<1);i++)
    {
        cin>>a[i];
        vans.PB(i+1);
    }
    l=0;r=20;
    while(l<r)
    {
        x=((l+r)>>1)+1;

        for(i=0;i<(1<<x);i++)
        {
            ad[i].clear();
        }

        for(i=0;i<n;i++)
        {
            ad[a[(i<<1)]&((1<<x)-1)].insert((i<<1)|1);
            ad[a[(i<<1)|1]&((1<<x)-1)].insert((i<<1));
        }

        bad=false;
        for(i=0;i<(1<<x);i++)
        {
            if((ad[i].size())&1)
                bad=true;
        }

        st.clear();
        st.PB(0);
        res.clear();
        while(!st.empty())
        {
            v=(a[st.back()]&((1<<x)-1));
            if(ad[v].empty())
            {
                res.push_back(st.back());
                st.DB();
            }
            else
            {
                t=(*ad[v].begin());
                ad[v].erase(ad[v].begin());
                v=(a[t]&((1<<x)-1));
                ad[v].erase(ad[v].find(t^1));
                st.PB(t);
            }
        }

        for(i=0;i<(1<<x);i++)
        {
            if((ad[i].size()))
                bad=true;
        }

        if(bad)
        {
            r=x-1;
        }
        else
        {
            l=x;
            ans=x;
            vans.clear();
            res.DB();
            for(i=0;i<n;i++)
            {
                vans.PB(res[i]+1);
                vans.PB((res[i]^1)+1);
            }
        }
    }
    cout<<ans<<'\n';
    for(i=0;i<(n<<1);i++)
        cout<<vans[i]<<' ';

    return 0;
}