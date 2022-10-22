#include <bits/stdc++.h>

using namespace std;

const int N=(int) 2e5+7;
int n, m, sol;
set<int> g[N];

void ad(int i)
{
        auto it=g[i].end();
        it--;
        sol+=(i>*it);
}

void dl(int i)
{
        auto it=g[i].end();
        it--;
        sol-=(i>*it);
}

void add(int a, int b)
{
        dl(a), dl(b);
        g[a].insert(b);
        g[b].insert(a);
        ad(a), ad(b);
}

void del(int a, int b)
{
        dl(a), dl(b);
        g[a].erase(b);
        g[b].erase(a);
        ad(a), ad(b);
}

int deg[N];
bool good[N];

int main()
{
        ios::sync_with_stdio(0); cin.tie(0);


        cin>>n>>m;
        sol=n;
        for (int i=1; i<=n; i++)
        {
                g[i].insert(0);
        }
        for (int i=1; i<=m; i++)
        {
                int a, b;
                cin>>a>>b;
                add(a, b);
        }

        int q;
        cin>>q;
        while (q--)
        {
                int t;
                cin>>t;
                if (t==1)
                {
                        int a, b;
                        cin>>a>>b;
                        add(a, b);
                }
                if (t==2)
                {
                        int a, b;
                        cin>>a>>b;
                        del(a, b);
                }
                if (t==3)
                {
                        cout<<sol<<"\n";
                }

        }

        return 0;
}