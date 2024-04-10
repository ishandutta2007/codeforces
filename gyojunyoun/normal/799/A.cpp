#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <deque>
#include <queue>
#include <set>
#define pb push_back
#define sz(V) ((int)(V).size())
#define allv(V) ((V).begin()),((V).end())
#define befv(V) ((V)[(sz(V)-2)])
#define upmin(ans,ansx) (ans)=min((ans),(ansx))
#define upmax(ans,ansx) (ans)=max((ans),(ansx))
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int N, T, K, D;
int t;

int main() {
    scanf("%d%d%d%d", &N, &T, &K, &D);
    t = (N+K-1)/K * T;
    if(t <= D) { puts("NO"); return 0; }
    int sex = (t-1)/T * K + (t-D-1)/T * K;
    if(N <= sex) puts("YES"); else puts("NO");
    return 0;

}