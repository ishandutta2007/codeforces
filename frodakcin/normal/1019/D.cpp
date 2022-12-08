#include <cstdio>
#include <iostream>

#include <utility>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

#define mp make_pair
#define pb push_back

#define slopey first.first
#define slopex first.second
#define point2 second.second
#define point1 second.first

typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<pll, pii> pllii;

const int MAXN = 101000;

int N;
ll S;

ll gcd(ll a , ll b) {
    if(a < b) return gcd(b, a);
    if(b == 0) return a;
    return gcd(b, a%b);
}

struct POINT
{
public:
    ll x, y;
    
    POINT() {
        x = y = -1;
    }
    POINT(ll a, ll b) {
        x = a;
        y = b;
    }
    
    void simp() {
        ll g = gcd(abs(x), abs(y));
        x /= g;
        y /= g;
        
        if(x < 0) x *= -1, y *= -1;
    }
    
    POINT rot90() {
        return POINT(-y, x);
    }
    
    POINT operator + (const POINT& c) {return POINT(x + c.x, y + c.y);}
    POINT operator - (const POINT& c) {return POINT(x - c.x, y - c.y);}
    ll operator ^ (const POINT& c) {return x * c.y - y * c.x;}      //det
    ll operator * (const POINT& c) {return x * c.x + y * c.y;}      //dot
} points[MAXN], sp[MAXN];

bool operator < (const pll& a, const pll& b) {return a.first * b.second < a.second * b.first;}

vector<pllii> H, I, V, II;        //(slope (y, x), pair of points)
int rep[MAXN];

ll tll(const int& a) {
    return static_cast<ll> (a);
}

bool comppos(const pllii& a, const pllii& b) {
    return a.first < b.first;
}
bool compneg(const pllii& a, const pllii& b) {
    return a.first > b.first;
}

void foundans(POINT a, POINT b, POINT c) {
    printf("Yes\n");
    printf("%lld %lld\n", a.x, a.y);
    printf("%lld %lld\n", b.x, b.y);
    printf("%lld %lld\n", c.x, c.y);
    exit(0);
}

int bsearch(POINT a, POINT b, ll g) {
    int l = -1, h = N;
    while(h > l + 1) {
        int m = l + (h - l)/2;
        if(g > ((b - a) ^ (points[m] - a))) l = m;
        else h = m;
    }
    return h;
}
void test(POINT a, POINT b) {
    int l = bsearch(a, b, S * 2);
    if(l < N and (((b - a) ^ (points[l] - a)) == S * 2)) foundans(a, b, points[l]);
    
    l = bsearch(a, b, - S * 2);
    
    if(l < N and (((b - a) ^ (points[l] - a)) == -S * 2)) foundans(a, b, points[l]);
}

void run(vector<pllii>& arr) {
    for(int i = 0;i < arr.size();i++) {
        test(points[rep[arr[i].point1]], points[rep[arr[i].point2]]);
        
        swap(points[rep[arr[i].point1]], points[rep[arr[i].point2]]);
        swap(rep[arr[i].point1], rep[arr[i].point2]);
    }
}

int main() {
    scanf("%d%lld", &N, &S);
    
    for(int i = 0;i < N;i++) {
        ll a, b;
        scanf("%lld%lld", &a, &b);
        points[i] = POINT(a, b);
    }
    
    sort(points, points + N, [](const POINT& a, const POINT& b){return a.x == b.x ? a.y > b.y : a.x < b.x;});
    
    for(int i = 0;i < N;i++) {
        rep[i] = i;
        for(int j = i + 1;j < N;j++) {
            
            POINT p1 = points[i];
            POINT p2 = points[j];
            POINT p3 = (p2 - p1).rot90();
            p3.simp();              //x positive, y either
            
            if(p1.y == p2.y) {
                V.pb(mp(mp(0LL, 1LL), mp(i, j)));
            } else if (p1.x == p2.x) {
                H.pb(mp(mp(1LL, 0LL), mp(i, j)));
            } else if (p3.y > 0){      //positive
                I.pb(mp(mp(p3.y, p3.x), mp(i, j)));
            } else {
                II.pb(mp(mp(p3.y, p3.x), mp(i, j)));
            }
            
        }
    }
    
    sort(I.begin(), I.end(), comppos);
    sort(II.begin(), II.end(), comppos);
    
    run(H);
    run(I);
    run(V);
    run(II);
    
    printf("No\n");
    
    return 0;
}


/*
3 2000000000000000000
1000000000 1000000000
1000000000 -1000000000
-1000000000 1000000000
*/