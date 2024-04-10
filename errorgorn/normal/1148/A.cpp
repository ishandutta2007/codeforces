#include <cstdio>
#include <algorithm>
using namespace std;
int main(){
    //freopen("input.txt","r",stdin);
    long long a,b,c;
    scanf("%lld%lld%lld",&a,&b,&c);
    long long ans=0;
    ans+=c*2;
    ans+=min(a,b)*2;
    if (a!=b) ans++;
    printf("%lld\n",ans);
}