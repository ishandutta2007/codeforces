#include <bits/stdc++.h>

using namespace std;

int main()
{
        ios::sync_with_stdio(0);
        cin.tie(0);

        int t;
        cin >> t;
        while (t--)
        {
                int n,m;
                bool ok=0;
                cin>>n>>m;
                for (int i=1;i<=n;i++)
                {
                        int a,b,c,d;
                        cin>>a>>b>>c>>d;
                        if (b==c)
                                ok=1;
                }
                if (m%2==0 && ok)
                        cout<<"YES\n";
                else
                        cout<<"NO\n";
        }

}