#include <iostream>
#include <cstdio>

#include <map>
#include <utility>

using namespace std;

#define mp make_pair

typedef long long ll;

const int MAXN = 1010;

struct PT {
public:
    ll x, y;
    PT() {x = y = 0;}
    PT(ll a, ll b) {
        x = a;
        y = b;
    }
    
    bool operator == (const PT& o) const {return o.x == x and o.y == y;}
    bool operator < (const PT& o) const {return x == o.x ? y < o.y : x < o.x;}
    bool operator > (const PT& o) const {return x == o.x ? y > o.y : x > o.x;}
    PT operator + (const PT& o) const {return PT(x + o.x, y + o.y);}
    PT operator - (const PT& o) const {return PT(x - o.x, y - o.y);}
    PT operator * (const ll& o) const {return PT(x * o, y * o);}
    
    void pout() {
        printf("%lld, %lld\n", x, y);
    }
};

PT lines[MAXN][2];

pair<bool, PT> intersect(const PT& a1, const PT& a2, const PT& b1, const PT& b2) {
    if((a2.x - a1.x) * (b2.y - b1.y) == (a2.y - a1.y) * (b2.x - b1.x)) return mp(false, PT(-1, -1));
    
    ll n = (b1.x - a1.x)*(b2.y - b1.y) - (b1.y - a1.y)*(b2.x - b1.x);
    ll d = (a2.x - a1.x)*(b2.y - b1.y) - (a2.y - a1.y)*(b2.x - b1.x);
    
    if(d > 0 and (n < 0 or n > d)) return mp(false, PT(-1, -1));
    if(d < 0 and (n > 0 or n < d)) return mp(false, PT(-1, -1));
    if(n * (a2.x - a1.x) % d or n * (a2.y - a1.y) % d) return mp(false, PT(-1, -1));
    
    PT sol = PT(n * (a2.x - a1.x) / d + a1.x, n * (a2.y - a1.y) / d + a1.y);
    
    if(sol.x < min(b1.x, b2.x) or sol.x > max(b1.x, b2.x) or sol.y < min(b1.y, b2.y) or sol.y > max(b1.y, b2.y)) return mp(false, PT(-1, -1));
    
    return mp(true, sol);
}

int N;
map<PT, int> dbc;

ll gcd(ll a, ll b) {
    if(a < b) swap(a, b);
    if(b == 0) return a;
    return gcd(b, a%b);
}

int nc2[MAXN];
void pcp() {
    for(int i = 0;i <= N;i++) {
        nc2[i] = i * (i + 1) / 2;
    }
}
int gt(int v) {
    int l = -1, h = N;
    while(h > l + 1) {
        int m = l + (h - l)/2;
        if(v > nc2[m]) l = m;
        else h = m;
    }
    return h;
}

int main() {
    scanf("%d", &N);
    
    ll ans = 0;
    pcp();
    
    for(int i = 0;i < N;i++) {
        int a, b, c, d;
        scanf("%d%d%d%d", &a, &b, &c, &d);
        lines[i][0] = PT(a, b);
        lines[i][1] = PT(c, d);
        ans += gcd(b > d ? b - d : d - b, c > a ? c - a : a - c) + 1;
    }
    
    pair<bool, PT> t;
    map<PT, int>::iterator it;
    
    for(int i = 0;i < N;i++) {
        for(int j = i + 1;j < N;j++) {
            if((t = intersect(lines[i][0], lines[i][1], lines[j][0], lines[j][1])).first) {
                if((it = dbc.find(t.second)) == dbc.end()) it = dbc.insert(mp(t.second, 0)).first;
                it->second++;
            }
        }
    }
    
    for(it = dbc.begin();it != dbc.end();it++) {
        ans -= gt(it->second);
    }
    
    printf("%lld\n", ans);
    
    return 0;
}