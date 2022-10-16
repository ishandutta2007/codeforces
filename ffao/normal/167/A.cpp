#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>

using namespace std;

typedef long long ll;
int N, M;

int n, a, d;
int t,v;

#define INF 1000000000
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REP(i,n) FOR(i,0,n)
#define pb push_back
#define itr iterator
#define sz size()

double calc(double v, double a, double d) {
    double acct = v/a;
    double dist_acc = v/2 * acct;
    
    if (dist_acc < d) {
        return acct + (d-dist_acc)/v;
    }
    
    else {
        return sqrt(2*d / a);
    }
}

int main() {
    scanf("%d %d %d", &n, &a, &d);
    double prev = 0;
    REP(i, n) {
        scanf("%d %d", &t, &v);
        double th = calc(v, a, d);
        if (th + t > prev) prev = th+t;
        printf("%lf\n", prev);
    }
}