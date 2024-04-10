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

#define PI 3.1415926535

#define INF 1000000000
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REP(i,n) FOR(i,0,n)
#define pb push_back
#define itr iterator
#define sz size()

int N, r, R;
int main() {
    scanf("%d %d %d", &N, &R, &r);
    
    if (N == 1) {
        if (r <= R) printf("YES\n");
        else printf("NO\n");
        return 0;
    }
    else if (N == 2) {
        if (2*r <= R) printf("YES\n");
        else printf("NO\n");
        return 0;
    }
    
    int diff = R-r;
    
    double theta = PI * (N-2) / ((double)N);
    double phi = 2*PI / ((double)N);
    
    double s = sin(phi) * diff / sin(theta/2);

    if (s - 2*r > -1e-9) printf("YES\n");
    else printf("NO\n");
}