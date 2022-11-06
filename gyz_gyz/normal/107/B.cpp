#include<cstdio>
#define rep(i,x,y) for(int i=(x);i<=(y);i++)
#define N 1010
using namespace std;
int n,m,k,x,p,q;
long double ans;
int main(){
    scanf("%d%d%d",&n,&m,&k);n--;
    rep(i,1,m){
        scanf("%d",&x);
        if(i!=k)p+=x;else q=x-1;
    }
    if(p+q<n){
        printf("-1\n");return 0;
    }
    if(p<n){
        printf("1\n");return 0;
    }
    ans=1;
    rep(i,p-n+1,p)ans*=i;
    rep(i,p+q-n+1,p+q)ans/=i;
    printf("%.10lf\n",double(1-ans));
}