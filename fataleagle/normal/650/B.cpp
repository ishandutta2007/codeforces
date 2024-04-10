#include <bits/stdc++.h>

using namespace std;

int N, A, B, T;
char S[500001];
int C[500001];
long long P[500001];

int main()
{
    scanf("%d%d%d%d", &N, &A, &B, &T);
    scanf("%s", S);
    for(int i=0; i<N; i++)
        C[i]=(S[i]=='w')*B+1;
    int ans=0;
    for(int t=0; t<2; t++)
    {
        P[0]=C[0];
        for(int i=1; i<N; i++)
            P[i]=P[i-1]+C[i];
        long long cost=0;
        for(int i=N; i>=1; i--)
        {
            if(i<N)
                cost+=2*A+C[i];
            if(cost+C[0]>T)
                break;
            int lo=0, mid, hi=i-1;
            while(lo<hi)
            {
                mid=(lo+hi+1)/2;
                if(cost+1LL*mid*A+P[mid]<=T)
                    lo=mid;
                else
                    hi=mid-1;
            }
            ans=max(ans, N-i+lo+1);
        }
        reverse(C+1, C+N);
    }
    printf("%d\n", ans);
    return 0;
}