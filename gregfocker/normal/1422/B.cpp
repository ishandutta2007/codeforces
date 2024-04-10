#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N=100+7;
int tt;
int n,m;
int a[N][N];
int t[N*N];
vector<int> con[N*N];

int f(int r,int c)
{
        return (r-1)*m+c;
}

int root(int x)
{
        if (t[x]==x)
                return x;
        else
                return root(t[x]);
}

void unite(int x,int y)
{
        t[root(x)]=root(y);
}

int main()
{
        ios::sync_with_stdio(0);
        cin.tie(0);

        cin>>tt;
        while (tt--)
        {
                cin>>n>>m;
                for (int i=1;i<=n;i++)
                        for (int j=1;j<=m;j++)
                                cin>>a[i][j];
                for (int i=1;i<=n*m;i++)
                        t[i]=i,con[i].clear();
                for (int i=1;i<=n;i++)
                        for (int j=1;j<=m;j++)
                                unite(f(i,j),f(n+1-i,j)),unite(f(i,j),f(i,m+1-j));
                for (int i=1;i<=n;i++)
                        for (int j=1;j<=m;j++)
                        {
                                con[root(f(i,j))].push_back(a[i][j]);
                        }
                ll sol=0;
                for (int i=1;i<=n*m;i++)
                {
                        vector<int> x=con[i];
                        if (x.empty())
                                continue;
                        ll mn=(ll) 1e18;
                        for (auto &it : x)
                        {
                                ll cur=0;
                                for (auto &it2 : x)
                                        cur+=abs(it2-it);
                                mn=min(mn,cur);
                        }
                        sol+=mn;
                        con[i].clear();
                }
                cout<<sol<<"\n";
        }


}