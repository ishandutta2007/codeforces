#include <stdio.h>

#define T16 (1<<16)

using namespace std;

int c[20][50],ans,n,t;

void fill_(int x, int y, int quant) {
    if(x == n) return;

    if(c[x][y] < T16) {
        if(c[x][y] + quant >= T16) {
            ans++;
            quant -= (T16 - c[x][y]);
            c[x][y] = T16;
        }
        else c[x][y] += quant;
    }

    if(c[x][y] >= T16) {
        fill_(x+1,y-1,quant/2);
        fill_(x+1,y+1,quant/2);
    }
}

int main()
{
    scanf("%d %d",&n,&t);
    for(int i=1;i<=t;i++) {
        fill_(0,30,T16);
        if(ans >= n*(n+1)/2) {
            ans = n*(n+1)/2;
            break;
        }
    }
    printf("%d\n",ans);
    return 0;
}