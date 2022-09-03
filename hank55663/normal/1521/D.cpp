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
#define pi acosl(-1)
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
vector<vector<int> > ans;
vector<pii> rm;
vector<pii> head;
vector<int> v[100005];
int dfs(int x,int f){
    vector<int> end;
    for(auto it:v[x]){
        if(it!=f){
            int a=dfs(it,x);
            if(a==0)continue;
            if(end.size()<2)end.pb(a);
            else{
                ans.pb({x,it,it,end[0]});
                end[0]=a;
            }
        }
    }
    if(end.size()==2){
        rm.pb(mp(x,f));
        head.pb(mp(end[0],end[1]));
        return 0;
    }
    if(end.size()==1)return end[0];
    else
    return x;
}
void solve(){
    int n;
    scanf("%d",&n);
    for(int i = 1;i<=n;i++)v[i].clear();
    for(int i = 1;i<n;i++){
        int x,y;
        scanf("%d %d",&x,&y);
        v[x].pb(y);
        v[y].pb(x);
    }
    ans.clear();
    head.clear();
    rm.clear();
    for(int i = 1;i<=n;i++){
        if(v[i].size()==1){
            int a=dfs(i,0);
            head.pb(mp(i,a));
            break;
        }
    }
    printf("%d\n",ans.size()+rm.size());
    for(auto it:ans){
        printf("%d %d %d %d\n",it[0],it[1],it[2],it[3]);
    }
   // printf("\n\n");
    for(int i = 0;i<rm.size();i++){
        printf("%d %d %d %d\n",rm[i].x,rm[i].y,head[i].y,head[i+1].x);
    }
}
int main(){
    int t=1;
    scanf("%d",&t);
    while(t--){
        solve();
    }
    //printf("8192\n");
    //printf("%d\n",cnt);
    //printf("%.12f\n",sum/tt);
    return 0;
}
/*
3 1 4 2
3 3 4 4
*/