#include <bits/stdc++.h>
using namespace std;

#define error(args...) { vector<string> _v = split(#args, ','); err(_v.begin(), args); }
vector<string> split(const string& s, char c) { vector<string> v; stringstream ss(s); string x; while (getline(ss, x, c)) v.push_back(move(x)); return v; }
void err(vector<string>::iterator it) {}
template<typename T, typename... Args> void err(vector<string>::iterator it, T a, Args... args) { cerr << it->substr((*it)[0] == ' ', it->length()) << " = " << a << '\n'; err(++it, args...); }

typedef long long LL;
const LL INF = 1e12;
#define MAXN 100013
#define MAXK 21
int N, K;
int A[MAXN];
LL dp[MAXK][MAXN];
LL ct[MAXN];
int cs = 0, ce = -1;
LL cc = 0;

inline LL c2(LL amt) { return amt * (amt - 1) / 2; }
inline void incs() { int x = A[cs++]; cc -= c2(ct[x]); cc += c2(--ct[x]); }
inline void dece() { int x = A[ce--]; cc -= c2(ct[x]); cc += c2(--ct[x]); }
inline void decs() { int x = A[--cs]; cc -= c2(ct[x]); cc += c2(++ct[x]); }
inline void ince() { int x = A[++ce]; cc -= c2(ct[x]); cc += c2(++ct[x]); }
inline void mve(int e) { while (ce > e) dece(); while (ce < e) ince(); }
inline void mvs(int s) { while (cs > s) decs(); while (cs < s) incs(); }

void go(int k, int s, int e, int lo, int hi) {
    if (s > e) return;
    int mid = (s + e) / 2;
    mve(mid - 1);
    dp[k][mid] = INF;
    int pos = -1;
    // kth interval: [i..mid-1]
    for (int i = lo; i <= mid && i <= hi; i++) {
        mvs(i);
        if (dp[k - 1][i] + cc < dp[k][mid]) {
            dp[k][mid] = dp[k - 1][i] + cc;
            pos = i;
        }
    }
    go(k, s, mid - 1, lo, pos);
    go(k, mid + 1, e, pos, hi);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    
    dp[0][0] = 0;
    for (int i = 1; i <= N; i++)
        dp[0][i] = INF;
    
    for (int k = 1; k <= K; k++) {
        // ct should be all 0's before this
        go(k, 0, N, 0, N - 1);
    }
    
    cout << dp[K][N] << endl;
    return 0;
}