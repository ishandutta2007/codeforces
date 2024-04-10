/**
 *    author:  gary
 *    created: 06.10.2021 15:40:11
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
const int MAXN=202;
int n;
vector<int> v[MAXN];
bool vis2[MAXN];
bool have[MAXN];
int ext[MAXN];
bool vis[MAXN];
vector<int> cont[MAXN];
void g(int x){
    for(auto it:cont[x]){
        have[it]=1;
        ext[it]--;
    }
}
int rnk[MAXN];
vector<int> solve(int A,int B){
    memset(vis,0,sizeof(vis));
    vis[A]=vis[B]=1;
    g(A);
    g(B);
    rnk[A]=1;
    rnk[B]=2;
    vector<int> rest;
    rest.PB(A);
    rest.PB(B);
    rb(T,3,n){
        rb(i,1,n-1){
            if(ext[i]==1&&!vis2[i]&&have[i]){
                vis2[i]=1;
                for(auto it:v[i]) if(!vis[it]){
                    rest.PB(it);
                    rnk[it]=T;
                    vis[it]=1;
                    g(it);
                }
                else{
                    if(rnk[it]+v[i].size()-1<T) return vector<int> (0);
                }
                break;
            }
        }
    }
    if(rest.size()!=n) return vector<int>(0);
    return rest;
}
void solve(){
    scanf("%d",&n);
    rb(i,1,n) cont[i].clear();
    rb(i,1,n-1){
        int ki;
        scanf("%d",&ki);
        v[i].resize(ki);
        rep(j,ki) scanf("%d",&v[i][j]),cont[v[i][j]].PB(i);
    }
    rb(i,1,n-1) if(v[i].size()==2){
        rb(j,1,n-1) ext[j]=v[j].size(),have[j]=0;
        memset(vis2,0,sizeof(vis2));
        vis2[i]=1;
        vector<int> Tmp=solve(v[i][0],v[i][1]);
        if(Tmp.size()){
            for(auto it:Tmp) printf("%d ",it);
            puts("");
            return;
        }
        rb(j,1,n-1) ext[j]=v[j].size(),have[j]=0;
        memset(vis2,0,sizeof(vis2));
        vis2[i]=1;
        Tmp=solve(v[i][1],v[i][0]);
        if(Tmp.size()){
            for(auto it:Tmp) printf("%d ",it);
            puts("");
            return;
        }
    }
}
int main(){
    int t;
    scanf("%d",&t);
    while (t--)
    {
        solve();   
    }    
    return 0;
}