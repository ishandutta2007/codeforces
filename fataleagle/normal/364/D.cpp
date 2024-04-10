#include <bits/stdc++.h>

#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

#include <random>
std::default_random_engine random_engine(0xdeadbeef);
template<class T>
inline T randint(T L, T R) { return std::uniform_int_distribution<T>(L, R)(random_engine); }

using namespace std;

int N;
long long A[1000001];
long long ans=1;

void check(long long x)
{
    map<long long, int> _m;
    for(int i=0; i<N; i++)
        _m[__gcd(x, A[i])]++;
    vector<pair<long long, int>> m;
    for(auto& it: _m)
        m.push_back(it);
    auto checkf=[&](long long y) {
        int ret=0;
        for(auto& it: m) if(it.first%y==0)
            ret+=it.second;
        return ret;
    };
    vector<long long> checkv;
    for(long long i=1; i*i<=x; i++) if(x%i==0)
    {
        checkv.push_back(i);
        if(i*i!=x)
            checkv.push_back(x/i);
    }
    sort(checkv.rbegin(), checkv.rend());
    for(auto& it: checkv) if(ans<it && checkf(it)*2>=N)
    {
        ans=max(ans, it);
        break;
    }
}

int main()
{
    scan(N);
    for(int i=0; i<N; i++)
        scan(A[i]);
    for(int i=0; i<7; i++)
        check(A[randint(0, N-1)]);
    printf("%lld\n", ans);
    return 0;
}