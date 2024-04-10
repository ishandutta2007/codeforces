#include <stdio.h>

using namespace std;

int main()
{
    int n, ans=0;
    scanf("%d", &n);
    for(int i=0; i < n; ++i){
        int k, a;
        scanf("%d%d", &k, &a);
        long long A=a, B=1;
        if(a == 1)
            ++k;
        while(B < A){
            B *= 4;
            ++k;
        }
        if(k > ans)
            ans=k;
    }
    printf("%d", ans);
    return 0;
}