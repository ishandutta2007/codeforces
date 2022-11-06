#include<cstdio>
using namespace std;
int n,m,x,r,ans;
int main(){
    scanf("%d%d",&n,&m);
    for(x=n;x<m;x*=2)r++;
    x-=m;for(;r;x/=2,r--)ans+=x%2+1;
    printf("%d\n",ans+x);
}