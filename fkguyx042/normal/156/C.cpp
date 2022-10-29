#include <iostream>  
#include <stdio.h>  
#include <string.h>  
using namespace std;  
#define P 1000000007  
long long dp[110][2700];  
  
int main()  
{  
    memset(dp,0,sizeof(dp));  
    for(int i=0;i<26;i++)  
        dp[1][i]=1;  
    for(int i=2;i<=100;i++)  
    {  
        for(int j=0;j<=2600;j++)  
            for(int k=0;k<26;k++)  
                dp[i][j+k]=(dp[i][j+k]+dp[i-1][j])%P;  
    }  
    int t;  
    char ch[110];  
    cin >> t;  
    while(t--)  
    {  
        scanf("%s",ch);  
        int len = strlen(ch);  
        int sum = 0;  
        for(int i = 0;i < len;i++)  
            sum += ch[i]-'a';  
        cout << (dp[len][sum]+P -1)%P << "\n";;  
    }  
    return 0;  
}