#include <bits/stdc++.h>

#define fi first
#define se second

const int N=500500;

using namespace std;

int n,m,k;
bool used[N];
int p[N],tin[N],tout[N],tim,dip[N];
vector<int>v[N];

void dfs(int x)
{
    used[x]=1;
    tin[x]=++tim;
    for(int y:v[x]){
        if(used[y])continue;
        p[y]=x;
        dip[y]=dip[x]+1;
        dfs(y);
    }
    tout[x]=tim;
}

vector<int> path(int x,int y)
{
    vector<int>A,B;
    while(!(tin[x]<=tin[y]&&tout[x]>=tout[y])){
        A.push_back(x);
        x=p[x];
    }
    A.push_back(x);
    while(x!=y){
        B.push_back(y);
        y=p[y];
    }
    reverse(B.begin(),B.end());
    for(int x:B)A.push_back(x);
    return A;
}

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);

    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        int x,y;
        cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    dfs(1);
    for(int i=1;i<=n;i++){
        if(dip[i]+1>=(n-1)/k+1){
            cout<<"PATH\n";
            cout<<dip[i]+1<<"\n";
            while(i!=1){
                cout<<i<<" ";
                i=p[i];
            }
            cout<<1<<"\n";
            return 0;
        }
    }
    vector<vector<int>>res;
    for(int i=2;i<=n;i++){
        if(tin[i]!=tout[i])continue;
        pair<int,int>f={-1,-1};
        for(int j:v[i]){
            if(j==p[i])continue;
            if(f.fi==-1)f.fi=j;
            else f.se=j;
        }
        vector<int>A=path(i,f.fi);
        vector<int>B=path(i,f.se);
        vector<int>C=path(f.fi,f.se);
        reverse(C.begin(),C.end());
        C.push_back(i);
        reverse(C.begin(),C.end());
        if(A.size()%3)res.push_back(A);
        else if(B.size()%3)res.push_back(B);
        else if(C.size()%3)res.push_back(C);
    }
    if(res.size()<k){
        cout<<-1<<"\n";
        return 0;
    }
    cout<<"CYCLES\n";
    for(int i=0;i<k;i++){
        cout<<res[i].size()<<"\n";
        for(int x:res[i]){
            cout<<x<<" ";
        }
        cout<<"\n";
    }
}