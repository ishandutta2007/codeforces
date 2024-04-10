#include <bits/stdc++.h>

using namespace std;

int N;
long long A[100001];
long long X[100001];
long double bit[100001];

void upd(int x, long double v)
{
    for(; x<=N; x+=x&-x)
        bit[x]=max(bit[x], v);
}

long double ask(int x)
{
    long double ret=0.0;
    for(; x>0; x-=x&-x)
        ret=max(ret, bit[x]);
    return ret;
}

int main()
{
    scanf("%d", &N);
    for(int i=1; i<=N; i++)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        A[i]=1LL*a*a*b;
        X[i]=A[i];
    }
    sort(X+1, X+1+N);
    long double ans=0.0;
    for(int i=1; i<=N; i++)
    {
        int key=lower_bound(X+1, X+1+N, A[i])-X;
        long double v=ask(key-1)+A[i];
        ans=max(ans, v);
        upd(key, v);
    }
    ans*=acosl(-1.0);
    cout<<fixed<<setprecision(9)<<ans<<endl;
    return 0;
}