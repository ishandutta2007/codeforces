#include <cstdio>
#include <algorithm>
using namespace std;
int n;
int arr[100005];
int main(){
    scanf("%d",&n);
    for (int x=0;x<n;x++) scanf("%d",&arr[x]);
    int best=arr[0];
    for (int x=1;x<n;x++){
        best=__gcd(best,arr[x]);
    }
    if (best>1){
        printf("YES\n0\n");
        return 0;
    }

    int ans=0;
    for (int x=0;x<n-1;x++){
        if (arr[x]&1){
            if (arr[x+1]&1){
                ans++;
                arr[x]^=1;
                arr[x+1]^=1;
            }
            else{
                ans+=2;
            }
        }
    }
    if (arr[n-1]&1) ans+=2;

    printf("YES\n%d\n",ans);
}