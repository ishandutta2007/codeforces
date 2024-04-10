#include <bits/stdc++.h>

#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

using namespace std;

int N, C, D;
pair<int, int> A[400000];
long long Z, ZO, ZOZ, O, OZ, OZO;

inline bool cmp(const pair<int, int>& a, const pair<int, int>& b)
{
    if((b.second<0)^(a.second<0))
        return 1LL*a.first*b.second>1LL*b.first*a.second;
    return 1LL*a.first*b.second<1LL*b.first*a.second;
}

inline bool eq(const pair<int, int>& a, const pair<int, int>& b)
{
    return 1LL*a.first*b.second==1LL*b.first*a.second;
}

int main()
{
    scan(N); scan(C); scan(D);
    for(int i=0; i<N; i++)
    {
        scan(A[i].first); scan(A[i].second);
        A[i].first-=C, A[i].second-=D;
    }
    sort(A, A+N, cmp);
    for(int i=0, j; i<N; i=j)
    {
        long long NZ=Z, NZO=ZO, NZOZ=ZOZ, NO=O, NOZ=OZ, NOZO=OZO;
        for(j=i; j<N && eq(A[i], A[j]); j++)
        {
            if(A[j].second<0)
            {
                NOZO+=OZ;
                NZO+=Z;
                NO++;
            }
            else
            {
                NZOZ+=ZO;
                NOZ+=O;
                NZ++;
            }
        }
        Z=NZ, ZO=NZO, ZOZ=NZOZ, O=NO, OZ=NOZ, OZO=NOZO;
    }
    int L=0, R=0, D=0;
    for(int i=0; i<N; i++) if(A[i].second==0)
    {
        if(A[i].first<0)
            L++;
        else
            R++;
    }
    for(int i=0; i<N; i++) if(A[i].second<0)
        D++;
    printf("%lld\n", OZO+ZOZ-1LL*L*R*D);
    return 0;
}