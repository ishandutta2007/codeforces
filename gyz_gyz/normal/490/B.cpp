#include<cstdio>
#define rep(i,x,y) for(i=(x);i<=(y);i++)
#define read(x) scanf("%d",&x);
#define mxn 200001
#define mx 1000001
using namespace std;
int n,i,j,st,a[mxn],b[mxn],c[mx],d[mx];
int main(){
    read(n);rep(i,1,n){read(a[i]);c[a[i]]=i;read(b[i]);d[b[i]]++;}
    rep(j,1,mx-1)if((c[j])&&(!d[j]))break;
    for(i=0;;){printf("%d %d ",a[c[j]],b[c[i]]);
        i=b[c[i]];if(!c[i])break;
        j=b[c[j]];if(!c[j]){printf("%d",j);break;}
    }
}