#include <iostream>
#include <cstdio>

using namespace std;

const int MOD=1000000007;
const long long MODSQ=1LL*MOD*MOD;
int W[8];
int dp[1<<7][1<<7][8][2];

struct matrix
{
    int sz;
    int data[1<<7][1<<7];
};

matrix multiply(matrix& a, matrix& b)
{
    matrix c;
    c.sz=a.sz;
    for(int i=0; i<c.sz; i++)
        for(int j=0; j<c.sz; j++)
        {
            long long sum=0;
            for(int k=0; k<c.sz; k++)
            {
                sum+=1LL*a.data[i][k]*b.data[k][j];
                if(sum>=MODSQ)
                    sum-=MODSQ;
            }
            c.data[i][j]=sum%MOD;
        }
    return c;
}

matrix pow(matrix b, int e)
{
    if(e==1)
        return b;
    matrix ret=pow(multiply(b, b), e/2);
    if(e&1)
        return multiply(ret, b);
    return ret;
}

matrix transition_matrix(int sz)
{
    matrix ret;
    ret.sz=1<<sz;
    for(int i=0; i<(1<<sz); i++)
        for(int j=0; j<(1<<sz); j++)
            ret.data[i][j]=dp[i][j][sz][1];
    return ret;
}

int main()
{
    for(int i=0; i<(1<<7); i++)
        for(int j=0; j<(1<<7); j++)
        {
            dp[i][j][0][0]=0;
            dp[i][j][0][1]=1;
            for(int k=0; k<7; k++)
            {
                dp[i][j][k+1][0]=dp[i][j][k][0]+dp[i][j][k][1];
                dp[i][j][k+1][1]=dp[i][j][k][0];
                if(!(((i>>k)&1) && ((j>>k)&1)))
                    dp[i][j][k+1][1]+=dp[i][j][k][1];
            }
        }
    int last=0;
    for(int i=1; i<=7; i++)
    {
        scanf("%d", W+i);
        if(W[i])
            last=i;
    }
    matrix pre, base, tmp;
    int psz=-1;
    for(int i=1; i<=last; i++)
        if(W[i])
        {
            base.sz=1<<i;
            if(psz==-1)
            {
                for(int j=0; j<(1<<i); j++)
                    base.data[j][0]=0;
                base.data[(1<<i)-1][0]=1;
            }
            else
            {
                for(int j=0; j<(1<<i); j++)
                {
                    if((j>>psz)==(1<<(i-psz))-1)
                        base.data[j][0]=pre.data[j&((1<<psz)-1)][0];
                    else
                        base.data[j][0]=0;
                }
            }
            tmp=pow(transition_matrix(i), W[i]);
            pre=multiply(tmp, base);
            psz=i;
        }
    printf("%d\n", pre.data[(1<<last)-1][0]);
    return 0;
}