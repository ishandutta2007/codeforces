#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

int N;
long long S;
pair<long long, long long> A[200001];
pair<long long, long long> upper[200002];
int nupper;

long double x_intersect(pair<long long, long long> a, pair<long long, long long> b)
{
    return (long double)(b.second-a.second)/(a.first-b.first);
}

pair<int, long long> find_line(long long y)
{
    int lo=1, mid, hi=nupper-1;
    while(lo<hi)
    {
        mid=(lo+hi+1)/2;
        long double m1=(long double)(y-upper[mid-1].second)/upper[mid-1].first;
        long double m2=(long double)(y-upper[mid].second)/upper[mid].first;
        if(m2<=m1)
            lo=mid;
        else
            hi=mid-1;
    }
    long long earliest=ceill((long double)(y-upper[lo].second)/upper[lo].first);
    lo=1;
    hi=nupper-1;
    while(lo<hi)
    {
        mid=(lo+hi+1)/2;
        if(x_intersect(upper[mid-1], upper[mid])<=earliest)
            lo=mid;
        else
            hi=mid-1;
    }
    return make_pair(lo, earliest);
}

int main()
{
    scanf("%d%lld", &N, &S);
    long long maxi=0;
    for(int i=0; i<N; i++)
    {
        scanf("%lld%lld", &A[i].first, &A[i].second);
        if(A[i].second==0)
            maxi=max(maxi, A[i].first);
    }
    A[N++]=make_pair(0x3f3f3f3f3f3f3f3fLL, S);
    sort(A, A+N);
    upper[nupper++]=make_pair(0, 0LL);
    upper[nupper++]=make_pair(maxi, 0LL);
    for(int i=0; i<N; i++)
    {
        if(A[i].first<=upper[nupper-1].first)
            continue;
        pair<int, long long> ret=find_line(A[i].second);
        int line=ret.first;
        long long x=ret.second;
        if(A[i].first==0x3f3f3f3f3f3f3f3fLL)
        {
            printf("%lld\n", x);
            break;
        }
        long long y=upper[line].first*x+upper[line].second-A[i].second;
        long long m=A[i].first;
        long long b=y-m*x;
        while(nupper>=2 && x_intersect(upper[nupper-2], upper[nupper-1])>=x_intersect(upper[nupper-2], make_pair(m, b)))
            nupper--;
        upper[nupper++]=make_pair(m, b);
    }
    return 0;
}