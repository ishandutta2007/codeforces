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
int ok[3005][3005];
int ok2[3005][3005];
double at[3005][3005];
void solve(){
    int n;
    LL R;
    scanf("%d %lld",&n,&R);
    pll p[3005];
    for(int i = 0;i<n;i++){
        int x,y;
        scanf("%d %d",&x,&y);
       // x=rand()%100000,y=rand()%100000;
        p[i]=mp(x,y);
    }
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){LL x=p[j].x-p[i].x,y=p[j].y-p[i].y;
            if(i==j)continue;
            at[i][j]=atan2(y,x);
        }
    }
    for(int i = 0;i<n;i++){
        vector<pair<double,pii> > v;
        int cnt=0;
        double l=-3*pi,r=3*pi;
        for(int j = 0;j<n;j++){
            LL x=p[j].x-p[i].x,y=p[j].y-p[i].y;
            //printf("%lld %lld %lld\n",x,y,r);
            if(x*x+y*y>R*R){
                cnt++;
                double angle=at[i][j];
                double d=sqrt(x*x+y*y);
                double d2=sqrt(r*r-d*d);
                double theta=pi/2;
                double ll=angle-theta,rr=angle+theta;
                if(ll<-pi){
                    ll+=2*pi;
                    rr+=2*pi;
                }
                //printf("%lf %lf\n",ll,rr);
                if(max(ll,l)<min(rr,r))l=max(ll,l),r=min(rr,r);
                else if(max(ll+2*pi,l)<min(rr+2*pi,r))l=max(ll+2*pi,l),r=min(rr+2*pi,r);
                else if(max(ll-2*pi,l)<min(rr-2*pi,r))l=max(ll-2*pi,l),r=min(rr-2*pi,r);
                else l=4*pi,r=0;
            }
           
        }
        for(int j=0;j<n;j++){
             double angle=at[i][j];
             if(i==j)continue;
             if(angle>l&&angle<r)ok[i][j]=1;
             if(angle+2*pi>l&&angle+2*pi<r)ok[i][j]=1;
             //if(ok[i][j])printf("%d %d %lf %lf %lf\n",i,j,l,angle,r);
         //    else printf("? %d %d %lf %lf %lf\n",i,j,l,angle,r);
        }
    }
    int ans=0;
    for(int i = 0;i<n;i++){
         vector<pair<double,pii> > v;
        int cnt=0;
        double l=-3*pi,r=3*pi;
        for(int j = 0;j<n;j++){
            LL x=p[j].x-p[i].x,y=p[j].y-p[i].y;
            if(x*x+y*y>R*R){
                cnt++;
                double angle=at[i][j];
                double d=sqrt(x*x+y*y);
                double d2=sqrt(d*d-R*R);
                double theta=asin(R/d);
                double ll=angle-theta,rr=angle+theta;
                if(ll<-pi){
                    ll+=2*pi;
                    rr+=2*pi;
                }
           //     printf("%lf %lf\n",ll,rr);
                if(max(ll,l)<min(rr,r))l=max(ll,l),r=min(rr,r);
                else if(max(ll+2*pi,l)<min(rr+2*pi,r))l=max(ll+2*pi,l),r=min(rr+2*pi,r);
                else if(max(ll-2*pi,l)<min(rr-2*pi,r))l=max(ll-2*pi,l),r=min(rr-2*pi,r);
                else l=4*pi,r=0;
            }
        }
       // printf("%lf %lf\n",l,r);
        for(int j=0;j<n;j++){
             double angle=at[i][j];
             if(angle>l&&angle<r)ok2[i][j]=1;
             if(angle+2*pi>l&&angle+2*pi<r)ok2[i][j]=1;
            // if(ok2[i][j])printf("%d %d %lf %lf %lf\n",i,j,l,angle,r);
        }
    }
    for(int i = 0;i<n;i++){
        for(int j = i+1;j<n;j++){
            if(ok[i][j]&&ok[j][i]&&ok2[i][j])ans++;//,printf("%d %d\n",i,j);
        }
    }
    printf("%d\n",ans);
}

int main(){

    int t=1;0000;
   // scanf("%d",&t);
    for(int i = 1;i<=t;i++){
       // cerr<<i<<endl;
        solve();
    }
    return 0;
}
/*
ACBABC
ACBCAB
ACABCB
*/