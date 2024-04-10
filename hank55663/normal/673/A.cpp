#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <set>
#include <map>
using namespace std;
main(){
    int n;
    scanf("%d",&n);
    int a[1000];
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
        a[n]=90;
    int ans=15;
    for(int i=0;i<n;i++){
        if(a[i]>ans)
            break;
        else
            ans=a[i]+15
;    }
    printf("%d\n",min(ans,90));
}