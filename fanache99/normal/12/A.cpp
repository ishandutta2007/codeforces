#include<stdio.h>
using namespace std;
int main(){
    //freopen("tema.in","r",stdin);
    //freopen("tema.out","w",stdout);
    char c1,c2,c3,c4,c5,c6,c7,c8,c9;
    scanf("%c%c%c\n%c%c%c\n%c%c%c",&c1,&c2,&c3,&c4,&c5,&c6,&c7,&c8,&c9);
    if(c1==c9&&c2==c8&&c3==c7&&c4==c6)
        printf("YES");
    else
        printf("NO");
    return 0;
}