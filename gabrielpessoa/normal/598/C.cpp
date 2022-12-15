#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
typedef long long ll;
typedef pair<ll, int> lli;
typedef pair<int, ii> iii;
typedef pair<double, ii> dii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<ii> vii;
typedef vector<iii> viii;
typedef long double ld;

const int SIZE = 1E5+5;
const int INF = 0x3f3f3f3f;
const ll INFll = 0x3f3f3f3f3f3f3f3f;
const ll fat = 1E6;

ld INFD = 1e100;
ld EPS = 1e-12;

struct PT {
    ld x, y;
    PT() {};
    PT(ld x, ld y) : x(x), y(y) {};
    PT(const PT &p) : x(p.x), y(p.y) {};
    PT operator + (const PT &p) const { return PT(x+p.x, y+p.y); }
    PT operator - (const PT &p) const { return PT(x-p.x, y-p.y); }
    PT operator * (ld c) const { return PT(x*c, y*c); }
    PT operator / (ld c) const { return PT(x/c, y/c); }
    bool operator < (const PT &p) const { return x < p.x || (x == p.x && y < p.y); }
};

ld dot(PT p, PT q) {return p.x*q.x+p.y*q.y;}
ld dist2(PT p, PT q) {return dot(p-q, p-q);}
ld cross(PT p, PT q) {return p.x*q.y-p.y*q.x;}

pair<PT, int> arrP[SIZE];
pair<PT, int> arrN[SIZE];

int main() {
    int n;
    cin >> n;
    int posP = 0, posN = 0; 
    for(int i = 1; i <= n; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        PT p(x, y);
        p = p/sqrt(dot(p, p));
        if(p.y >= 0) arrP[posP++] = {p, i};
        else arrN[posN++] = {p, i};
    }
    sort(arrP, arrP + posP);
    sort(arrN, arrN + posN);
    for(int i = 0; i < posN; i++) {
        arrP[posP + i] = arrN[posN - 1 - i];
    }
    ld best = 3;
    ii bestPos;
    for(int i = 1; i <= n; i++) {
        ld seno = dot(arrP[i%n].first, arrP[i-1].first);
        ld cosseno = abs(cross(arrP[i%n].first, arrP[i-1].first));
        if(seno < 0) cosseno = 2 - cosseno;
        if(cosseno < best) {
            best = cosseno;
            bestPos = {arrP[i%n].second, arrP[i-1].second};
        }
    }
    printf("%d %d\n", bestPos.first, bestPos.second);
    return 0;
}