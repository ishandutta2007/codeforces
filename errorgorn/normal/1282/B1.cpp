#include <cstdio>
#include <algorithm>
using namespace std;
int n,p,k;
int arr[200005];
int main(){
    int TC;
    scanf("%d",&TC);
    while (TC--){
        scanf("%d%d%d",&n,&p,&k);
        for (int x=1;x<=n;x++) scanf("%d",&arr[x]);
        
        sort(&arr[1],&arr[n+1]);
        
        int best=0;
        
        for (int x=1;x<=n;x++){
            if (x>=k) arr[x]+=arr[x-k];
            else arr[x]+=arr[x-1];
            if (arr[x]<=p) best=x;
        }
        printf("%d\n",best);
    }
}