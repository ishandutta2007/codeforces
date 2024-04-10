#include <cstdio>
#include <algorithm>
using namespace std;

inline double cross(double x, double y, double p, double q){
    return max(0.0,min(y,q)-max(x,p));
}

int main(){
    int nf,ne,ns,rf,re,rs,df,de;
    scanf("%d%d%d",&nf,&ne,&ns);
    scanf("%d%d%d",&rf,&re,&rs);
    scanf("%d%d",&df,&de);
    double lf=sqrt(rf*rf-1);
    double le=sqrt(re*re-1);
    double ls=sqrt(rs*rs-1),ans=0;
    int n=nf+ne+ns,all=(1<<n)-1;
    for(int s=0;s<=all;s++){
        if(__builtin_popcount(s)!=ns) continue;
        vector<double> u;
        double now=0;
        for(int r=all^s;r;r&=r-1){
            int x=__builtin_ctz(r)/2;
            double vf=2*lf*df,ve=2*le*de;
            for(int t=s;t;t&=t-1){
                int y=__builtin_ctz(t)/2;
                vf+=cross(x-lf,x+lf,y-ls,y+ls)*df;
                ve+=cross(x-le,x+le,y-ls,y+ls)*de;
            }
            now+=vf;
            u.push_back(vf-ve);
        }
        sort(u.begin(),u.end());
        for(int i=0;i<ne;i++) now-=u[i];
        ans=max(ans,now);
    }
    printf("%.12f\n",ans);
}