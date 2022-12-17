#include<iostream>
#include<algorithm>
using namespace std;

long long mod;
struct mat
{
    long long a[2][2];
};

mat mul(mat A,mat B)
{
    mat C;
    int i,j,k;
    for(i=0;i<2;i++)
        for(j=0;j<2;j++)
        {
            C.a[i][j]=0;
            for(k=0;k<2;k++)
                C.a[i][j]=(C.a[i][j]+A.a[i][k]*B.a[k][j])%mod;
        }
    return C;
}

long long get(long long n)
{
    if(n<=2) return 1%mod;
    n-=2;
    mat S,D;
    int i,j;
    for(i=0;i<2;i++)
        for(j=0;j<2;j++)
        {
            S.a[i][j]=D.a[i][j]=0;
            if(i==j) S.a[i][j]=1;
        }
    D.a[0][0]=D.a[0][1]=D.a[1][0]=1;
    while(n)
    {
        if(n&1) S=mul(S,D);
        n>>=1;
        D=mul(D,D);
    }
    return (S.a[0][0]+S.a[0][1])%mod;
}

int main()
{
    long long l,r,k,q,i,j;
    cin>>mod>>l>>r>>k;
    q=1;
    for(i=1;i*i<=r;i++)
    {
        if(r/i-(l-1)/i>=k) q=max(q,i);
        j=r/i;
        if(r/j-(l-1)/j>=k) q=max(q,j);
    }
    cout<<get(q)<<endl;
    return 0;
}