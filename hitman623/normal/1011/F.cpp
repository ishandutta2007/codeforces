#include <bits/stdc++.h>

#define ll          long long
#define pb          push_back
#define pii         pair<int,int>
#define vi          vector<int>
#define vii         vector<pii>
#define mi          map<int,int>
#define mii         map<pii,int>
#define all(a)      (a).begin(),(a).end()
#define x           first
#define y           second
#define sz(x)       (int)x.size()
#define endl        '\n'
#define hell        1000000007
#define rep(i,a,b)  for(int i=a;i<b;i++)
using namespace std;
int n,val[1000006],g,ans[1000006];
string s[1000006],res;
vi a[1000006],v;
void dfs1(int node){
    for(auto i:a[node]){
        dfs1(i);
    }
    if(s[node]=="NOT"){
        val[node]=!val[a[node][0]];
    }
    else if(s[node]=="AND"){
        val[node]=val[a[node][0]]&val[a[node][1]];
    }
    else if(s[node]=="OR"){
        val[node]=val[a[node][0]]|val[a[node][1]];
    }
    else if(s[node]=="XOR"){
        val[node]=val[a[node][0]]^val[a[node][1]];
    }
}
void dfs(int node,int f){
    if(f==2){
        for(auto i:a[node]){
            dfs(i,2);
        }
        if(sz(a[node])==0) ans[node]=g;
        return;
    }
    if(s[node]=="NOT"){
        dfs(a[node][0],!f);
    }
    else if(s[node]=="AND"){
        if(f==0){
            if(val[a[node][0]]==0){
                dfs(a[node][1],2);
            }
            else dfs(a[node][1],0);
            if(val[a[node][1]]==0){
                dfs(a[node][0],2);
            }
            else dfs(a[node][0],0);
        }
        else{
            if(val[a[node][0]]==1){
                dfs(a[node][1],1);
            }
            if(val[a[node][1]]==1){
                dfs(a[node][0],1);
            }            
        }
    }
    else if(s[node]=="OR"){
        if(f==1){
            if(val[a[node][0]]==1){
                dfs(a[node][1],2);
            }
            else dfs(a[node][1],1);
            if(val[a[node][1]]==1){
                dfs(a[node][0],2);
            }
            else dfs(a[node][0],1);
        }
        else{
            if(val[a[node][0]]==0){
                dfs(a[node][1],0);
            }
            if(val[a[node][1]]==0){
                dfs(a[node][0],0);
            }
        }
    }
    else if(s[node]=="XOR"){
        dfs(a[node][1],!(val[a[node][0]]==f));
        dfs(a[node][0],!(val[a[node][1]]==f));
    }
    else{
        if(val[node]==!f) ans[node]=g;
    }
}
void solve(){
    cin>>n;
    rep(i,1,n+1){
        cin>>s[i];
        if(s[i]=="NOT"){
            int x;
            cin>>x;
            a[i].pb(x);
        }
        else if(s[i]=="IN"){
            cin>>val[i];
            v.pb(i);
        }
        else{
            int x,y;
            cin>>x>>y;
            a[i].pb(x);
            a[i].pb(y);
        }
    }
    dfs1(1);
    g=0;
    dfs(1,0);
    g=1;
    dfs(1,1);
    for(auto i:v){
        res+=ans[i]+'0';
    }
    cout<<res<<endl;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    // cin>>t;
    while(t--){
        solve();
    }
    return 0;
}