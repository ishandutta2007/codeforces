#include<cstdio>
#define rep(i,x,y) for(int i=(x);i<=(y);i++)
#define mx 3000000
#define mo 1000000007
#define ll long long
using namespace std;
int n;ll a[mx];
int pr(int x){
    if(x==1)return 1;
    ll s=mo/x+1;return s*pr(s*x-mo)%mo;
}
int main(){
    scanf("%d",&n);n++;a[0]=1;
    rep(i,1,n*2)a[i]=a[i-1]*i%mo;
    printf("%I64d\n",(2*a[2*n-1]%mo*pr(a[n])%mo*pr(a[n-1])%mo+mo-1)%mo);
}