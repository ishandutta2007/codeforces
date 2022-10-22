#include <stdio.h>

using namespace std;

int ans[105], l, n;

bool rec(int a, int pos){
    if(pos+1 == n){
        ans[pos]=a;
        if(a < 1 || a > l)
            return 0;
        return 1;
    }
    int b, c;
    if(a <= 0)
        b=1;
    else
        b=l;
    c=b-a;
    ans[pos]=b;
    return rec(c, pos+1);
}

int main()
{
    int last;
    scanf("%d%d%d", &n, &last, &l);
    if(rec(last, 0)){
        for(int i=0; i < n; ++i)
            printf("%d ", ans[i]);
    }
    else
        printf("-1");
    return 0;
}