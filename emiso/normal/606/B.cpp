#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>
#include <vector>
#include <math.h>
#include <stdlib.h>
#include <queue>

#define w1 while(1)
#define pint(n) printf("%d\n",n)
#define fill(n,m) memset(n,m,sizeof(n))

using namespace std;

int visit[505][505];

int main()
{
    int x0,x,y0,y,n,cnt=0;
    char s[100100];
    scanf("%d %d %d %d %s",&x,&y,&x0,&y0,s);
    int sz = strlen(s);
    for(int i=0;i<sz;i++) {
            //printf("s %c x %d y %d\n",s[i],x0,y0);
        if(!visit[x0][y0]) {
            visit[x0][y0]++;
            cnt++;
            printf("1 ");
        }
        else printf("0 ");
        if(s[i] == 'U')
            x0 = max(1,x0-1);
        else if(s[i] == 'D')
            x0 = min(x,x0+1);
        else if(s[i] == 'R')
            y0 = min(y,y0+1);
        else y0 = max(1,y0-1);
    }
    printf("%d\n",x*y-cnt);
    return 0;
}