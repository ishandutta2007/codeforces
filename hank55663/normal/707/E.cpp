#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define ULL unsigned long long
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
#define less Less
#define EPS 1e-4
#define arg ARG
#define cpdd const pdd
#define rank Rank
#define KK 500
#define MXN 200005
LL sum[2005][2005];
void add(int x,int y,int k){
    for(int i = x;i<2005;i+=i&-i){
        for(int j=y;j<2005;j+=j&-j){
            sum[i][j]+=k;
        }
    }
}
LL query(int x,int y){
    LL res=0;
    for(int i=x;i>0;i-=i&-i){
        for(int j=y;j>0;j-=j&-j){
            res+=sum[i][j];
        }
    }
    return res;
}
vector<pair<pii,pii> > qr;
vector<vector<LL> > que;
int val[2005][2005];
vector<vector<pii> > bulb(1);
vector<vector<int> > state;
int main(){ 
    int n,m,k;
    scanf("%d %d %d",&n,&m,&k);
    for(int i = 0;i<k;i++){
        int x;
        scanf("%d",&x);
        vector<pii> v;
        while(x--){
            int a,b;
            scanf("%d %d",&a,&b);
            scanf("%d",&val[a][b]);
            v.pb(mp(a,b));
        }
        bulb.pb(v);
    }
    int q;
    scanf("%d",&q);
    vector<int> v(k+1,1);
    while(q--){
        char c[10];
        scanf("%s",c);
        if(c[0]=='S'){
            int x;
            scanf("%d",&x);
            v[x]^=1;
        }
        else{
            int x1,x2,y1,y2;
            scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
            qr.pb(mp(mp(x1-1,y1-1),mp(x2,y2)));
            state.pb(v);
            que.pb(vector<LL>(k+1,0));
        }
    }
    for(int i = 1;i<=k;i++){
        for(auto it:bulb[i]){
          //  printf("%d %d %d\n",it.x,it.y,val[it.x][it.y]);
            add(it.x,it.y,val[it.x][it.y]);
        }
        for(int j=0;j<que.size();j++){
            int x1=qr[j].x.x,y1=qr[j].x.y,x2=qr[j].y.x,y2=qr[j].y.y;
            que[j][i]=query(x2,y2)-query(x1,y2)-query(x2,y1)+query(x1,y1);
            //printf("%d %d %d %d\n",x1,y1,x2,y2);
            //printf("%d %d %lld %lld %lld %lld %lld\n",j,i,que[j][i],query(x2,y2),query(x1,y2),query(x2,y1),query(x1,y1));
        }
    }
    for(int i = k;i>=1;i--){
        for(int j=0;j<que.size();j++){
           // int x1=qr[j].x.x,y1=qr[j].x.y,x2=qr[j].y.x,y2=qr[j].y.y;
            que[j][i]-=que[j][i-1];
            //printf("%d %d %d %d\n",x1,y1,x2,y2);
            //printf("%d %d %lld %lld %lld %lld %lld\n",j,i,que[j][i],query(x2,y2),query(x1,y2),query(x2,y1),query(x1,y1));
        }
    }
    for(int j=0;j<que.size();j++){
        LL ans=0;
        for(int i=1;i<=k;i++){
            ans+=state[j][i]*que[j][i];
        }
        printf("%lld\n",ans);
    }
}
/*
1 2 2 3 3 3 4
2 2 1
3 2 3
4 2 4 4 7
 
1 1
*/