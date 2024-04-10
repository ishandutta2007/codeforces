#include <iostream>
#include <cstdio>

#include <utility>
#include <queue>
#include <algorithm>

using namespace std;

const int MAXN = 1500 + 100;
const int MAXM = 1500 + 100;
const int MAXS = 1500 + 100;

int N, S, M, K;

int a[MAXN];

typedef pair<int, int> pii;
#define mp make_pair

pii s[MAXN];

typedef deque<pii> dpii;
int psum[MAXN];
int dp[MAXS][MAXM];
dpii dp2[MAXM];
int dp3[MAXN][MAXM];

void rpl(int& a, const int& b) {
    if(a < b) a = b;
}
void add(dpii& q, const pii& v) {
    while(!q.empty() and q.back().first < v.first) q.pop_back();
    q.push_back(v);
}
bool solve(const int& v) {
    psum[0] = 0;
    for(int i = 1;i <= N;i++) psum[i] = psum[i-1]+(a[i]<=v);
    for(int i = 0;i <= M;i++) dp2[i].clear();
    for(int i = 0;i <= S;i++) for(int j = 0;j <= M;j++) dp[i][j] = 0;
    for(int i = 0;i <= N;i++) for(int j = 0;j <= M;j++) dp3[i][j] = 0;
    
    for(int i = 0, p = 1, cp;i < S;i++) {
        cp = s[i].first;
        for(int j = 0;j <= M;j++) {
            while(!dp2[j].empty() and dp2[j].front().second < cp) {
                rpl(dp3[dp2[j].front().second][j], dp2[j].front().first + psum[dp2[j].front().second]);
                dp2[j].pop_front();
            }
            for(int k = p;k < cp;k++) rpl(dp3[k][j], dp3[k-1][j]);
        }
        for(int j = 0;j <= M;j++) {
            if(j and !dp2[j-1].empty()) dp[i][j] = dp2[j-1].front().first + psum[s[i].second];
            if(j) rpl(dp[i][j], dp3[cp-1][j-1] + psum[s[i].second] - psum[s[i].first-1]);
            
            //printf("dp[%d][%d] = %d\n", i, j, dp[i][j]);
            if(dp[i][j] >= K) return true;
            
            add(dp2[j], mp(dp[i][j] - psum[s[i].second], s[i].second));
        }
        p = cp;
    }
    return false;
}

int v[MAXN], vs;

int main() {
    scanf("%d%d%d%d", &N, &S, &M, &K);
    for(int i = 1;i <= N;i++) scanf("%d", a + i), v[i-1] = a[i];
    
    for(int i = 0;i < S;i++) scanf("%d%d", &s[i].first, &s[i].second);
    sort(s, s + S, [](const pii& a, const pii& b) {return a.first < b.first or (not (b.first < a.first) and a.second > b.second);});
    
    for(int i = 0, o = 0;i < S;i++) {
        s[i] = s[i + o];
        while(i + 1 < S and s[i].first == s[i + o + 1].first) S--, o++;
    }
    if(M > S) M = S;
    
    sort(v, v + N);
    vs = unique(v, v + N) - v;
    
    int l = -1, h = vs;
    while(h > l + 1) {
        int m = l + ((h-l)>>1);
        if(solve(v[m])) h = m;
        else l = m;
    }
    if(h < vs) printf("%d\n", v[h]); else printf("-1\n");
    
    return 0;
}