#include <cstdio>
#include <algorithm>
using namespace std;
int n;
int arr[100005];
int main(){
    bool odd=false,even=false;
    scanf("%d",&n);
    for (int x=0;x<n;x++){
        scanf("%d",&arr[x]);
        if (arr[x]&1) odd=true;
        else even=true;
    }
    if (odd&&even) sort(&arr[0],&arr[n]);
    for (int x=0;x<n;x++) printf("%d ",arr[x]);
}