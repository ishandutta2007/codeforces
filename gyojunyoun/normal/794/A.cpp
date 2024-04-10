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

int A, B, C;
int N, Ans;

int main() {
    for(scanf("%d%d%d%d", &A, &B, &C, &N); N--;) {
        int c; scanf("%d", &c);
        if(B < c && c < C) Ans++;
    }
    printf("%d\n", Ans);
    return 0;
}