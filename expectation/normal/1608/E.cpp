//#define _CRT_SECURE_NO_WARNINGS
//#pragma comment(linker, "/stack:32777216")
#include <string>
#include <vector>
#include <map>
#include <list>
#include <iterator>
#include <cassert>
#include <set>
#include <queue>
#include <iostream>
#include <sstream>
#include <stack>
#include <deque>
#include <cmath>
#include <memory.h>
#include <cstdlib>
#include <cstdio>
#include <cctype>
#include <algorithm>
#include <utility>
#include <time.h>
using namespace std;

#define FOR(i, a, b) for(int i=(a);i<(b);i++)
#define RFOR(i, b, a) for(int i=(b)-1;i>=(a);--i)
#define FILL(A,value) memset(A,value,sizeof(A))
#define ALL(V) V.begin(), V.end()
#define SZ(V) (int)V.size()
#define PB push_back
#define MP make_pair
#define x first
#define y second
#define Pi 3.14159265358979
#define x0 ikjnrmthklmnt
#define y0 lkrjhkltr
#define y1 ewrgrg

typedef long long Int;
typedef long long LL;
typedef unsigned long long UInt;
typedef vector<int> VI;
typedef pair<int, int> PII;

const int RANGE = 1000000000+7;

vector<PII> v[3];
vector<PII> vx[3];
vector<PII> vy[3];
int n;

bool solve2(int k, int xl, int xr, vector<PII>& p1, vector<PII>& p2) {
    int ly = -RANGE, ry = RANGE;
    while (ly <= ry) {
        int y = (ly+ry)/2;
        int num1 = 0, num2 = 0;
        FOR (i,0,p1.size()) if (p1[i].first >= xl && p1[i].first <= xr && p1[i].second <= y) num1++;
        FOR (i,0,p2.size()) if (p2[i].first >= xl && p2[i].first <= xr && p2[i].second  > y) num2++;
        if (num1 < k && num2 < k) return false;
        if (num1 >=k && num2 >=k) return true;
        if (num1 < k) ly = y+1;
        else ry = y-1;
    }
    return false;
}

bool solve3(int k, int xl, int xr, vector<PII>& p1, vector<PII>& p2) {
    int ly = xl, ry = xr;
    while (ly <= ry) {
        int x = (ly+ry)/2;
        int num1 = 0, num2 = 0;
        FOR (i,0,p1.size()) if (p1[i].first >= xl && p1[i].first <= x) num1++;
        FOR (i,0,p2.size()) if (p2[i].first > x && p2[i].first <= xr) num2++;
        if (num1 < k && num2 < k) return false;
        if (num1 >=k && num2 >=k) return true;
        if (num1 < k) ly = x+1;
        else ry = x-1;
    }
    return false;
}

bool solve(int k, vector<PII>& p, vector<PII>& p1, vector<PII>& p2) {
    if (solve2(k, p[k-1].first+1, RANGE, p1, p2)) return true;
    if (solve2(k, p[k-1].first+1, RANGE, p2, p1)) return true;
    if (solve3(k, p[k-1].first+1, RANGE, p1, p2)) return true;
    if (solve3(k, p[k-1].first+1, RANGE, p2, p1)) return true;
    if (solve2(k, -RANGE, p[p.size()-k].first-1, p1, p2)) return true;
    if (solve2(k, -RANGE, p[p.size()-k].first-1, p2, p1)) return true;
    if (solve3(k, -RANGE, p[p.size()-k].first-1, p1, p2)) return true;
    if (solve3(k, -RANGE, p[p.size()-k].first-1, p2, p1)) return true;
    return false;
}

bool ok(int k) {
    return solve(k, vx[0], vx[1], vx[2]) ||
           solve(k, vx[1], vx[0], vx[2]) ||
           solve(k, vx[2], vx[0], vx[1]) ||
           solve(k, vy[0], vy[1], vy[2]) ||
           solve(k, vy[1], vy[0], vy[2]) ||
           solve(k, vy[2], vy[0], vy[1]);
}

int bp(int l, int r) {
    while (l != r) {
        int x = (l+r+1)/2;
        if (ok(x)) l = x;
        else r = x-1;
    }
    return l;
}

int main()
{
    cin >> n;
    FOR (i,0,n) {
        PII p;
        int type;
        cin >> p.first >> p.second; cin >> type;
        v[type-1].PB(p);
    }
    n /= 3;
    FOR (k,0,3) {
        FOR (i,0,v[k].size()) {
            vx[k].PB(v[k][i]);
            vy[k].PB(MP(v[k][i].second, v[k][i].first));
        }
        sort(vx[k].begin(), vx[k].end());
        sort(vy[k].begin(), vy[k].end());
    }
    cout << 3*bp(0,n);
    return 0;
}