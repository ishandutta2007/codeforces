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

int n, m, k;

int main() {
    scanf("%d %d %d", &n, &m, &k);

    if (n+m-2 < k) {
        printf("-1\n");
        return 0;
    }

    // k-small <= m-1
    // small >= k-m+1
    int small = max(0, k-m+1);

    // k-big >= 0
    // big <= k
    int big = min(k, n-1);

    int st = k/2;
    st = max(small, k/2);
    st = min(big, st);

    long long ans = 0;
    for (int h = small; h <= small+100000; h++) if (h >= small && h <= big) {
        long long a = n/(h+1);
        long long b = m/(k-h+1);
        ans = max(ans, a*b);
    }

    for (int h = big; h >= big-100000; h--) {
        if (h >= small && h <= big) {
            long long a = n/(h+1);
            long long b = m/(k-h+1);
            ans = max(ans, a*b);
        }
    }

    printf("%I64d\n", ans);
}