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
vector<pii> v[105];
pair<pii,double> edge[105];
void dfs(int x,int f,double d){
    double ti=2.0/(v[x].size());
    double now=fmod(d+ti,2);
    for(auto it:v[x]){
        if(it.x!=f){
            dfs(it.x,x,fmod(now+1,2));
            if(edge[it.y].x.x!=x)
            swap(edge[it.y].x.x,edge[it.y].x.y);
            edge[it.y].y=now;
            now = fmod(now+ti,2);
        }
    }
}
int main(){
    int n;
    scanf("%d",&n);
    for(int i = 1;i<n;i++){
        int x,y;
        scanf("%d %d",&x,&y);
        v[x].pb(mp(y,i));
        v[y].pb(mp(x,i));
        edge[i]=mp(mp(x,y),0);
    }
    for(int i = 1;i<n;i++){
        if(v[i].size()==1){
            dfs(i,0,0);
            break;
        }
    }
    printf("%d\n",n-1);
    for(int i = 1;i<n;i++){
        if(edge[i].y>=1){
            printf("1 %d %d %d %.12lf\n",i,edge[i].x.x,edge[i].x.y,2-edge[i].y);
        }
        else{
            printf("1 %d %d %d %.12lf\n",i,edge[i].x.y,edge[i].x.x,1-edge[i].y);
        }
    }
}

/*
230
0.5 0.5
0.5 0.25
0.25 0.125
0.25
*/