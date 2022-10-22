#include <stdio.h>

using namespace std;

int main()
{
    int n, x;
    scanf("%d%d", &n, &x);
    for(int i=0; i < n; ++i){
        for(int j=0; j < 2; ++j){
            int a;
            scanf("%d", &a);
            if(a == x || a == 7-x){
                printf("NO");
                return 0;
            }
        }
    }
    printf("YES");
    return 0;
}