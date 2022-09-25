#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;
int n;
int arr[4005];
set<int> s;
int main(){
    scanf("%d",&n);
    for (int x=0;x<n;x++) scanf("%d",&arr[x]),s.insert(arr[x]);
    
    int curr;
   for (int x=1;x<n;x++){
       if (__gcd(arr[0],arr[x])<arr[0]){
           printf("-1\n");
           return 0;
       }
   }
    
    printf("%d\n",2*n);
    for (int x=0;x<n;x++) {
        printf("%d ",arr[0]);
        printf("%d ",arr[x]);
    }
}