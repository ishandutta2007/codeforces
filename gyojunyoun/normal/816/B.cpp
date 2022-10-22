#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <unordered_map>
#include <bitset>
#include <string>
#define pb push_back
#define sz(V) ((int)(V).size())
#define allv(V) ((V).begin()),((V).end())
#define befv(V) ((V)[(sz(V)-2)])
#define sorv(V) sort(allv(V))
#define univ(V) (V).erase(unique(allv(V)),(V).end())
#define upmin(a,b) (a)=min((a),(b))
#define upmax(a,b) (a)=max((a),(b))
#define INF (1100000099)
#define INFLL (1100000000000000099ll)
#define MAXN (200005)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<int, ll> pil;
typedef pair<ll, int> pli;

int S[MAXN];
int A[MAXN];
int N, K, Q;

int main() {
    for(scanf("%d%d%d", &N, &K, &Q); N--;) {
        int l, r; scanf("%d%d", &l, &r); S[l]++; S[r+1]--;
    }
    for(int i = 1; i < MAXN; i++) S[i] += S[i-1];
    for(int i = 1; i < MAXN; i++) if(K <= S[i]) A[i]++;
    for(int i = 1; i < MAXN; i++) A[i] += A[i-1];
    for(int s, e; Q--;) {
        scanf("%d%d", &s, &e);
        printf("%d\n", A[e] - A[s-1]);
    }
    return 0;
}