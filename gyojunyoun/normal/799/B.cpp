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
#define MAXN (200005)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

set<pii> SA[4], SB[4];
int P[MAXN], A[MAXN], B[MAXN];
int N, M;

int main() {
    scanf("%d", &N);
    for(int i = 0; i < N; i++) scanf("%d", &P[i]);
    for(int i = 0; i < N; i++) scanf("%d", &A[i]);
    for(int i = 0; i < N; i++) scanf("%d", &B[i]);
    for(int i = 0; i < N; i++) {
        SA[A[i]].insert((pii){P[i], i});
        SB[B[i]].insert((pii){P[i], i});
    }
    for(scanf("%d", &M); M--;) {
        int c; scanf("%d", &c);
        int hubop = 2147483647, huboidx = -1;
        if(!SA[c].empty()) {
            const pii t = *SA[c].begin();
            if(t.first < hubop) {
                hubop = t.first; huboidx = t.second;
            }
        }
        if(!SB[c].empty()) {
            const pii t = *SB[c].begin();
            if(t.first < hubop) {
                hubop = t.first; huboidx = t.second;
            }
        }
        if(-1 == huboidx) printf("-1 ");
        else {
            printf("%d ", hubop);
            SA[A[huboidx]].erase((pii){P[huboidx], huboidx});
            SB[B[huboidx]].erase((pii){P[huboidx], huboidx});
        }
    }
    return 0;
}