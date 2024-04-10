#include <cstdio>
#include <algorithm>
using namespace std;
int n,m,k;
int arr[105];
int it;
int main(){
    int TC;
    scanf("%d",&TC);
    while (TC--){
        scanf("%d%d%d",&n,&m,&k);
        for (int x=1;x<=n;x++) scanf("%d",&arr[x]);
        it=1;
        while (it!=n){
            if (arr[it]>=max(0,arr[it+1]-k)){
                m+=(arr[it]-max(0,arr[it+1]-k));
            }
            else {
                if (m<arr[it+1]-k-arr[it]){
                    printf("NO\n");
                    goto _end;
                }
                else m-=arr[it+1]-k-arr[it];
            }
            it++;
        }
        printf("YES\n");
        _end:;
    }
}