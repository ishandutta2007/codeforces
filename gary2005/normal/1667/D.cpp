/**
 *    author:  gary
 *    created: 20.04.2022 15:31:26
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
const int MAXN=2e5+10;
bool noans=0;
int n,arc[MAXN],col[MAXN],col2[MAXN],cnt[MAXN][2],cnt2[MAXN][2],d[MAXN];
vector<int> tree[MAXN],g[MAXN];
void dfs1(int now,int pre){
    cnt[now][0]=cnt[now][1]=cnt2[now][0]=cnt2[now][1]=0;
    col2[now]=col[now]^(tree[now].size()&1);
    cnt[now][col[now]]++;
    cnt2[now][col2[now]]++;
    for(auto it:tree[now]) if(it!=pre){ 
    col[it]=col[now]^1,dfs1(it,now);
    cnt[now][0]+=cnt[it][0];
    cnt[now][1]+=cnt[it][1];
    cnt2[now][0]+=cnt2[it][0];
    cnt2[now][1]+=cnt2[it][1];
    if(abs(cnt[it][0]-cnt2[it][0])!=1) noans=1;
    else if(cnt[it][0]>cnt2[it][0]) g[now].PB(it),d[it]++;
    else g[it].PB(now),d[now]++;
    }
}
vector<int> tour;
void dfs(int now){
    while(arc[now]!=g[now].size()){
        int to=g[now][arc[now]++];
        dfs(to);
    }
    tour.PB(now);
}
void solve(){
    cin>>n;
    noans=0;
    rb(i,0,n) arc[i]=0,tree[i].clear(),g[i].clear(),d[i]=0;
    rb(i,1,n-1){
        int u,v;
        cin>>u>>v;
        tree[u].PB(v);
        tree[v].PB(u);
    }
    col[1]=0;
    dfs1(1,0);
    rb(i,1,n) {if(!col2[i]) g[0].PB(i),d[i]++;if(!col[i]) g[i].PB(0),d[0]++;}
    rb(i,0,n) noans|=g[i].size()!=d[i];
    if(noans){
        cout<<"NO\n";
        return;
    }
    cout<<"YES\n";
    rb(i,1,n){
        for(auto & it:g[i]) if(it==0){
            swap(g[i].back(),it);
            break;
        }
    }
    tour.clear();
    dfs(0);
    reverse(ALL(tour));
    for(int i=0;i+1<tour.size();){
        int j=i+1;
        while (tour[j]){
            j++;
        }
        stack<mp> tmp;
        rb(k,i+2,j-1){
            int u,v;
            u=tour[k-1],v=tour[k];
            if(!col2[u]&&!col2[v]){
                tmp.push(II(u,v));
            }
            else{
                cout<<u<<' '<<v<<endl;
                swap(col2[u],col2[v]);
                assert(col2[u]+col2[v]==1);
            }
        }
        while (!tmp.empty())
        {
            int u,v;
            tie(u,v)=tmp.top();
            tmp.pop();
            cout<<u<<' '<<v<<endl;
            swap(col2[u],col2[v]);
            assert(col2[u]+col2[v]==1);
        }        
        i=j;
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while (t--)
    {
        solve();
    }
    return 0;
}