#include <cstdio>
#include <algorithm>
using namespace std;
int tc;
int n,k;
int arr[200005];
int _min,ans;
int main(){
    //freopen("input.txt","r",stdin);
    scanf("%d",&tc);
    while (tc--){
        _min=2000000000;
        ans=0;
        scanf("%d%d",&n,&k);
        for (int x=0;x<n;x++) scanf("%d",&arr[x]);
        for (int x=k;x<n;x++){
            if (_min>arr[x]-arr[x-k]){
                _min=arr[x]-arr[x-k];
                ans=(arr[x]+arr[x-k])>>1;
            }
        }
        printf("%d\n",ans);
    }
}