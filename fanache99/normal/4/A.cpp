#include <stdio.h>
using namespace std;
int main(){
    //freopen("arrows.in","r",stdin);
    //freopen("arrows.out","w",stdout);
    int n;
    scanf("%d",&n);
    if(n%2==1)
        printf("NO");
    else
        if(n==2)
            printf("NO");
        else
            printf("YES");
    return 0;
}