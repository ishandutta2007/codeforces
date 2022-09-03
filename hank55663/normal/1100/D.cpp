#include<bits/stdc++.h>
//#include<bits/extc++.h>
using namespace std;
//using namespace __gnu_pbds;
//typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> set_t;
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
#define pll pair<LL,LL>
#define pdd pair<double,double>
#define pb push_back
#define x first
#define y second
//#define sqr(x) ((x)*(x))
#define EPS 1e-7
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
#define pi acos(-1)
#define sqr(x) ((x)*(x))
#define Line pair<pii,pii> 
typedef long long LL;
#define hash Hash;
#define MXN 100005
//#define assert(x) while(!(x))
int vis[1000][1000];
int main(){
    int stx,sty;
    scanf("%d %d",&stx,&sty);
    vector<pii> v;
    set<pii> s;
    for(int i=0;i<666;i++){
        int x,y;
        //x=rand()%999+1;
        //y=rand()%999+1;
        scanf("%d %d",&x,&y);
        v.pb(mp(x,y));
        s.insert(mp(x,y));
    }
    while(stx!=500||sty!=500){
        if(stx<500){
            stx++;
            //printf("%d ",stx);
        }
        if(stx>500){
            stx--;
        }
       // printf("%d ",stx);
        int ori=sty;
        if(sty<500){
            sty++;
            //printf("%d\n",sty);
        }
        if(sty>500){
            sty--;
        }
        if(s.find(mp(stx,sty))!=s.end())sty=ori;
        printf("%d %d\n",stx,sty);
        fflush(stdout);
        int d,x,y;
        scanf("%d %d %d",&d,&x,&y);
        if(d==-1)
        return 0;
        if(d==0)
        return 0;
     //   if(v[d-1].x>0&&v[d-1].x<1000&&v[d-1].y>0&&v[d-1].y<1000)
     //   vis[v[d-1].x][v[d-1].y]=0;
        s.erase(v[d-1]);
        v[d-1]=mp(x,y);
        s.insert(v[d-1]);
       // if(x>0&&x<1000&&y>0&&y<1000)
        //vis[x][y]=1;
    }
    assert(stx==500&&sty==500);
    int cnt[4];
    MEM(cnt);
    for(auto it:v){
        if(it.x<stx&&it.y<sty){
            cnt[0]++;
        }
        if(it.x<stx&&it.y>sty){
            cnt[1]++;
        }
        if(it.x>stx&&it.y<sty){
            cnt[2]++;
        }
        if(it.x>stx&&it.y>sty){
            cnt[3]++;
        }
    }
    int X[4]={1,1,-1,-1};
    int Y[4]={1,-1,1,-1};
    int Min=1e9,Mini;
    for(int i=0;i<4;i++){
        if(cnt[i]<Min){
            Min=cnt[i];
            Mini=i;
        }
    }
    assert(Min<=166);
    assert(Mini>=0&&Mini<4);
    for(int i=0;i<1000;i++){
        stx+=X[Mini];
        int ori=sty;
        sty+=Y[Mini];
        if(s.find(mp(stx,sty))!=s.end()){
            sty=ori;
        }
        printf("%d %d\n",stx,sty);
       // assert(stx>0&&stx<1000&&sty>0&&sty<1000);
        fflush(stdout);
        int a,b,c;
        scanf("%d %d %d",&a,&b,&c);
       // vis[v[a-1].x][v[a-1].y]=0;
        s.erase(v[a-1]);
        v[a-1]=mp(b,c);
        s.insert(v[a-1]);
      //  vis[b][c]=1;
        if(a==-1){
            break;
        }
    }
}