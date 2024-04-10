#include<cstdio>
#define rep(i,x,y) for(int i=(x);i<=(y);i++)
using namespace std;
const long long md=1000000007;
char c[200000];int n,p[5],mx;
long long ans,fl;
int main(){
    scanf("%d",&n);
    scanf("%s",c);
    rep(i,0,n-1){
        if(c[i]=='A')p[1]++;
        if(c[i]=='C')p[2]++;
        if(c[i]=='G')p[3]++;
        if(c[i]=='T')p[4]++;
    }
    rep(i,1,4)if(p[i]>mx)mx=p[i];
    rep(i,1,4)if(mx==p[i])fl++;ans=1;
    rep(i,1,n)ans=ans*fl%md;
    printf("%I64d\n",ans);
}