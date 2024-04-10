#include <cstdio>
#include <algorithm>
using namespace std;
int n;
int a[200005];
int b[200005];
int main(){
    //freopen("input.txt","r",stdin);
    scanf("%d",&n);
    for (int x=0;x<n;x++){
        scanf("%d",&a[x]);
    }
    for (int x=0;x<n;x++){
        scanf("%d",&b[x]);
    }
    int ans=n;
    for (int x=0;x<n;x++){
        if (b[x]) ans=max(n-b[x]+x+2,ans);
    }
    int ans2=0;
    for (int x=0;x<n;x++){
        if (!b[x]) continue;
        else if (b[x]==1){
            if (ans2<=x){
                ans2=x;
            }
            else{
                ans2=-1;
            }
            break;
        }
        else ans2=max(n-b[x]+x+2,ans2);

    }
    //printf("%d %d\n",ans,ans2);
    if (ans2!=-1){
        for (int x=ans2;x<n;x++){
            if (x-b[x]!=ans2-1 || b[x]==0) goto _end;
        }
    }
    else goto _end;
    printf("%d\n",ans2);
    return 0;
    _end:
    printf("%d\n",ans);
}