#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define pll pair<LL,LL>
#define x first
#define y second
#define pi acos(-1)
#define sqr(x) ((x)*(x))
#define pdd pair<double,double>
#define MEMS(x) memset(x,-1,sizeof(x))
#define MEM(x) memset(x,0,sizeof(x))
#define MXN 10005
#define less Less
#define N (1<<20)
typedef complex<double> C;

vector<pii> v[1005];
pair<pii,int> p[1005];
int dfs(int x,int f){
    if(v[x].size()==1){
        return x;
    }
    for(auto it:v[x]){
        if(it.x!=f){
            return dfs(it.x,x);
        }
    }
}
int degree[1005];
bool cmp(const pair<pii,int> &p,const pair<pii,int> &q){
    return min(degree[p.x.x],degree[p.x.y])>min(degree[q.x.x],degree[q.x.y]);
}
int main(){
    int n;
    scanf("%d",&n);
    for(int i = 1;i<n;i++){
        int x,y,val;
        scanf("%d %d %d",&x,&y,&val);
        p[i]=mp(mp(x,y),val);
        degree[x]++;
        degree[y]++;
        v[x].pb(mp(y,i));
        v[y].pb(mp(x,i));
    }
   // sort(p+1,p+n,cmp);
   // for(int i = 1;i<n;i++){
   //     v[p[i].x.x].pb(mp(p[i].x.y,i));
    //    v[p[i].x.y].pb(mp(p[i].x.x,i));
   // }
    for(int i = 1;i<=n;i++){
        if(v[i].size()==2){
            printf("NO\n");
            return 0;
        }
    }
    vector<pair<pii,int> > ans;
    for(int i = 1;i<n;i++){
     //   printf("%d %d %d\n",p[i].x.x,p[i].x.y,p[i].y);
        vector<int> left,right;
        if(v[p[i].x.y].size()==1){
            left.pb(p[i].x.y);
            left.pb(p[i].x.y);
        }
        else{
            if(v[p[i].x.y][0].x!=p[i].x.x)
            left.pb(dfs(v[p[i].x.y][0].x,p[i].x.y));
            else
            left.pb(dfs(v[p[i].x.y].back().x,p[i].x.y));
            if(v[p[i].x.y][1].x!=p[i].x.x)
            left.pb(dfs(v[p[i].x.y][1].x,p[i].x.y));
            else
            left.pb(dfs(v[p[i].x.y].back().x,p[i].x.y));
            //printf("%d %d %d\n",p[i].x.y,v[p[i].x.y][0].x,v[p[i].x.y][1].x);
        }
        if(v[p[i].x.x].size()==1){
            right.pb(p[i].x.x);
            right.pb(p[i].x.x);
        }
        else{
            if(v[p[i].x.x][0].x!=p[i].x.y)
            right.pb(dfs(v[p[i].x.x][0].x,p[i].x.x));
            else
            right.pb(dfs(v[p[i].x.x].back().x,p[i].x.x));
            if(v[p[i].x.x][1].x!=p[i].x.y)
            right.pb(dfs(v[p[i].x.x][1].x,p[i].x.x));
            else
            right.pb(dfs(v[p[i].x.x].back().x,p[i].x.x));
            // printf("%d %d\n",v[p[i].x.x][0].x,v[p[i].x.x][1].x);
        }
        ans.pb(mp(mp(left[0],right[0]),p[i].y/2));
        ans.pb(mp(mp(left[1],right[1]),p[i].y/2));
        if(left[0]!=left[1]){
            ans.pb(mp(mp(left[0],left[1]),-p[i].y/2));
        }
        if(right[0]!=right[1]){
            ans.pb(mp(mp(right[0],right[1]),-p[i].y/2));
        }
    }
    printf("YES\n");
    printf("%d\n",ans.size());
    for(auto it:ans)
    printf("%d %d %d\n",it.x.x,it.x.y,it.y);
}
/*
int main(){
    int n,p,k;
    scanf("%d %d %d",&n,&p,&k);
    for(int i = 0;i<p;i++){
        for(int j = 0;j<p;j++){
            printf("%d %d %d\n",i,j,(i*i+j*j)*(i+j)%p);
        }
    }
}*/
/*
1 
2 6 
3 5 
4
*/