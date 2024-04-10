#include<bits/stdc++.h>
#define pb push_back
#define x first
#define y second
#define pdd pair<double,double>
#define pii pair<int,int>
#define pll pair<LL,LL>
#define mp make_pair
#define LL long long
#define ULL unsigned long long
#define sqr(x) ((x)*(x))
#define pi acos(-1)
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
const int mod=998244353;
vector<vector<int> > V[200005];
int Index[200005];
map<int,vector<pii> > edge;
vector<vector<char> > res;
void dfs(int x){
    while(Index[x]!=V[x].size()){
        auto p=V[x][Index[x]];
        Index[x]++;
        if(res[p[1]][p[2]]!=0)continue;
        res[p[1]][p[2]]='R';
        res[x][p[0]]='L';
        dfs(p[1]);
    }
}
void solve(){
    map<int,int> cnt;
    vector<vector<int> > v;
    int n;
    scanf("%d",&n);
    for(int i  = 0;i<n;i++){
        vector<int> tmp;
        int x;
        scanf("%d",&x);
        for(int j = 0;j<x;j++){
            int a;
            scanf("%d",&a);
            tmp.pb(a);
            cnt[a]++;
        }
        v.pb(tmp);
    }
    for(auto it:cnt){
        if(it.y&1){
            printf("NO\n");
            return;
        }
    }
    printf("YES\n");
    map<int,char> vis;

    int idx=0;
    for(auto it:v){
        vector<char> ans(it.size(),0);
        map<int,vector<int>> tmp;
        for(int j = 0;j<it.size();j++){
            tmp[it[j]].pb(j);
        }
        int l=0,r=0;
        for(auto &it:tmp){
            while(it.y.size()>=2){
                int a=it.y.back();
                it.y.pop_back();
                int b=it.y.back();
                it.y.pop_back();
                ans[a]='L';
                ans[b]='R';
            }
            if(it.y.size()){
              //  printf("!%d\n",it.y.back());
              edge[it.x].pb(mp(idx,it.y.back()));
              /*
                if(vis.find(it.x)!=vis.end()){
                    char c=vis[it.x];
                    if(c=='L')r++,ans[it.y.back()]='R';
                    else l++,ans[it.y.back()]='L';
                    it.y.pop_back();
                    vis.erase(it.x);
                }*/
            }
        }
        res.pb(ans);
        idx++;
    }
    for(auto it:edge){
        for(int j = 0;j<it.y.size();j+=2){
            V[it.y[j].x].pb({it.y[j].y,it.y[j+1].x,it.y[j+1].y});
            V[it.y[j+1].x].pb({it.y[j+1].y,it.y[j].x,it.y[j].y});
        }
    }
    for(int i = 0;i<n;i++){
        while(Index[i]!=V[i].size()){
            dfs(i);
        }
    }
    for(auto it:res){
        for(auto it2:it)printf("%c",it2);
        printf("\n");
    }
} 
/*
LLRLLR
012345
LRLL
*/
int main(){
   /* for(int i = 2;i<=1000000;i++){
        if(v[i].empty())
        for(int j = i;j<=1000000;j+=i )v[j].pb(i);
    }*/
    int t=1;
  //  scanf("%d",&t);
    while(t--){
        solve();
    }
    return 0;
}
/*
(k_1x+b)k_2+b=y
3 1 2 4 5

36
0123
0123 4567

RRRRR
6 4 4 4
5 3 4 4
4 3 3 4
4 2 4 4
3 2 3 4
4 4 2 4


*/