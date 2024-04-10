#include <bits/stdc++.h>

#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

using namespace std;

int N, Q;
int A[1000001];
int B[1000001];
int bit[1000001];
vector<pair<int, int>> q[1000001];
int ans[1000001];

void add(int x, int v)
{
    for(; x<=N; x+=x&-x)
        bit[x]^=v;
}

int sum(int x)
{
    int ret=0;
    for(; x>0; x-=x&-x)
        ret^=bit[x];
    return ret;
}

int main()
{
    scan(N);
    for(int i=1; i<=N; i++)
        scan(A[i]);
    for(int i=1; i<=N; i++)
        B[i]=B[i-1]^A[i];
    scan(Q);
    for(int i=0; i<Q; i++)
    {
        int a, b;
        scan(a); scan(b);
        ans[i]=B[a-1]^B[b];
        q[b].push_back({a-1, i});
    }
    map<int, int> last;
    int xs=0;
    for(int i=1; i<=N; i++)
    {
        if(last.count(A[i]))
            add(last[A[i]], A[i]);
        else
            xs^=A[i];
        add(i, A[i]);
        last[A[i]]=i;
        for(auto& it: q[i])
            ans[it.second]^=xs^sum(it.first);
    }
    for(int i=0; i<Q; i++)
        printf("%d\n", ans[i]);
    return 0;
}