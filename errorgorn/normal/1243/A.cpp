#include <cstdio>
#include <algorithm>
using namespace std;
int n;
int arr[1005];
int main(){
    int TC;
    scanf("%d",&TC);
    while (TC--){
        scanf("%d",&n);
        for (int x=0;x<n;x++) scanf("%d",&arr[x]);

        sort(&arr[0],&arr[n],[](int i,int j){
            return i>j;
        });

        int ans=0;
        for (int x=0;x<n;x++){
            ans=max(ans,min(x+1,arr[x]));
        }

        printf("%d\n",ans);
    }
}