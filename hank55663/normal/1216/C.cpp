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
#define MXN 1500
bool check(pair<pii,pii> p,pii q){
    if(q.x>=p.x.x&&q.x<=p.y.x&&q.y>=p.x.y&&q.y<=p.y.y)return true;
    return false;
}
bool touch(pair<pii,pii> p1,pair<pii,pii> p2){
    for(int t=0;t<2;t++){
        vector<pii> pp2;
        pp2.pb(p2.x);pp2.pb(p2.y);
        pp2.pb(mp(p2.x.x,p2.y.y));pp2.pb(mp(p2.y.x,p2.x.y));
        for(auto it:pp2){
            if(check(p1,it))return true;
        }
        swap(p1,p2);
    }
    return false;
}
int main(){
    pair<pii,pii> p[3];
    for(int i = 0;i<3;i++){
        int a,b,c,d;
        scanf("%d %d %d %d",&a,&b,&c,&d);
        p[i]=mp(mp(a,b),mp(c,d));
    }
    vector<pii> pp;
    pp.pb(p[0].x);pp.pb(p[0].y);
    pp.pb(mp(p[0].x.x,p[0].y.y));pp.pb(mp(p[0].y.x,p[0].x.y));
    int ok=0;
    for(auto it:pp){
        if(!check(p[1],it)&&!check(p[2],it))ok=1;
    }
    if(ok){
        printf("YES\n");
    }
    else{
        if(touch(p[1],p[2]))
        printf("NO\n");
        else{
            int ok1=0,ok2=0;
            for(auto it:pp){
                if(!check(p[2],it))ok2=1;
                if(!check(p[1],it))ok1=1;
            }
            if(ok1&&ok2)
            printf("YES\n");
            else
            printf("NO\n");
        }
    }
}