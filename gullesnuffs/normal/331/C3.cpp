#include <stdio.h>
#include <algorithm>
typedef long long Int;

using namespace std;

long long n;
//Exponent, starting at 10^x-y, largest previous digit
pair<long long, int> dp[20][15][15];

int main(){
    scanf("%I64d", &n);
    if(!n){
        printf("0\n");
        return 0;
    }
    if(n < 10){
        printf("1\n");
        return 0;
    }
    for(int i=1; i < 11; ++i)
        for(int j=0; j < 10; ++j){
            if(j > 10-i)
                dp[1][i][j]=make_pair(1, j+i-10);
            else
                dp[1][i][j]=make_pair(2, j);
        }
    for(int x=2; x < 20; ++x)
        for(int i=1; i < 11; ++i)
            for(int j=1; j < 10; ++j){
                int a=i;
                long long moveN=0;
                int digit=9;
                while(digit >= 0){
                    pair<long long, int> p=dp[x-1][a][max(digit, j)];
                    moveN += p.first;
                    int ap=p.second;
                    --digit;
                    a=ap;
                }
                dp[x][i][j]=make_pair(moveN, a);
            }
    long long ans=0;
    if(n == 1000000000000000000L){
        ++ans;
        n=999999999999999999L;
    }
    long long Pow[19];
    Pow[0]=1;
    for(int i=1; i < 19; ++i)
        Pow[i]=Pow[i-1]*10;
    while(n >= 10){
        int i;
        for(i=1; i < 18 && (n%(10*Pow[i]))/Pow[i] == 9; ++i);
        long long a=Pow[i]-(n%Pow[i]);
        long long maxDigit=1;
        for(int j=i; j < 18; ++j){
            if((n%(10*Pow[j]))/Pow[j] > maxDigit)
                maxDigit=(n%(10*Pow[j]))/Pow[j];
        }
        pair<long long, int> p=dp[i][a][maxDigit];
        ans += p.first;
        n -= n%Pow[i]+p.second;
    }
    if(n > 0)
        ++ans;
    if(n < 0)
        --ans;
    printf("%I64d\n", ans);
    return 0;
}