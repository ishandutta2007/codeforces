#include <cstdio>
#include <algorithm>
using namespace std;
int n;
int arr[2005];
int main(){
    scanf("%d",&n);
    n<<=1;
    for  (int x=0;x<n;x++){
        scanf("%d",&arr[x]);
    }
    sort(&arr[0],&arr[n]);
    if (arr[0]==arr[n-1]){
        printf("-1\n");
        return 0;
    }
    for (int x=0;x<n;x++){
        printf("%d ",arr[x]);
    }
}