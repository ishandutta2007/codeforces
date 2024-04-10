#include <cstdio>
#include <cmath>
using namespace std;
int n,m;
int arr[1005];
int main(){
    int TC;
    scanf("%d",&TC);
    while (TC--){
        scanf("%d%d",&n,&m);
        for (int x=0;x<n;x++) scanf("%d",&arr[x]);

        if (n==2 || m<n) {
            printf("-1\n");
            continue;
        }

        int ans=0;
        for (int x=0;x<n;x++) ans+=arr[x]*2;
        printf("%d\n",ans);
        for (int x=2;x<=n;x++){
            printf("%d %d\n",x-1,x);
        }
        printf("%d %d\n",n,1);
    }
}