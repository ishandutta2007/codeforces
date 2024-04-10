#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define x first
#define LL long long 
#define y second
#define sqr(x) ((x)*(x))
#define pii pair<int,int>
#define pll pair<LL,LL>
#define pdd pair<long double,long double>
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
#define pi acosl(-1)
//#define N 524288
#define ld long double
using namespace std;
int main(){
    int t;
    scanf("%d",&t);
    LL a[100005],b[100005],c[100005];
    while(t--){
        int x,y,z;
        scanf("%d %d %d",&x,&y,&z);
        for(int i = 0;i<x;i++)scanf("%lld",&a[i]);
        for(int i=0;i<y;i++)scanf("%lld",&b[i]);
        for(int i = 0;i<z;i++)scanf("%lld",&c[i]);
        sort(a,a+x);
        sort(b,b+y);
        sort(c,c+z);
        LL ans=5e18;
        for(int i = 0;i<x;i++){
            {
                int yy=lower_bound(b,b+y,a[i])-b;
                int zz=upper_bound(c,c+z,a[i])-1-c;
                if(yy!=y&&zz!=-1){
                    ans=min(ans,sqr(a[i]-b[yy])+sqr(b[yy]-c[zz])+sqr(a[i]-c[zz]));
                }
            }
            {
                int yy=upper_bound(b,b+y,a[i])-1-b;
                int zz=lower_bound(c,c+z,a[i])-c;
                //printf("%d %d %d %lld %lld %lld\n",i,yy,zz,a[i],b[yy],);
                if(yy!=-1&&zz!=z){
                    ans=min(ans,sqr(a[i]-b[yy])+sqr(b[yy]-c[zz])+sqr(a[i]-c[zz]));
                }
            }
        }
        for(int i = 0;i<y;i++){
            {
                int xx=lower_bound(a,a+x,b[i])-a;
                int zz=upper_bound(c,c+z,b[i])-1-c;
                if(xx!=x&&zz!=-1){
                    ans=min(ans,sqr(a[xx]-b[i])+sqr(b[i]-c[zz])+sqr(a[xx]-c[zz]));
                }
            }
            {
                int xx=upper_bound(a,a+x,b[i])-1-a;
                int zz=lower_bound(c,c+z,b[i])-c;
                if(xx!=-1&&zz!=z){
                    ans=min(ans,sqr(a[xx]-b[i])+sqr(b[i]-c[zz])+sqr(a[xx]-c[zz]));
                }
            }
        }
        for(int i = 0;i<z;i++){
            {
                int yy=lower_bound(b,b+y,c[i])-b;
                int xx=upper_bound(a,a+x,c[i])-1-a;
                if(yy!=y&&xx!=-1){
                    ans=min(ans,sqr(a[xx]-b[yy])+sqr(b[yy]-c[i])+sqr(a[xx]-c[i]));
                }
            }
            {
                int yy=upper_bound(b,b+y,c[i])-1-b;
                int xx=lower_bound(a,a+x,c[i])-a;
                if(yy!=-1&&xx!=x){
                    ans=min(ans,sqr(a[xx]-b[yy])+sqr(b[yy]-c[i])+sqr(a[xx]-c[i]));
                }
            }
        }
        printf("%lld\n",ans);
    }
}
/*
00 00
01 10
10 11
11 01

*/