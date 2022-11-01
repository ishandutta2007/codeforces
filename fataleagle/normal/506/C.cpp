#include <iostream>
#include <cstdio>

using namespace std;

int N, M, K, P;
int H[100000];
int A[100000];
int hammer[5002];

bool solve(long long maxh)
{
    for(int i=0; i<=M+1; i++)
        hammer[i]=0;
    long long tot=0;
    for(int i=0; i<N; i++)
    {
        long long need=H[i]+1LL*M*A[i]-maxh;
        if(need<=0)
            continue;
        long long hammers=(need+P-1)/P;
        tot+=hammers;
        if(tot>M*K)
            return false;
        int tmp=0;
        while(hammers>0)
        {
            int lo=0, mid, hi=M;
            while(lo<hi)
            {
                mid=(lo+hi)/2;
                if(max(H[i]+1LL*mid*A[i]-hammers*P, 0LL)+1LL*(M-mid)*A[i]-1LL*tmp*P>maxh)
                    lo=mid+1;
                else
                    hi=mid;
            }
            hammer[lo+1]++;
            tmp++;
            hammers--;
        }
    }
    if(hammer[M+1]>0)
        return false;
    int num=0;
    for(int i=0; i<=M; i++)
        num=max(num+hammer[i]-K, 0);
    return num==0;
}

int main()
{
    scanf("%d%d%d%d", &N, &M, &K, &P);
    long long lo=0, mid, hi=0;
    for(int i=0; i<N; i++)
        scanf("%d%d", H+i, A+i), hi=max(hi, H[i]+1LL*M*A[i]);
    while(lo<hi)
    {
        mid=(lo+hi)/2;
        if(solve(mid))
            hi=mid;
        else
            lo=mid+1;
    }
    printf("%lld\n", lo);
    return 0;
}