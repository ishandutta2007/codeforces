#include <stdio.h>
using namespace std;
long long s[100001];
int main(){
    //freopen("tema.in","r",stdin);
    //freopen("tema.out","w",stdout);
    int n,i,x,nr=0;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%d",&x);
        s[i]=s[i-1]+x;
    }
    for(i=1;i<=n-1;i++)
        if(s[i]==s[n]-s[i])
            nr++;
    printf("%d",nr);
    return 0;
}