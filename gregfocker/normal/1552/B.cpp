#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N=50000+7;
int n, a[N][5];

bool sup(int i, int j)
{
        int cnt=0;
        for (int x=0; x<5; x++)
        {
                cnt+=(a[i][x]<a[j][x]);
        }
        return cnt>=3;
}

signed main()
{
        ios::sync_with_stdio(0); cin.tie(0);

        ///freopen ("input", "r", stdin);

        int t;
        cin>>t;
        while (t--)
        {
                cin>>n;
                int sol=-1;
                for (int i=1; i<=n; i++)
                {
                        for (int j=0; j<5; j++)
                                cin>>a[i][j];
                        if (i==1)
                                sol=i;
                        else
                        {
                                if (sup(i, sol))
                                        sol=i;
                        }
                }
                bool good=1;
                for (int i=1; i<=n; i++)
                {
                        if (i!=sol)
                                good&=(sup(sol, i));
                }
                if (!good)
                {
                        cout<<"-1\n";
                        continue;
                }
                cout<<sol<<"\n";
        }

        return 0;
}