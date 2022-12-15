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

const int SIZE = 1005;
const int INF = 0x3f3f3f3f;
const ll INFll = 0x3f3f3f3f3f3f3f3f;
const ll fat = 1E6;

double INFD = 1e100;
double EPS = 1e-12;

struct PT {
    double x, y;
    PT() {};
    PT(double x, double y) : x(x), y(y) {};
    PT(const PT &p) : x(p.x), y(p.y) {};
    PT operator + (const PT &p) const { return PT(x+p.x, y+p.y); }
    PT operator - (const PT &p) const { return PT(x-p.x, y-p.y); }
    PT operator * (double c) const { return PT(x*c, y*c); }
    PT operator / (double c) const { return PT(x/c, y/c); }
    bool operator < (const PT &p) const { return x < p.x || (x == p.x && y < p.y); }
};

double dot(PT p, PT q) {return p.x*q.x+p.y*q.y;}
double dist2(PT p, PT q) {return dot(p-q, p-q);}
double cross(PT p, PT q) {return p.x*q.y-p.y*q.x;}

PT arr[SIZE];
PT aux[SIZE];
int n;

PT projectPointLine(PT a, PT b, PT c) {
    return a + (b-a)*dot(c-a, b-a)/dot(b-a, b-a);
}

double dist2PointLine(PT a, PT b, PT c) {
    return dist2(c, projectPointLine(a, b, c));
}

bool check(int um, int dois) {
    PT a = arr[um];
    PT b = arr[dois];
    int qntPontos = 0;
    for(int i = 0; i < n; i++) {
        if(dist2PointLine(a, b, arr[i]) > EPS) {
            aux[qntPontos++] = arr[i];
        }
    }
    if(!qntPontos) return false;
    PT c = aux[0];
    PT d = aux[0] + b - a;
    for(int i = 1; i < qntPontos; i++) {
        if(dist2PointLine(c, d, aux[i]) > EPS) return false;
    }
    return true;
}

int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        int y;
        scanf("%d", &y);
        arr[i] = PT(i+1, y);
    }
    if(check(0, 1) || check(0, 2) || check(1, 2)) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }
    return 0;
}