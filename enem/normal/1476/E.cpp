#include <bits/stdc++.h>
using namespace std;

void dfs(int x, vector<int> ad[], int color[],bool &bad,vector<int> &dfs_order)
{
    if(color[x]==1) bad=true;
    if(color[x]==1 || color[x]==2) return;
    color[x]=1;

    for(auto it:ad[x])
    {
        if(it!=x) dfs(it,ad,color,bad,dfs_order);
    }

    dfs_order.push_back(x);
    color[x]=2;

    return;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n,m,k;
    cin>>n>>m>>k;

    int nv=1;
    for(int i=0; i<k; i++) nv*=27;

    int mp[nv];
    for(int i=0; i<nv; i++) mp[i]=-1;

    vector<int> ad[n];

    string a[n];
    for(int i=0; i<n; i++)
    {
        cin>>a[i];
        int x=0;
        for(int j=0; j<k; j++)
        {
            x*=27;
            if(a[i][j]!='_') x+=(a[i][j]-'a'+1);
        }
        mp[x]=i;
    }
    bool bad=false;
    for(int i=0; i<m; i++)
    {
        string b;
        int c;
        cin>>b>>c;
        c--;
        for(int j=0; j<k; j++)
        {
            if(!(a[c][j]=='_'||a[c][j]==b[j])) bad=true;
        }
        for(int t=0; t<(1<<k); t++)
        {
            int x=0;
            for(int j=0; j<k; j++)
            {
                x*=27;
                if(((1<<j)&t)!=0) x+=(b[j]-'a'+1);
            }
            if(mp[x]!=-1)
            {
                ad[c].push_back(mp[x]);
            }
        }
    }

    vector<int> dfs_order;
    int color[n];
    for(int i=0; i<n; i++)
    {
        color[i]=0;
    }
    for(int i=0; i<n; i++)
    {
        if(color[i]==0) dfs(i,ad,color,bad,dfs_order);
    }

    reverse(dfs_order.begin(), dfs_order.end());

    if(bad) cout<<"NO";
    else
    {
        cout<<"YES\n";
        for(auto it:dfs_order) cout<<it+1<<' ';
    }

    return 0;
}