#include <cstdio>
#include <algorithm>
using namespace std;
int TC;
int n,t,arr[3];
int main(){
    scanf("%d",&TC);
    while (TC--){
        scanf("%d",&n);
        arr[0]=arr[1]=arr[2]=0;
        while (n--){
            scanf("%d",&t);
            arr[t%3]++;
        }
        t=min(arr[1],arr[2]);
        arr[0]+=t;
        arr[1]-=t;
        arr[2]-=t;
        printf("%d\n",arr[0]+arr[1]/3+arr[2]/3);
    }
}