#include<cstdio>
#define rep(i,x,y) for(int i=(x);i<=(y);i++)
#define N 100001
using namespace std;
int n,a[N],b[N],s,ans;
int main(){
    scanf("%d",&n);
    rep(i,1,n){
        scanf("%d",&a[i]);b[a[i]]=i;
    }s=1;ans=1;
    rep(i,2,n){
        if(b[i]>b[i-1])s++;else s=1;
        if(s>ans)ans=s;
    }
    printf("%d\n",n-ans);
}