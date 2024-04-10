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

pii beac[1100000];
int kill[1100000];

int main() {
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d %d", &beac[i].first, &beac[i].second);
    }

    sort(beac, beac+n);

    int ans = 1000000000;
    for (int i = 0; i < n; i++) {
        int destroy_up_to = lower_bound(beac, beac+n, pair<int,int>(beac[i].first - beac[i].second, -1)) - beac;
        kill[i] = i - destroy_up_to;

        if (destroy_up_to > 0) kill[i] += kill[destroy_up_to-1];
        ans = min(ans, kill[i] + n-1-i);
    }
    
    printf("%d\n", ans);
}