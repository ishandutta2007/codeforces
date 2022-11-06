#include<cstdio>
#include<cstring>
#define read(x) scanf("%d",&x);
#define rep(i,x,y) for(i=(x);i<=(y);i++)
#define Rep(i,x,y) for(i=(x);i>=(y);i--)
#define num(x) (int(x)-48)
#define mx 1000001
using namespace std;
int n,a[mx];int x,y,i,j,p,q,r;char c[mx];
int main(){
    scanf("%s",c);n=strlen(c);
    scanf("%d%d",&x,&y);a[n-1]=1%y;
    rep(i,0,n-1)q=(q*10+num(c[i]))%y;
    Rep(i,n-2,0)a[i]=a[i+1]*10%y;
    rep(i,0,n-1){
        r=num(c[i]);q=(q+10*y-r*a[i])%y;
        p=(p*10+r)%x;
        if((c[i+1]!='0')&&(!p)&&(!q))break;
    }
    if(i>=n-1)puts("NO");else{
        puts("YES");
        rep(j,0,i)printf("%c",c[j]);puts("");
        rep(j,i+1,n-1)printf("%c",c[j]);puts("");
    }
}