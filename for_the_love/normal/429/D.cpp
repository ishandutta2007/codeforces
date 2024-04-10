#include <set>
#include <map>
#include <cmath>
#include <ctime>
#include <queue>
#include <cstdio>
#include <string>
#include <cstring>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;

#define PB push_back
#define MP make_pair

typedef double DB;
typedef long long LL;
typedef pair<int,int> PI;

const DB eps = 1e-6;
const int N = 1e5 + 7;
const int MOD = 1e9 + 7;
const int INF = 1e9 + 7;

struct Point{
    LL x, y;
} p[N], t[N];

LL Calc_dis(Point &a ,Point &b) {
    return (a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y);
}


bool cmpx(Point a, Point b){
    if (a.x == b.x) return a.y < b.y;
    return a.x < b.x;
}

bool cmpy(Point a, Point b){
    return a.y < b.y;
}

bool operator<(const Point &a ,const Point &b){
    if(a.y != b.y) return a.y < b.y;
    return a.x < b.x;
}

LL sqr(LL x){return x * x;}
LL Closest_Pair(int l ,int r ,Point p[]){
    LL ret = 1e18;
    if(l == r) return ret;
    if(l + 1 == r) return Calc_dis(p[l], p[l + 1]);

    int mid = l + r >> 1;
    ret = min(ret, Closest_Pair(l, mid, p));
    ret = min(ret, Closest_Pair(mid + 1, r, p));

    int n = 0;

    for (int i = l; i <= r; i++)
    if (sqr(p[i].x - p[mid].x) <= ret) t[n++] = p[i];

    sort(t, t + n, cmpy);

    for(int i = 0; i < n; i++)
    for(int j = i + 1; j <= i + 7 && j < n; j++)
        ret = min(ret , Calc_dis(t[i], t[j]));

     return ret;
}


int main(){
    int n, x;
    scanf("%d", &n);
    for (int i = 0; i < n; i++){
        scanf("%d", &x);
        p[i].x = i;
        if (!i) p[i].y = x; else p[i].y = p[i - 1].y + x;
    }

    sort(p, p + n, cmpx);
    cout << Closest_Pair(0, n - 1, p) << endl;

}