#include <stdio.h>
#include <cmath>
#include <algorithm>

using namespace std;

char types[11];
bool possible[1005][12][11];
int m;
int pre[1005][12][11][3];

int main()
{
    scanf("%s", types);
    scanf("%d", &m);
    for(int i=0; i < 11; ++i)
        for(int d=0; d <= 10; ++d)
            possible[0][i][d]=0;
    possible[0][0][0]=1;
    int best=0;
    int bestVal[3];
    for(int j=1; j <= m; ++j){
        for(int d=0; d <= 10; ++d)
            possible[j][0][d]=0;
        for(int i=1; i < 11; ++i)
            for(int d=0; d <= 10; ++d){
                possible[j][i][d]=0;
                if(types[i-1] == '0' || !d || d > i){
                    continue;
                }
                for(int k=0; k < 11; ++k){
                    if(!possible[j-1][k][i-d] || k == i)
                        continue;
                    possible[j][i][d]=1;
                    //printf("(%d,%d,%d)\n", j, i, d);
                    pre[j][i][d][0]=j-1;
                    pre[j][i][d][1]=k;
                    pre[j][i][d][2]=i-d;
                    best=j;
                    bestVal[0]=j;
                    bestVal[1]=i;
                    bestVal[2]=d;
                }
            }
    }
    if(best == m){
        printf("YES\n");
        int j=bestVal[0], i=bestVal[1], d=bestVal[2];
        int ansList[1005];
        ansList[j-1]=i;
        //printf("%d ", i);
        while(j > 1){
            int jp=pre[j][i][d][0], ip=pre[j][i][d][1], kp=pre[j][i][d][2];
            j=jp;
            i=ip;
            d=kp;
            //printf("%d ", i);
            ansList[j-1]=i;
        }
        for(int a=0; a < m; ++a)
            printf("%d ", ansList[a]);
    }
    else printf("NO\n");
    return 0;
}