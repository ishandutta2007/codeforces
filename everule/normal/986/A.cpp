#include <iostream>
#include<algorithm>
#include<bits/stdc++.h>
using namespace std;
#define FIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define mod 1000000007
#define test ll t; t=1; while(t--)
typedef long long int ll;
vector<ll>adj[100001];
vector<ll>col[100];
vector<ll>p[100001];
void solve(ll s,ll n){
    bool vis[n];
    memset(vis,false,n);
    queue<ll>q;
    ll level[n];
    ll i,j,t;
    for(i=0;i<col[s].size();i++){
        level[col[s][i]]=0;
        q.push(col[s][i]);
        vis[col[s][i]]=true;
    }
    while(!q.empty()){
        t=q.front();
        q.pop();
        for(i=0;i<adj[t].size();i++){
            if(!vis[adj[t][i]]){
                vis[adj[t][i]]=true;
                q.push(adj[t][i]);
                level[adj[t][i]]=level[t]+1;
            }
        }
    }
    for(i=0;i<n;i++){
        p[i].push_back(level[i]);
    }
}
int main() {
    FIO;
    test{
        ll n,m,k,s,i,l,r,j;
        cin>>n>>m>>k>>s;
        ll a[n];
        for(i=0;i<n;i++){
            cin>>a[i];
            a[i]--;
            col[a[i]].push_back(i);
        }
        for(i=0;i<m;i++){
            cin>>l>>r;
            l--; r--;
            adj[l].push_back(r);
            adj[r].push_back(l);
        }
        for(i=0;i<k;i++){
            solve(i,n);
        }
        for(i=0;i<n;i++){
            sort(p[i].begin(),p[i].end());
            ll ans=0;
            for(j=0;j<s;j++){
                ans+=p[i][j];
            }
            cout<<ans<<" ";
        }
        cout<<endl;
    }
	return 0;
}