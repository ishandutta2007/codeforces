#include<bits/stdc++.h>
#define next Next
using namespace std;
const int N=2e5+1;
int n;
int in[N],d[N];
vector<int>g[N],next[N];
bool dfs(int x,int fa){
    for (auto i:g[x])
        if (i!=fa)
            dfs(i,x);
    if (next[x].size()&1){
        if (!fa)return 0;
        next[x].push_back(fa);
    }else{
        if (fa)
            next[fa].push_back(x);
    }
    return 1;
}
int main(){
    ios::sync_with_stdio(false);
    cin>>n;
    for (int i=1;i<=n;i++){
        int x;
        cin>>x;
        if (x)g[i].push_back(x),g[x].push_back(i);
    }
    if (!dfs(1,0)){
        cout<<"NO";
        return 0;
    }
    for (int i=1;i<=n;i++)
        for (auto j:next[i])
            in[j]++;
    int l=0,r=0;
    for (int i=1;i<=n;i++)
        if (in[i]==0)d[++r]=i;
    while (l!=r){
        for (auto i:next[d[++l]])
            if (!(--in[i]))d[++r]=i;
    }
    cout<<"YES"<<endl;
    for (int i=1;i<=n;i++)
        cout<<d[i]<<endl;
    return 0;
}