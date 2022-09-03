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
double dis(pll p){
    return sqrt(sqr(p.x)+sqr(p.y));
}
void solve(){
    int n,k;
    scanf("%d %d",&n,&k);
    pll p[100005];
    for(int i = 0;i<n;i++){
        int x,y;
        scanf("%d %d",&x,&y);
        p[i]=mp(x,y);
    }
    double Max=2e6,Min=0;
    for(int i = 0;i<100;i++){
        double mid=(Max+Min)/2;
       // printf("%.12f\n",mid);
        vector<pair<double,int> > v;
        for(int i = 0;i<n;i++){
            if(p[i]==mp(0ll,0ll)){
                v.pb(mp(-pi,1));
                continue;
            }
            if(dis(p[i])+1e-8<2*mid){
                double theta=acos((-dis(p[i])*dis(p[i])+mid*mid*2)/(2*mid*mid));
                theta=(pi-theta)/2;
                double angle=atan2(p[i].y,p[i].x);
                double l=angle-theta,r=angle+theta;
              //  printf("%.12f %.12f\n",l,r);
              //  printf("%.12f %.12f %.12f\n",fmod(l+pi,2*pi)-pi,fmod(r+pi,2*pi)-pi,(dis(p[i])-mid*mid*2)/(2*mid*mid));
                if(l>-pi&&r<pi){
                    v.pb(mp(l,1));
                    v.pb(mp(r,-1));
                
                }
                else{
                    if(l<=-pi){
                        v.pb(mp(l+2*pi,1));
                        v.pb(mp(pi,-1));
                        v.pb(mp(-pi,1));
                        v.pb(mp(r,-1));
                       // v.pb(mp(l+2*pi,pi));
                       // v.pb(mp(-pi,r));
                    }
                    else if(r>=pi){
                         v.pb(mp(l,1));
                        v.pb(mp(pi,-1));
                        v.pb(mp(-pi,1));
                        v.pb(mp(r-2*pi,-1));
                        //v.pb(mp(l,pi));
                       // v.pb(mp(-pi,r-2*pi))
                    }
                    else{
                        assert(0);
                    }
                    
                }
            }
        }
        sort(v.begin(),v.end());
        int sum=0;
        int ok=0;
        for(auto it:v){
            sum+=it.y;
            if(sum>=k)ok=1;
        }
        if(ok)Max=mid;
        else Min=mid;
    }
    printf("%.12f\n",Max);
}
int main(){
    int t=1;//00;//00;
    //scanf("%d",&t);
    for(int i = 1;i<=t;i++){
        solve();
    }
 //   printf("0\n1\n2\n");
    //printf("8192\n");
    //printf("%d\n",cnt);
    //printf("%.12f\n",sum/tt);
    return 0;
}
/*
*/