/**
 *    author:  gary
 *    created: 27.05.2022 20:14:44
**/
#include<bits/stdc++.h>
#define rb(a,b,c) for(int a=b;a<=c;++a)
#define rl(a,b,c) for(int a=b;a>=c;--a)
#define rep(a,b) for(int a=0;a<b;++a)
#define LL long long
#define PB push_back
#define POB pop_back
#define II(a,b) make_pair(a,b)
#define FIR first
#define SEC second
#define SRAND mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define random(a) rng()%a
#define ALL(a) a.begin(),a.end()
#define check_min(a,b) a=min(a,b)
#define check_max(a,b) a=max(a,b)
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
const int MAXN=202+20;
int n,p[MAXN],fa[MAXN],ans,q[MAXN],siz[MAXN],in[MAXN],out[MAXN];
bool used[MAXN];
int root(int x){return fa[x]=(fa[x]==x? x:root(fa[x]));}
void merge(int u,int v){fa[root(u)]=root(v);}
bool cmp(pair<mp,int> A,pair<mp,int> B){return A.second<B.second;}
int MST(vector<pair<mp,int> > E){
    int tmp=0;
    rb(i,1,n) fa[i]=i;
    sort(ALL(E),cmp);
    for(auto it2:E){
        auto it=it2.first;
        if(root(it.first)!=root(it.second)){
            tmp+=it2.second;
            merge(it.first,it.second);
        }
    }
    return tmp;
}
bool check(int now){
    if(now==n||now==1) return true;
    // if(p[q[1]]==q[now]) return false;
    int tmp=0;
    rb(i,1,n) fa[i]=i;
    rb(i,1,now-1) tmp+=abs(q[i]-p[q[i+1]]);
    // cout<<tmp<<endl;
    vector<mp> Edge;
    Edge.PB(II(p[q[1]],q[now]));
    rb(i,1,n) if(!used[i]) Edge.PB(II(p[i],i));
    memset(in,0,sizeof(in));
    memset(out,0,sizeof(out));
    for(auto it:Edge) in[it.second]++,out[it.first]++;
    vector<int> vv[2];
    // for(auto it:Edge){
        // cout<<it.first<<" "<<it.second<<endl;
    // }
        // return 1;
    rb(i,1,n) if(in[i]^out[i]) vv[in[i]].PB(i);
    assert(vv[0].size()==vv[1].size());
    rep(i,vv[0].size()) {Edge.PB(II(vv[0][i],vv[1][i])),tmp+=abs(vv[0][i]-vv[1][i]);rb(j,min(vv[0][i],vv[1][i]),max(vv[0][i],vv[1][i])-1) merge(j,j+1);}
    for(auto it:Edge) merge(it.first,it.second);
    rb(i,1,n) siz[i]=0;
    for(auto it:Edge) siz[root(it.first)]++;
    vector<pair<mp,int> > E;
    rb(i,1,n) if(siz[root(i)]){
        int j=i-1;
        while (j>=1&&!siz[root(j)]){
            j--;
        }
        if(j){
            E.PB(II(II(root(i),root(j)),2*(i-j)));
        }
        j=i+1;
        while (j<=n&&!siz[root(j)]){
            j++;
        }
        if(j<=n){
            E.PB(II(II(root(i),root(j)),2*(j-i)));
        }
    }
    tmp+=MST(E);
    // cout<<tmp<<' '<<ans<<endl;
    return tmp==ans;
}
void solve(){
    memset(used,0,sizeof(used));
    memset(q,0,sizeof(q));
    ans=0;
    cin>>n;
    rb(i,1,n) fa[i]=i;
    rb(i,1,n) cin>>p[i],fa[root(i)]=root(p[i]);
    rb(i,1,n) ans+=root(i)==i;
    ans=(ans-1)*2;
    // q[1]=1;q[2]=2;
    // used[1]=1,used[2]=1;
    // check(2);
    // return ;
    rb(i,1,n){
        rb(j,1,n){
            if(!used[j]){
                q[i]=j;
                used[j]=1;
                if(check(i)){
                    break;
                }
                used[j]=0;
            }
        }
    }
    rb(i,1,n) cout<<q[i]<<' ';
    cout<<endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while (t--){
        solve();
    }
    
    return 0;
}