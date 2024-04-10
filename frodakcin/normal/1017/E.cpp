#include <iostream>
#include <cstdio>

#include <utility>
#include <cmath>
#include <algorithm>

using namespace std;

#define mp make_pair

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ld, ll> pdi;

const int MAXN = 101000;
const int MAXM = 101000;

const ld EPS = 1e-10;

inline bool operator == (const pdi& a, const pdi& b) {
    return a.second == b.second and abs(a.first - b.first) < EPS;
}
inline bool operator != (const pdi& a, const pdi& b) {
    return a.second != b.second or abs(a.first - b.first) > EPS;
}
inline pii operator + (const pii& a, const pii& b) {
    return mp(a.first + b.first, a.second + b.second);
}
inline pii operator - (const pii& a, const pii& b) {
    return mp(a.first - b.first, a.second - b.second);
}


int N, M;

//GEOMETRY: CONVEX HULL
pii eg1[MAXN], eg2[MAXM];
int chl1, chl2;
int ch1[MAXN], ch2[MAXN];

ll dist(const pii& a, const pii& b) {return (static_cast<ll> (a.first) - b.first)*(static_cast<ll> (a.first) - b.first) + (static_cast<ll> (a.second) - b.second)*(static_cast<ll> (a.second) - b.second);}
ll det(const pii& a, const pii& b) {return static_cast<ll> (a.second) * b.first - static_cast<ll> (a.first) * b.second;}
ll dot(const pii& a, const pii& b) {return static_cast<ll> (a.first) * b.first + static_cast<ll> (a.second) * b.second;}
ld mag(const pii& a) {return sqrt(static_cast<ld> (dot(a, a)));}
ld angle(const pii& a, const pii& b) {return (det(a, b) < 0 ? -1.0 : 1.0) * acos(static_cast<ll> (dot(a, b)) / (mag(a) * mag(b)));}

void genCVH(pii * points, int plen, int * ch, int &chl) {
    sort(points, points+plen);
    chl = 0;
    bool u[plen];
    for(int i = 0;i < plen;i++) {
        while(chl >= 2 and det(points[ch[chl - 1]] - points[ch[chl - 2]], points[i] - points[ch[chl - 1]]) <= 0) u[ch[--chl]] = false;
        ch[chl++] = i;
        u[i] = true;
    }
    int cf = chl;
    for(int i = plen - 1;i >= 0;i--) {
        if(u[i]) continue;
        while(chl > cf and det(points[ch[chl - 1]] - points[ch[chl - 2]], points[i] - points[ch[chl - 1]]) <= 0) chl--;
        ch[chl++] = i;
    }
    while(chl > 2 and det(points[ch[chl - 1]] - points[ch[chl - 2]], points[0] - points[ch[chl - 1]]) <= 0) chl--;
}

//STRING MATCHING
pdi A[MAXN * 2];
pdi B[MAXM];
int fail[MAXM];

void initfail() {
    fail[0] = -1;
    int pl = -1;
    for(int i = 1;i < chl2;i++) {
        while(pl != -1 and B[i] != B[pl + 1]) pl = fail[pl];
        if(B[i] == B[pl + 1]) pl++;
        fail[i] = pl;
    }
}
bool dokmp() {
    int j = -1;
    for(int k = 0;k < 2;k++)
        for(int i = 0;i < chl1;i++) {
            while(j != -1 && A[i] != B[j + 1]) j = fail[j];
            if(A[i] == B[j + 1]) j++;
            if(j >= chl1 - 1) return true;
        }
    return false;
}

int main() {
    
    scanf("%d%d", &N, &M);
    for(int i = 0;i < N;i++) {
        scanf("%d%d", &eg1[i].first, &eg1[i].second);
    }
    for(int i = 0;i < M;i++) {
        scanf("%d%d", &eg2[i].first, &eg2[i].second);
    }
    
    genCVH(eg1, N, ch1, chl1);
    genCVH(eg2, M, ch2, chl2);
    
    if(chl1 != chl2) {
        printf("NO\n");
        return 0;
    }
    if(chl1 == 1) {
        printf("YES\n");
        return 0;
    }
    if(chl1 == 2) {
        if(dist(eg1[ch1[0]], eg1[ch1[1]]) == dist(eg2[ch2[0]], eg2[ch2[1]])) printf("YES\n");
        else printf("NO\n");
        return 0;
    }
    for(int i = 0;i < chl1;i++) {
        A[(i+1)%chl1] = mp(angle(eg1[ch1[(i+2)%chl1]] - eg1[ch1[(i+1)%chl1]], eg1[ch1[(i+1)%chl1]] - eg1[ch1[i]]), dist(eg1[ch1[(i+2)%chl1]], eg1[ch1[(i+1)%chl1]]));
        B[(i+1)%chl1] = mp(angle(eg2[ch2[(i+2)%chl1]] - eg2[ch2[(i+1)%chl1]], eg2[ch2[(i+1)%chl1]] - eg2[ch2[i]]), dist(eg2[ch2[(i+2)%chl1]], eg2[ch2[(i+1)%chl1]]));
        //printf("A[%d] = (%Lf, %lld)\n", i, A[(i + 1)%chl1].first, A[(i + 1)%chl1].second);
        //printf("B[%d] = (%Lf, %lld)\n", i, B[(i + 1)%chl1].first, B[(i + 1)%chl1].second);
    }
    
    initfail();
    if(dokmp()) printf("YES\n");
    else printf("NO\n");
    
    return 0;
}