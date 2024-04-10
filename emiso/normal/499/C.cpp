#include <stdio.h>

int eq(int a,int b,int c,long long x,long long y) {
    if(x*a + y*b + c < 0) return -1;
    return 1;
}

int main() {     
    long long x1,x2,y1,y2;
    int n,a,b,c,co=0,i;
    scanf("%I64d %I64d %I64d %I64d %d",&x1,&y1,&x2,&y2,&n);
    for(i=0;i<n;i++) {
            scanf("%d %d %d",&a,&b,&c);
            if(eq(a,b,c,x1,y1) != eq(a,b,c,x2,y2)) co++;
    }
    printf("%d\n",co);
    return 0;
}