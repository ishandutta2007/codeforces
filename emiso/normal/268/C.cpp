#include <stdio.h>
#include <algorithm>

using namespace std;

int main() {
    int n,m,ans;
    scanf("%d %d",&n,&m);
    ans = min(n,m) + 1;
    printf("%d\n",ans);
    for(int i=0;i<ans;i++) printf("%d %d\n",ans-i-1,i);
    return 0;
}