#include <cstdio>
using namespace std;
int n,k;
const int MOD=1000000007;

int arr[10];

int main(){
    scanf("%d%d",&n,&k);
    long long ans=1;
    for (int x=1;x<k;x++) ans=(ans*k)%MOD;
    for (int x=k;x<n;x++) ans=(ans*(n-k))%MOD;
    printf("%lld\n",ans);
}