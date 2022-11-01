#include <bits/stdc++.h>

using namespace std;

const int MOD=1000000007;
int N, X;
int A[101];
int dp[1001];

struct matrix
{
    int data[101][101];
};

matrix multiply(matrix a, matrix b)
{
    matrix c;
    for(int i=0; i<=100; i++)
        for(int j=0; j<=100; j++)
        {
            c.data[i][j]=0;
            for(int k=0; k<=100; k++)
                c.data[i][j]=(c.data[i][j]+1LL*a.data[i][k]*b.data[k][j])%MOD;
        }
    return c;
}

matrix pow(matrix a, int b)
{
    matrix ret;
    for(int i=0; i<=100; i++)
        for(int j=0; j<=100; j++)
            ret.data[i][j]=i==j;
    while(b)
    {
        if(b&1)
            ret=multiply(ret, a);
        a=multiply(a, a);
        b/=2;
    }
    return ret;
}

int main()
{
    scanf("%d%d", &N, &X);
    int a;
    for(int i=0; i<N; i++)
    {
        scanf("%d", &a);
        A[a]++;
    }
    matrix trans;
    for(int i=0; i<=100; i++)
        for(int j=0; j<=100; j++)
            trans.data[i][j]=0;
    trans.data[0][0]=trans.data[0][100]=1;
    for(int i=1; i<100; i++)
        trans.data[i][i+1]=1;
    for(int i=1; i<=100; i++)
        trans.data[100][100-i+1]=A[i];
    matrix base;
    for(int i=0; i<=100; i++)
        for(int j=0; j<=100; j++)
            base.data[i][j]=0;
    dp[0]=1;
    for(int i=1; i<=1000; i++)
        for(int j=1; j<=100; j++)
            if(i>=j)
                dp[i]=(dp[i]+1LL*dp[i-j]*A[j])%MOD;
    for(int i=1; i<=100; i++)
        base.data[i][0]=dp[i];
    for(int i=0; i<100; i++)
        base.data[0][0]=(base.data[0][0]+dp[i])%MOD;
    if(X<=1000)
    {
        int ans=0;
        for(int i=0; i<=X; i++)
            ans=(ans+dp[i])%MOD;
        printf("%d\n", ans);
        return 0;
    }
    matrix ans=multiply(pow(trans, X-99), base);
    printf("%d\n", ans.data[0][0]);
    return 0;
}