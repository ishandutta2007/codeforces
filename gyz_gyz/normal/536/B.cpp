#include<cstdio>
#include<cstring>
#define rep(i,x,y) for(int i=(x);i<=(y);i++)
#define mx 1000001
using namespace std;
int f[mx],p[mx],r[mx],mr[mx],n,m,l,ans;char c[mx];long long t;
int main(){
    scanf("%d%d",&n,&m);
    scanf("%s",c+1);l=strlen(c+1);
    rep(i,1,m)scanf("%d",&p[i]);
    rep(i,2,l){int j;
        for(j=f[i-1];j&&c[j+1]!=c[i];)j=f[j];
        if(c[j+1]!=c[i])f[i]=0;else f[i]=j+1;
    }
    ans+=p[1]-1;
    for(int i=l;i;i=f[i])r[i]=1;
    rep(i,2,m){
        if(p[i]-p[i-1]>=l)ans+=p[i]-p[i-1]-l;
        else if(!r[l-p[i]+p[i-1]])return printf("0\n"),0;
    }
    ans+=n-p[m]-l+1;if(!m)ans=n;t=1;
    rep(i,1,ans)t=t*26%1000000007;
    printf("%I64d\n",t);
}