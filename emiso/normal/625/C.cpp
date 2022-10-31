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

int l,r,n,k,ans,table[505][505];

int main()
{
    scanf("%d %d",&n,&k);
    l = 1; r = n*n;

    for(int i=1;i<=n;i++) {
        for(int j=1;j<k;j++) {
            table[i][j] = l;
            l++;
        }
        for(int j=n;j>=k;j--) {
            table[i][j] = r;
            r--;
        }
        ans += table[i][k];
    }

    printf("%d\n",ans);
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++) {
            printf("%d%c",table[i][j],(j==n)?'\n':' ');
        }
    }

    return 0;
}