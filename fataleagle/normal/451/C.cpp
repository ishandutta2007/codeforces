#include <bits/stdc++.h>

using namespace std;

long long N, K, A, B;

inline bool check(long long a, long long b, long long c)
{
    return a>=0 && b>=0 && c>=0 && a+b+c<=K && (K-(a+b+c))%3==0;
}

bool solve()
{
    if(N%3!=0)
        return false;
    if(check(0, A, A+B) && ((N-K)-((A+B)+(B)+(0)))%3==0 && (A+B)+(K-((0)+(A)+(A+B)))/3<=N/3)
        return true;
    if(check(0, A, A-B) && ((N-K)-((A)+(0)+(B)))%3==0 && (A)+(K-((0)+(A)+(A-B)))/3<=N/3)
        return true;
    if(check(A, 0, B) && B>=A && ((N-K)-((B-A)+(B)+(0)))%3==0 && (B)+(K-((A)+(0)+(B)))/3<=N/3)
        return true;
    if(check(A, 0, B) && A>=B && ((N-K)-((0)+(A)+(A-B)))%3==0 && (A)+(K-((A)+(0)+(B)))/3<=N/3)
        return true;
    if(check(B-A, B, 0) && ((N-K)-((A)+(0)+(B)))%3==0 && (B)+(K-((B-A)+(B)+(0)))/3<=N/3)
        return true;
    if(check(A+B, B, 0) && ((N-K)-((0)+(A)+(A+B)))%3==0 && (A+B)+(K-((A+B)+(B)+(0)))/3<=N/3)
        return true;
    return false;
}

int main()
{
    int T;
    scanf("%d", &T);
    for(int i=0; i<T; i++)
    {
        scanf("%lld%lld%lld%lld", &N, &K, &A, &B);
        if(solve())
            printf("yes\n");
        else
            printf("no\n");
    }
    return 0;
}