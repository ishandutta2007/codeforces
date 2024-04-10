#include <bits/stdc++.h>

using namespace std;

int N, K, B, C;
int A[200000];
deque<int> V[5][5];
deque<long long> S[5][5];
long long sub[5][5];

long long check(int t)
{
    int k=t%5;
    int sum=0;
    for(int i=0; i<5; i++)
        sum+=V[k][i].size();
    if(sum<K)
        return 0x3f3f3f3f3f3f3f3fLL;
    while(sum>K)
    {
        long long maxi=-1;
        int idx=-1;
        for(int i=0; i<5; i++) if(!V[k][i].empty())
        {
            int x=V[k][i].front();
            int dc=((t-i)%5+5)%5;
            x+=dc;
            int db=(0LL+t-x)/5;
            long long val=1LL*C*dc+1LL*B*db;
            if(val>maxi)
                maxi=val, idx=i;
        }
        assert(idx!=-1);
        sub[k][idx]=S[k][idx].front();
        V[k][idx].pop_front();
        S[k][idx].pop_front();
        sum--;
    }
    long long ret=0;
    for(int i=0; i<5; i++) if(!V[k][i].empty())
    {
        int dc=(t%5-i+5)%5;
        int cnt=V[k][i].size();
        long long s=S[k][i].back();
        s-=sub[k][i];
        s=1LL*t*cnt-s;
        s-=dc*cnt;
        ret+=1LL*s/5*B;
        ret+=1LL*dc*cnt*C;
    }
    return ret;
}

#include <random>
std::default_random_engine random_engine(0xdeadbeef);
template<class T>
inline T randint(T L, T R) { return std::uniform_int_distribution<T>(L, R)(random_engine); }

int main()
{
    //freopen("in.txt", "r", stdin);
    scanf("%d%d%d%d", &N, &K, &B, &C);
    B=min(B, C*5);
    for(int i=0; i<N; i++)
        scanf("%d", A+i), A[i]+=1000000000;
    sort(A, A+N);
    long long ans=0x3f3f3f3f3f3f3f3fLL;
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<5; j++)
        {
            V[j][A[i]%5].push_back(A[i]);
            long long s=sub[j][A[i]%5];
            if(!S[j][A[i]%5].empty())
                s=S[j][A[i]%5].back();
            S[j][A[i]%5].push_back(s+A[i]);
        }
        for(int t=A[i]; t<A[i]+5; t++)
            ans=min(ans, check(t));
    }
    printf("%lld\n", ans);
    return 0;
}