#include <bits/stdc++.h>

using namespace std;

const int MAXN=10000000;
bool prime[MAXN];
int pi[MAXN];
int rub[MAXN];

int main()
{
    memset(prime, 1, sizeof prime);
    prime[0]=prime[1]=false;
    for(int i=2; i<MAXN; i++)
    {
        pi[i]=pi[i-1];
        if(prime[i])
        {
            pi[i]++;
            for(long long j=1LL*i*i; j<MAXN; j+=i)
                prime[j]=false;
        }
    }
    for(int i=1; i<MAXN; i++)
    {
        int n=i, m=0;
        while(n)
        {
            m*=10;
            m+=n%10;
            n/=10;
        }
        rub[i]=rub[i-1];
        if(i==m)
            rub[i]++;
    }
    int p, q;
    scanf("%d%d", &p, &q);
    int ans=0;
    for(int i=0; i<MAXN; i++)
        if(1LL*q*pi[i]<=1LL*p*rub[i])
            ans=i;
    if(ans==0)
        printf("Palindromic tree is better than splay tree\n");
    else
        printf("%d\n", ans);
    return 0;
}