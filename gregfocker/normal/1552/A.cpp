#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;


signed main()
{
        ios::sync_with_stdio(0); cin.tie(0);

        ///freopen ("input", "r", stdin);

        int t;
        cin>>t;
        while (t--)
        {
                int n;cin>>n;
                string a, b;
                cin>>a;
                b=a;
                sort(b.begin(), b.end());
                int sol=0;
                for (int i=0; i<(int) a.size();i++)
                        sol+=(a[i]!=b[i]);
                cout<<sol<<"\n";
        }

        return 0;
}