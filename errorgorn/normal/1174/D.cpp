#include <cstdio>
using namespace std;
int n,k;
int arr[300005];
int main(){
    scanf("%d%d",&n,&k);
    int iter=1;
    for (int x=1;x<(1<<n);x++){
        if (x==k || (x^k)<x) continue;
        arr[iter++]=x;
    }
    printf("%d\n",iter-1);
    for (int x=1;x<iter;x++){
        printf("%d ",arr[x]^arr[x-1]);
    }
}