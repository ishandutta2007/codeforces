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

#define REP(i,n) for(int(i)=0;(i)<(int)(n);(i)++)

int n, m, b;

int a[1100000];

int main() {
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        int u;
        scanf("%d", &u);
        a[u] = a[u-1]+1;
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        ans = max(ans, a[i]);
    }
    printf("%d\n", n - ans);
}