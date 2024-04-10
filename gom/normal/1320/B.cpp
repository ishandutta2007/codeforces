#include <bits/stdc++.h>
#pragma GCC target("avx2")
#pragma GCC optimization("O3")
#pragma GCC optimization("unroll-loops")
#define x first
#define y second
using namespace std;
typedef long long ll;
typedef long double db;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<db,db> pdb;
typedef tuple<int,int,int> tii;
typedef tuple<ll,ll,ll> tll;
typedef tuple<int,int,int,ll> tup;
typedef vector<vector<ll>> mat;
const ll mod=998244353,inf=1e18;
const int N=2e5+5,M=55,K=1e5+5;
int n,m,k,d[N],a[N],cnt[N],ans1,ans2;
vector<int> g[N],g2[N];
queue<int> que;
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    cin>>n>>m;
    for(int u,v,i=1;i<=m;i++){
        cin>>u>>v;
        g[v].emplace_back(u);
        g2[u].emplace_back(v);
    }
    cin>>k;
    for(int i=1;i<=k;i++) cin>>a[i];
    fill(d+1,d+1+n,1e9); d[a[k]]=0;
    que.emplace(a[k]);
    while(que.size()){
        int u=que.front(); que.pop();
        for(auto v : g[u]){
            if(d[v]>d[u]+1){
                d[v]=d[u]+1; que.emplace(v);
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(auto j : g2[i]) if(d[i]==d[j]+1) cnt[i]++;
    }
    for(int i=1;i<k;i++){
        int u=a[i],v=a[i+1];
        if(d[u]!=d[v]+1){
            ans1++; ans2++; continue;
        }
        if(cnt[u]>=2) ans2++;
    }
    cout<<ans1<<" "<<ans2;
    return 0;
}