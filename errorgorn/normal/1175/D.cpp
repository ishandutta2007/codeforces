#include <cstdio>
#include <algorithm>
using namespace std;
typedef pair<long long,long long> ii;
long long n,k;
long long arr[300005]; ///preset sum
int main(){
    //freopen("input.txt","r",stdin);
    scanf("%lld%lld",&n,&k);
    for (long long x=0;x<n;x++) scanf("%lld",&arr[x]);
    for (long long x=n-2;x>=0;x--) arr[x]+=arr[x+1];
    sort(&arr[1],&arr[n]);
    reverse(&arr[1],&arr[n]);
    long long ans=0;
    for (int x=0;x<k;x++){
        ans+=arr[x];
    }
    printf("%lld\n",ans);
}