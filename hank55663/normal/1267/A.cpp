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
#define EPS 1e-4
#define arg ARG
#define cpdd const pdd
#define rank Rank
//#define MXN 300000
#define N 100005
map<LL,int> m;
LL val[2000005];
LL dp[2000005];
vector<pll> in[2000005],out[2000005];
int main(){
    int n;
    scanf("%d",&n);
   // map<LL,vector<pll> >m ;
    pair<pll,LL> p[200005];
    priority_queue<pll,vector<pll>,greater<pll> > pq;
    for(int i=0;i<n;i++){
        LL l,r,t;
        scanf("%lld %lld %lld",&l,&r,&t);
       // m[l];
        //l+=t;
        //m[l];
        //m[r];
       // m[l].pb(mp(t,r));
        pq.push(mp(l,i));
        p[i]=mp(mp(l,r),t);
    }
    LL lastans=0,lasti=0;
    LL nexti=1e18+1;
    set<pll> s;
    while(!pq.empty()){
        pll pp=pq.top();
        pq.pop();
        LL t=pp.x;
        if(pp.x>=nexti){
            lasti=nexti;
            lastans++;
            nexti=1e18+1;
            while(s.size()){
                pll p=*s.begin();
                // printf("%lld %lld\n",p.x,p.y);
                if(p.y<=t){
                    if(p.y>lasti){
                        lastans+=(p.y-lasti)/p.x;
                        lasti=lasti+(p.y-lasti)/p.x*p.x;
                    }
                    s.erase(s.begin());
                }
                else{
                    lastans+=(t-lasti)/p.x;
                    lasti=lasti+(t-lasti)/p.x*p.x;
                    if(lasti+p.x<=p.y&&nexti>lasti+p.x){
                        nexti=lasti+p.x;
                        //break;
                    }
                    if(lasti+p.x>p.y){
                        s.erase(s.begin());
                    }
                    else{
                        break;
                    }
                  
                }
            }
        }
        //printf("%lld %lld %lld\n",lastans,lasti,nexti);
        //printf("%lld %lld %lld\n",lastans,lasti,nexti);
        if(t+p[pp.y].y<=nexti)nexti=t+p[pp.y].y;
        s.insert(mp(p[pp.y].y,p[pp.y].x.y));
        //printf("%lld %lld %lld\n",lastans,lasti,nexti);
    }
    lasti=nexti;
    lastans++;
    nexti=1e18+1;
    while(s.size()){
        pll p=*s.begin();
        if(p.y>lasti){
            lastans+=(p.y-lasti)/p.x;
            lasti=lasti+(p.y-lasti)/p.x*p.x;
        }
        s.erase(s.begin());
    }
    printf("%lld\n",lastans);
}
/*
2 -2000000000 2 -20000000000 1 1
*/