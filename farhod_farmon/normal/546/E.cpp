#include <bits/stdc++.h>

const int N=444;

using namespace std;

int n,m,G,d[N],p[N],a[N];
vector<int>v,c,f,e[N];

void add(int x,int y,int cost)
{
        e[x].push_back(G);v.push_back(y);f.push_back(0);c.push_back(cost);G++;
        e[y].push_back(G);v.push_back(x);f.push_back(0);c.push_back(0);G++;
}

int main()
{
        //freopen("input.txt","r",stdin);
        //freopen("output.txt","w",stdout);

        int s=0;
        cin>>n>>m;
        for(int i=1;i<=n;i++){
                int x;
                cin>>x;
                s+=x;
                add(n+n+1,i,x);
        }
        int ans=0;
        for(int i=1;i<=n;i++){
                int x;
                cin>>x;
                s-=x;
                ans+=x;
                add(n+i,n+n+2,x);
        }
        if(s){
                cout<<"NO\n";
                return 0;
        }
        for(int i=1;i<=m;i++){
                int x,y;
                cin>>x>>y;
                add(x,n+y,1e8);
                add(y,n+x,1e8);
        }
        for(int i=1;i<=n;i++)add(i,n+i,1e8);
        while(true){
                queue <int>q;
                q.push(n+n+1);
                for(int i=1;i<=n+n+2;i++)d[i]=1e9,p[i]=-1;
                d[n+n+1]=0;
                while(!q.empty()){
                        int x=q.front();
                        q.pop();
                        for(int g:e[x]){
                                if(c[g]-f[g]>0&&d[v[g]]==1e9){
                                        d[v[g]]=d[x]+1;
                                        p[v[g]]=g;
                                        q.push(v[g]);
                                }
                        }
                }
                int t=n+n+2,mn=1e9;
                if(d[t]==1e9)break;
                while(true){
                        if(p[t]==-1)break;
                        mn=min(mn,c[p[t]]-f[p[t]]);
                        t=v[p[t]^1];
                }
                ans-=mn;
                t=n+n+2;
                while(true){
                        if(p[t]==-1)break;
                        f[p[t]]+=mn;
                        f[p[t]^1]-=mn;
                        t=v[p[t]^1];
                }
        }
        if(ans){
                cout<<"NO\n";
                return 0;
        }
        cout<<"YES\n";
        for(int i=1;i<=n;i++){
                for(int j=1;j<=n;j++)a[j]=0;
                for(int g:e[i])a[v[g]-n]=f[g];
                for(int j=1;j<=n;j++)cout<<a[j]<<" \n"[j==n];
        }
}