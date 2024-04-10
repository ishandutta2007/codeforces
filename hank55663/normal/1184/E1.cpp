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
#define MXN 10005
#define less Less
pair<int,pii> p[1000005];
int f[100005];
int Find(int i){
    if(f[i]==i)return i;
    return f[i]=Find(f[i]);
}
int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    for(int i = 1;i<=n;i++)
        f[i]=i;
    pii a;
    for(int i = 0;i<m;i++){
        int x,y,e;
        scanf("%d %d %d",&x,&y,&e);
        p[i]=mp(e,mp(x,y));
        if(i==0){
            a=p[i].y;
            p[i].x=1e9;
        }
    }
    sort(p,p+m);
    for(int i = 0;i<m;i++){
        int fx=Find(p[i].y.x);
        int fy=Find(p[i].y.y);
        if(fx!=fy){
            f[fx]=fy;
            if(Find(a.x)==Find(a.y)){
                printf("%d\n",p[i].x);
                break;
            }
        }
    }
}