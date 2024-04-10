#include <vector> 
#include <list> 
#include <map> 
#include <set> 
#include <queue>
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
typedef pair<int, int> pii;

#define INF 1000000000
#define pb push_back 
#define itr iterator 
#define sz size() 
#define mp make_pair

int a[1100][1100];
int sc[1100], sr[1100];
long long arit[1100000];
long long sumr[1100000], sumc[1100000];

multiset<long long> rows, cols;
int rf = 0, cf = 0;
int n,m,k,p;

void calcs(long long suma[], multiset<long long>& vals, int dim) {
    suma[0] = 0;
    for (int it = 1; it <= k; it++) {
        long long cur = -*vals.begin();
        vals.erase(vals.begin());

        suma[it] = suma[it-1] + cur;
        cur -= p*dim;

        vals.insert(-cur);
    }
}

int main() {
    scanf("%d %d %d %d", &n, &m, &k, &p);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &a[i][j]);
            sr[i] += a[i][j];
            sc[j] += a[i][j];
        }
    }

    for (int i = 0; i < n; i++) rows.insert(-sr[i]);
    for (int j = 0; j < m; j++) cols.insert(-sc[j]);

    calcs(sumr, rows, m);
    calcs(sumc, cols, n);

    arit[0] = 0;
    long long dec = 0;
    for (int i = 1; i <= k; i++) {
        arit[i] = arit[i-1] + dec;
        dec += p;
    }

    long long best = -1000000000000000000LL;
    for (int r = 0; r <= k; r++) {
        best = max(best, sumr[r] + sumc[k-r] - ((long long)p) * r * (k-r));
    }

    printf("%I64d\n", best);
}