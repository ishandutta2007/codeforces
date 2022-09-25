#include <cstdio>
#include <algorithm>
using namespace std;
long long n,k;
int arr[1000005];
int brr[1000005];
int main(){
    scanf("%lld%lld",&n,&k);
    if (k<(n+1)*n/2){
        printf("-1\n");
        return 0;
    }
    long long curr=0;
    for (int x=1;x<=n;x++){
        curr+=max(n-x+1,(long long)x);
    }
    if (curr<=k){
        printf("%lld\n",curr);
        for (int x=1;x<=n;x++) printf("%d ",x);
        printf("\n");
        for (int x=n;x>=1;x--) printf("%d ",x);
        printf("\n");
        return 0;
    }
    
    curr=0;
    for (int x=1;x<=n;x++) curr+=arr[x]=brr[x]=x;
    
    int iter=n;
    while (true){
        curr+=brr[iter]-brr[n-iter+1];
        if (curr>k){
            curr-=brr[iter]-brr[n-iter+1];
            break;
        }
        swap(brr[iter],brr[n-iter+1]);
        iter--;
    }
    
    swap(brr[iter],brr[iter-(k-curr)]);
    printf("%lld\n",k);
    for (int x=1;x<=n;x++) printf("%d ",arr[x]);
    printf("\n");
    for (int x=1;x<=n;x++) printf("%d ",brr[x]);
    printf("\n");
}