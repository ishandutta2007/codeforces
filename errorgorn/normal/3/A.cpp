#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
int h,v;
int main(){
    h=getchar();
    v=getchar();
    getchar();
    h-=getchar();
    v-=getchar();
    printf("%d\n",max(abs(v),abs(h)));
    while (h!=0 || v!=0){
        if (h>0) putchar('L'),h--;
        else if (h<0) putchar('R'),h++;
        if (v>0) putchar('D'),v--;
        else if (v<0) putchar('U'),v++;
        putchar('\n');
    }
}