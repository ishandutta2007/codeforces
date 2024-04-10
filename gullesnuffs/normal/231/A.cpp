#include <stdio.h>

using namespace std;
int main()
{
    int n, s=0;
    scanf("%d", &n);
    for(int i=0; i < n; ++i){
        int a, b, c, t;
        scanf("%d%d%d", &a, &b, &c);
        t=a+b+c;
        if(t >= 2)
            ++s;
    }
    printf("%d", s);
    return 0;
}