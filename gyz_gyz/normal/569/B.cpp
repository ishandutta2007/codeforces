#include<cstdio>
#define rep(i,x,y) for(int i=(x);i<=(y);i++)
#define mx 100001
using namespace std;
int a[mx],b[mx],c[mx],n,j;
int main(){
    scanf("%d",&n);
    rep(i,1,n)scanf("%d",&a[i]);
    rep(i,1,n)c[a[i]]=1;j=1;
    rep(i,1,n)if(b[a[i]]||a[i]>n){
        while(b[j]||c[j])j++;b[j]=1;a[i]=j;
    }else b[a[i]]=1;
    rep(i,1,n)printf("%d ",a[i]);
}