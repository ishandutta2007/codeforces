#include <cstdio>
#include <algorithm>
using namespace std;
int n;
int arr[100005];
int main(){
    scanf("%d",&n);
    for (int x=0;x<(2<<n)-2;x++) scanf("%d",&arr[x]);
    int ans=0;
    
    for (int x=(1<<n)-2;x>=0;x--){
        //printf("%d\n",x);
        //printf("%d %d\n",arr[x*2+1],arr[x*2]);
        ans+=max(arr[x*2],arr[x*2+1])-min(arr[x*2+1],arr[x*2]);
        if (x) arr[x-1]+=max(arr[x*2],arr[x*2+1]);
    }
    
    printf("%d\n",ans);
}