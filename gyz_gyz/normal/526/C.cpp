#include<cstdio>
#define rep(i,x,y) for(int i=(x);i<=(y);i++)
using namespace std;
long long n,a,b,c,d,tmp,x,ans,r,w;
int main(){
    scanf("%I64d%I64d%I64d%I64d%I64d",&n,&a,&b,&c,&d);
    if(c<d)tmp=c,c=d,d=tmp,tmp=a,a=b,b=tmp;
    if(a*d>b*c)x=a*d;else x=b*c;
    r=n/(c*d)*x;n%=c*d;if(r)r-=x,n+=c*d;
    rep(i,0,n/c){
        w=i*a+(n-i*c)/d*b;
        if(w>ans)ans=w;
    }
    printf("%I64d\n",ans+r);
}