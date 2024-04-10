#include <cstdio>
#include <algorithm>
using namespace std;
int l,n,k;
int arr[1005];
int space[1005];
int main(){
    scanf("%d%d%d",&l,&n,&k);
    k--;
    int s=l;
    for (int x=0;x<n;x++){
        scanf("%d",&arr[x]);
        s-=arr[x];
    }
    for (int x=0;x<=n;x++){
        space[x]=min(k,s);
        s-=space[x];
    }

    if (s){
        printf("NO\n");
        return 0;
    }
    printf("YES\n");
    for (int x=0;x<=n;x++){
        for (int y=0;y<space[x];y++) printf("0 ");
        for (int y=0;y<arr[x];y++) printf("%d ",x+1);
    }
}