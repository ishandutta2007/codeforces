#include <iostream>
#include <cstdio>

#include <cassert>
#include <stack>
#include <utility>

using namespace std;

#define mp make_pair

typedef long long ll;
typedef pair<int, int> pii;

const int MAXN = 1010000;
const int MAXK = 1010000;
const ll MOD = 1000000007;
const int INF = 1010000000;

int N, K;
int A[MAXN];

int L[MAXN];        //inclusive
int R[MAXN];        //inclusive

void RL() {
    stack<pii> st;
    st.push(mp(INF, -1));
    
    for(int i = 0;i < N;i++) {
        while(A[i] > st.top().first) st.pop();
        L[i] = st.top().second + 1;
        st.push(mp(A[i], i));
    }
}
void RR() {
    stack<pii> st;
    st.push(mp(INF, N));
    
    for(int i = N - 1;i >= 0;i--) {
        while(A[i] >= st.top().first) st.pop();
        R[i] = st.top().second - 1;
        st.push(mp(A[i], i));
    }
}

int sum(int a, int b) {
    ll s = static_cast<ll> (a) + static_cast<ll> (b);
    return static_cast<int> (s%MOD);
}
void addto(int& a, int b) {
    a = sum(a, b);
}
int product(int a, int b) {
    ll p = static_cast<ll> (a) * static_cast<ll> (b);
    return static_cast<int> (p%MOD);
}

int nsum(int n) {
    if(n <= 0) return 0;
    
    int ret = 0;
    addto(ret, n);               //n
    int nn;
    if(n%2) nn = product(n, n/2 + 1);           //n(n + 1)/2
    else nn = product(n + 1, n/2);
    addto(ret, product(nn, K - 1));              //n(n + 1)(K - 1)/2
    return ret;
}


int main() {
    scanf("%d%d", &N, &K);
    
    for(int i = 0;i < N;i++) {
        scanf("%d", &A[i]);
    }
    
    RL();
    RR();
    
    
    int ans = 0;
    for(int i = 0;i < N;i++) {
        int l = i - L[i] + 1, r = R[i] - i + 1;
        if(l > r) swap(l, r);
        
        int n = (l - 1)/(K - 1);
        int m = (r - 1)/(K - 1);
        int p = (r + l - 2)/(K - 1);
        
        int ta = 0;
        
        assert(n <= m and m <= p);
        
        if(n > 0) {
            addto(ta, nsum(n));
        }
        if(m > n) {
            if(n > 0) addto(ta, product(m - n, l));
            else addto(ta, product(m, l));
        }
        if(p > m) {
            int pu = p;
            int pl = m > 0 ? m : 0;
            
            addto(ta, product(l + r, pu - pl));
            addto(ta, (nsum(pl) - nsum(pu) + MOD)%MOD);
        }
        
        addto(ans, product(ta, A[i]));
    }
    
    printf("%d\n", ans);
    
    return 0;
}