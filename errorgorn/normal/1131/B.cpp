#include <cstdio>
#include <algorithm>
using namespace std;
int n;
int main(){
    scanf("%d",&n);
    int t1=0,t2=0,a,b;
    int ans=1;
    for (int x=0;x<n;x++){
        scanf("%d%d",&a,&b);
        if ((a==t1)&&(b==t2)) continue;
        ans+=max(0,min(a,b)-max(t1,t2)+1);
        if (t1==t2) ans--;
        t1=a,t2=b;
    }
    printf("%d\n",ans);
}