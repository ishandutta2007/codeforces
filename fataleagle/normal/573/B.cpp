#include <bits/stdc++.h>

#include <random>
std::default_random_engine random_engine(0xdeadbeef);
template<class T>
inline T randint(T L, T R) { return std::uniform_int_distribution<T>(L, R)(random_engine); }

using namespace std;

int N;
int A[200005];
pair<int, int> B[200005];
int T[200005];

int main()
{
    scanf("%d", &N);
    for(int i=1; i<=N; i++)
    {
        scanf("%d", A+i);
        B[i]=make_pair(A[i], i);
    }
    sort(B+1, B+1+N);
    set<pair<int, int>> S;
    S.insert(make_pair(0, 0));
    S.insert(make_pair(N+1, 0));
    for(int i=1; i<=N; i++)
    {
        int x=B[i].second;
        auto it=S.lower_bound(make_pair(x, -1));
        auto it2=--S.lower_bound(make_pair(x, -1));
        T[x]=min(B[i].first, min(it2->second+(x-it2->first), it->second+(it->first-x)));
        S.insert(make_pair(x, T[x]));
    }
    int ans=0;
    for(int i=1; i<=N; i++)
        ans=max(ans, T[i]);
    printf("%d\n", ans);
    return 0;
}