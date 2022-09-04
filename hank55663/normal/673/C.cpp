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
    int a[5005];
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    int ans[5005];
    for(int i=0;i<n;i++){
        int num[5005];
        memset(num,0,sizeof(num));
        int ma=0,mai=0;
        for(int j=i;j<n;j++){
            num[a[j]]++;
            if(num[a[j]]>ma)
                ma=num[a[j]],mai=a[j];
            else if(num[a[j]]==ma&&a[j]<mai)
                mai=a[j];
            ans[mai]++;
        }
    }
    for(int i=1;i<=n;i++)
        printf("%d ",ans[i]);
}