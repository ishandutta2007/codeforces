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
#define EPS 1e-3
#define arg ARG
#define pdd pair<double,double>
#define cpdd const pdd
int mod=1e9+7;
bool cmp(const pii &p,const pii &q){
    if(p.y!=q.y)
    return p.y<q.y;
    return p.x<q.x;
}
int main() {
    int n;
    scanf("%d",&n);
    pii p[200005];
    int Max=0;
    for(int i = 0;i<n;i++){
        int x,y;
        scanf("%d %d",&x,&y);
        p[i]=mp(x,y);
        Max=max(Max,y);
    }
    sort(p,p+n,cmp);
    map<int,pair<int,int> > m;
    int extra=0,last=0,sum=1;
    int Min=1e9,ans=0;
    for(int i = 0;i<n;i++){
        if(last!=p[i].y){
            extra+=p[i].y-last;
            auto it=m.upper_bound(last);
            last=p[i].y;
            while(it!=m.end()&&it->x<=p[i].y){
             //   printf("! %d\n",it->y.x+p[i].x-it->x);
                if(it->y.x+p[i].y-it->x==extra){
                    sum+=it->y.y;
                    sum%=mod;
                }
                if(it->y.x+p[i].y-it->x<extra){
                    extra=it->y.x+p[i].y-it->x;
                    sum=it->y.y;
                }
                it=next(it);
            }
        }
        if(m.find(p[i].x)==m.end()){
            m[p[i].x]=mp(extra,sum);
        }
        else if(m[p[i].x].x==extra){
            m[p[i].x].y+=sum;
            m[p[i].x].y%=mod;
        }
        else if(m[p[i].x].x>extra){
            m[p[i].x]=mp(extra,sum);
        }
        //printf("%d %d %d\n",p[i].x,m[p[i].x].x,m[p[i].x].y);
        if(p[i].x>Max){
            if(Min==extra){
                ans+=sum;
                ans%=mod;
            }
            else if(extra<Min){
                Min=extra;
                ans=sum;
            }
        }
    }
    printf("%d\n",ans);
}