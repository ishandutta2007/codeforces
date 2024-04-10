#include <stdio.h>
#define MAXN 101

using namespace std;

bool filled[MAXN][2];

int getNim(int len, int a, int b){
    if((a+b)%2){
        if(a+b == 1)
            return len+1;
        else
            return len;
    }
    return (len+2)%2;
}

int main()
{
    int r, n;
    int a, b;
    a=1;
    scanf("%d%d", &r, &n);
    for(int i=0; i < n; ++i){
        int x, y;
        scanf("%d%d", &x, &y);
        filled[x-1][y-1]=1;
    }
    int ans=0;
    int from=0;
    for(int i=0; i < r; ++i){
        if(filled[i][0]){
            b=2;
            ans^=getNim(i-from, a, b);
            from=i+1;
            a=2;
        }
        else if(filled[i][1]){
            b=0;
            ans^=getNim(i-1-from, a, b);
            from=i+2;
            a=0;
        }
    }
    if(r-from >= 0)
        ans^=getNim(r-from, a, 1);
    if(ans)
        printf("WIN\n");
    else
        printf("LOSE");
    return 0;
}