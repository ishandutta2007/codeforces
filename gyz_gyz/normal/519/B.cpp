#include<cstdio>
#include<algorithm>
#define rep(i,x,y) for(int i=(x);i<=(y);i++)
using namespace std;
int a[100001],b[100001],n;
int main(){
    scanf("%d",&n);
    rep(i,1,n)scanf("%d",&a[i]);
    rep(i,1,n-1)scanf("%d",&b[i]);
    sort(a+1,a+1+n);sort(b+1,b+n);
    rep(i,1,n)if(a[i]!=b[i]){
        printf("%d\n",a[i]);break;
    }
    rep(i,1,n-2)scanf("%d",&a[i]);
    sort(a+1,a+n-1);a[n-1]=0;
    rep(i,1,n-1)if(a[i]!=b[i]){
        printf("%d\n",b[i]);break;
    }
}