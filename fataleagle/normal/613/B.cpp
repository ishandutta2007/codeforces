#include <bits/stdc++.h>

using namespace std;

int N, MAX, cf, cm;
long long m;
int A[100000];
int order[100000];
int I[100000];
long long suf[100001];

int getMini()
{
    int lo=0, mid, hi=MAX;
    while(lo<hi)
    {
        mid=(lo+hi+1)/2;
        int pos=upper_bound(A, A+N, mid, greater<int>())-A;
        long long sum=1LL*(N-pos)*mid-suf[pos];
        if(sum<=m)
            lo=mid;
        else
            hi=mid-1;
    }
    return lo;
}

int main()
{
    scanf("%d%d%d%d%lld", &N, &MAX, &cf, &cm, &m);
    for(int i=0; i<N; i++)
        scanf("%d", A+i), order[i]=i;
    sort(order, order+N, [](const int a, const int b) {
        return A[a]>A[b];
    });
    for(int i=0; i<N; i++)
        I[order[i]]=i;
    sort(A, A+N, greater<int>());
    int perf=0;
    for(int i=0; i<N; i++)
    {
        if(A[i]==MAX)
            perf++;
    }
    suf[N]=0;
    for(int i=N-1; i>=0; i--)
        suf[i]=suf[i+1]+A[i];
    int idx=-1, mval=getMini();
    long long ans=1LL*perf*cf+1LL*mval*cm;
    for(int i=0; i<N; i++)
    {
        int cost=MAX-A[i];
        if(cost==0)
            continue;
        m-=cost;
        if(m<0)
            break;
        int lo=0, mid, hi=MAX;
        while(lo<hi)
        {
            mid=(lo+hi+1)/2;
            int pos=upper_bound(A+i+1, A+N, mid, greater<int>())-A;
            long long sum=1LL*(N-pos)*mid-suf[pos];
            if(sum<=m)
                lo=mid;
            else
                hi=mid-1;
        }
        long long val=1LL*(i+1)*cf+1LL*lo*cm;
        if(val>ans)
        {
            ans=val;
            idx=i;
            mval=lo;
        }
    }
    printf("%lld\n", ans);
    for(int i=0; i<=idx; i++)
        A[i]=MAX;
    for(int i=0; i<N; i++)
        A[i]=max(A[i], mval);
    for(int i=0; i<N; i++)
        printf("%d%c", A[I[i]], " \n"[i==N-1]);
    return 0;
}