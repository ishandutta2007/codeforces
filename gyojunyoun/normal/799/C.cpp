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
#define MAXN (100005)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

vector<pii> VC, VD; // {cost, beauty}
int N, C, D;

inline int f(vector<pii>& V, const int& C) {
    if(sz(V) < 2) return 0;
    priority_queue<pii> PQ; // {beauty, idx}
    int ret = 0;
    for(int i = sz(V)-1, j = 0; 0 <= i; i--) {
        for(; j < sz(V) && V[i].first + V[j].first <= C; j++) PQ.push((pii){V[j].second, j});
        if(PQ.empty()) continue;
        const pii t = PQ.top();
        if(t.second != i) { upmax(ret, V[i].second + V[t.second].second); continue; }
        PQ.pop(); if(PQ.empty()) { PQ.push(t); continue; }
        upmax(ret, V[i].second + V[PQ.top().second].second);
        PQ.push(t);
    }
    return ret;
}
inline int g(vector<pii>& V, const int& C) {
    if(V.empty()) return 0;
    int ret = 0;
    for(int i = 0; i < sz(V); i++) {
        if(V[i].first <= C) upmax(ret, V[i].second);
    }
    return ret;
}
int main() {
    for(scanf("%d%d%d", &N, &C, &D); N--;) {
        int a, b; char c; scanf("%d%d %c", &a, &b, &c);
        if('C' == c && b <= C) VC.pb((pii){b, a});
        if('D' == c && b <= D) VD.pb((pii){b, a});
    } 
    sort(allv(VC)); sort(allv(VD));

    int Ans = 0;
    int tmp1 = g(VC, C), tmp2 = g(VD, D);
    if(tmp1 && tmp2) upmax(Ans, tmp1+tmp2);
    tmp1 = f(VC, C); upmax(Ans, tmp1);
    tmp2 = f(VD, D); upmax(Ans, tmp2);
    printf("%d\n", Ans);
    return 0;
}