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

#define INF 1000000000000000000LL
#define pb push_back 
#define itr iterator 
#define sz size() 
#define mp make_pair

int n, m, maxj, maxp;
int d[110000];
int h[210000];
long long total_dist[210000];

pair< pair<long long, int>, long long> sm[210000][20];
pair< pair<long long, int>, long long> big[210000][20];

typedef pair< pair<long long, int>, long long> node;

node join(node a, node b) {
    node ret;
    if (a.first.first < b.first.first) swap(a,b);
    ret.first = a.first;
    ret.second = max(b.first.first, a.second);
    return ret;
}

long long query(int st, int end) {
    int j = maxj;
    int p = maxp;
    pair< pair<long long, int>, long long> best_big = make_pair(make_pair(-INF, -1), -INF);
    pair< pair<long long, int>, long long> best_sm = make_pair(make_pair(-INF, -1), -INF);
    
    while (j >= 0) {
        if (st + p <= end) {
            best_big = join(best_big, big[st][j]);
            best_sm = join(best_sm, sm[st][j]);
            st += p;
        }
        j--;
        p >>= 1;
    }

    best_big = join(best_big, big[st][0]);
    best_sm = join(best_sm, sm[st][0]);

    if (best_big.first.second != best_sm.first.second) {
        return best_big.first.first + best_sm.first.first;
    }
    else {
        return max(best_big.second + best_sm.first.first, best_big.first.first + best_sm.second);
    }
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%d", &d[i]);
        total_dist[i+1] = total_dist[i] + d[i];
    }

    for (int i = 0; i < n; i++) {
        total_dist[i+n+1] = total_dist[i+n] + d[i];
    }

    for (int i = 0; i < n; i++) {
        scanf("%d", &h[i]);
        h[i+n] = h[i];
    }

    for (int i = 0; i < 2*n; i++) {
        big[i][0] = make_pair(make_pair(total_dist[i] + 2*h[i], i), -INF);
        sm[i][0] = make_pair(make_pair(2*h[i] - total_dist[i], i), -INF);
    }

    maxp = 1;
    maxj = -1;
    for (int p = 1; p <= 2*n; p*=2) {
        maxp = p;
        maxj++;
    }

    for (int j = 1, p = 1; j <= maxj; j++, p*=2) { 
        for (int i = 0; i < 2*n; i++) {
            if (i+p < 2*n) {
                big[i][j] = join(big[i][j-1], big[i+p][j-1]);
                sm[i][j] = join(sm[i][j-1], sm[i+p][j-1]);
            }
            else {
                big[i][j] = big[i][j-1];
                sm[i][j] = sm[i][j-1];
            }
        }
    }

    for (int i = 0; i < m; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        a--; b--;
        if (b < a) {
            printf("%lld\n", query(b+1, a-1));
        }
        else {
            printf("%lld\n", query(b+1, (n+a)-1));
        }
    }
}