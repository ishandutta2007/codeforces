#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <deque>
#include <cassert>
#include <cstdlib>

#define mp make_pair
#define fs first
#define sc second
#define pb push_back

typedef long long ll;
typedef long double ld;

const ll INF = 1e9;
const ll lINF = 1e18;
const double EPS = 1e-12;

#ifdef DEBUG
#define dout(x) cerr<<x;
#else
#define dout(x)
#endif

using namespace std;

int n, T;

double prob[5555][5555], ans;

int main()
{
#ifdef DEBUG
    freopen ("in.txt", "r", stdin);
#endif
    scanf("%d%d", &n, &T);
    prob[0][0] = 1;
    int t[5555];
    double p[5555], sum = 0, sum2 = 0;
    for (int i = 0; i < n; i++) {
        scanf("%lf%d", &p[i], &t[i]);
        p[i]/=100;
    }
    for (int i = 0; i < n; i++) {
        sum = 0;
        sum2 = 0;
        double pow2 = 1, pp = 1-p[i];
        for (int j = 0; j < t[i]-1; j++) {
            pow2 *= pp;
            if (pow2 < EPS) {
                pow2 = 0;
            }
        }
        for (int j = i+1; j<t[i]; j++) {
            sum2*=pp;
            if (sum2 < EPS) {
                sum2 = 0;
            }
            sum2+=p[i]*prob[i][j-1];
            prob[i+1][j] = sum2;
            ans+=prob[i+1][j];
        }
        for (int j = max(t[i], i+1); j<=T; j++) {
            sum2*=pp;
            if (sum2 < EPS) {
                sum2 = 0;
            }
            sum2+=p[i]*(prob[i][j-1] - prob[i][j-t[i]]*pow2);
            prob[i+1][j]=prob[i][j-t[i]]*pow2 + sum2;
            ans+=prob[i+1][j];
        }
    }
    printf("%.10f", ans);
    return 0;
}