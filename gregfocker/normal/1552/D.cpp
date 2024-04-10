#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int U=(int) 1e9;
bool good;
int n, dif[11], sol[11], tp[11];

signed main()
{
        ios::sync_with_stdio(0); cin.tie(0);

        ///freopen ("input", "r", stdin);

        int t;
        cin>>t;
        while (t--)
        {

                cin>>n;
                set<int> s;
                for (int i=1; i<=n; i++)
                {
                        sol[i]=U;
                        int x;
                        cin>>x;
                        if (x==0)
                                continue;
                        s.insert(x);
                }
                int y=0;
                for (auto &x : s)
                        dif[y++]=x;
                if (y!=n)
                {
                        cout<<"YES\n";
                        continue;
                }
                int p=1;
                for (int i=1; i<=n; i++) p*=3;
                bool good=0;
                for (int m=0; m<p; m++)
                {
                        int cur=m;
                        for (int i=0; i<n; i++)
                        {
                                tp[i]=cur%3;
                                cur/=3;
                        }
                        int sum=0;
                        for (int i=0; i<n; i++)
                        {
                                if (tp[i]==1) sum+=dif[i];
                                if (tp[i]==2) sum-=dif[i];
                        }
                        for (int i=0; i<n; i++)
                        {
                                if (tp[i]==0&&sum==dif[i])
                                {
                                        good=1;
                                        break;
                                }
                        }
                }
                if (good)
                {
                        cout<<"YES\n";
                }
                else
                {
                        cout<<"NO\n";
                }
        }

        return 0;
}