#include <bits/stdc++.h>

#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

using namespace std;

int N, K;
int A[300001];
int cnt1[1000005];
int cnt2[1000005];
long long ans=0;

struct info
{
    int type, s, m;
    bool operator< (const info& other) const
    {
        if(m==other.m)
            return type<other.type;
        return m<other.m;
    }
} V[300000];

void solve(int l, int r)
{
    if(l==r)
        return;
    int m=(l+r)/2;
    int sum=0, maxi=0;
    int n=0;
    for(int i=m; i>=l; i--)
    {
        sum=(sum+A[i])%K;
        maxi=max(maxi, A[i]);
        V[n++]=(info){0, sum, maxi};
    }
    sum=maxi=0;
    for(int i=m+1; i<=r; i++)
    {
        sum=(sum+A[i])%K;
        maxi=max(maxi, A[i]);
        V[n++]=(info){1, sum, maxi};
    }
    sort(V, V+n);
    for(int i=0; i<n; i++)
    {
        if(V[i].type==0)
        {
            cnt1[V[i].s]++;
            ans+=cnt2[(K-((V[i].s-V[i].m+K)%K))%K];
        }
        else
        {
            cnt2[V[i].s]++;
            ans+=cnt1[(K-((V[i].s-V[i].m+K)%K))%K];
        }
    }
    for(int i=0; i<n; i++)
    {
        if(V[i].type==0)
            cnt1[V[i].s]--;
        else
            cnt2[V[i].s]--;
    }
    solve(l, m);
    solve(m+1, r);
}

int main()
{
    scan(N);
    scan(K);
    for(int i=1; i<=N; i++)
        scan(A[i]);
    solve(1, N);
    cout<<ans<<endl;
    return 0;
}