#include <stdio.h>

using namespace std;

int plantN, speciesN;
int species[5005], dp[5005][5005];

int main()
{
    scanf("%d%d", &plantN, &speciesN);
    for(int i=0; i < plantN; ++i){
        double t;
        scanf("%d%lf", species+i, &t);
    }
    for(int i=0; i <= plantN; ++i)
        for(int j=0; j < speciesN; ++j)
            dp[i][j]=plantN;
    for(int j=0; j < speciesN; ++j)
        dp[0][j]=0;
    for(int i=1; i <= plantN; ++i){
        for(int j=0; j < speciesN; ++j){
            if(j > 0)
                dp[i][j]=dp[i][j-1];
            else
                dp[i][j]=plantN;
            if(dp[i-1][j]+1 < dp[i][j])
                dp[i][j]=dp[i-1][j]+1;
            if(species[i-1] == j+1 && dp[i-1][j] < dp[i][j])
                dp[i][j]=dp[i-1][j];
        }
    }
    printf("%d", dp[plantN][speciesN-1]);
    return 0;
}