#include <cstdio>
 
int N;
int main(void)
{
    scanf("%d" ,&N);
    for(int x;N;)
    {
        x = 31 - __builtin_clz(N);
        printf("%d ", x+1);
        N^=1<<x;
    }
    return 0;
}