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
#include <unordered_map>

using namespace std; 

typedef long long ll; 
typedef pair<int, int> pii;

#define INF 1000000000
#define pb push_back 
#define itr iterator 
#define sz size() 
#define mp make_pair

int n, devs, mod;
int vec[410000];

int ct;
int iss[1100000];
int assoc[1100000];

long long solve(int st, int ed) {
    ct++;
    if (st == ed) return 0;

    long long ans = 0;
    int m = (st+ed)/2;

    int right = m+1;
    int righttot = 0;

    int tot = 0;
    int big = 0;
    for (int k = m; k >= st; k--) {
        tot = (tot + vec[k]) % devs;
        big = max(big, vec[k]);

        while (right <= ed && vec[right] <= big) {
            righttot = (righttot + vec[right]) % devs;
            if (iss[righttot] != ct) {
                iss[righttot] = ct;
                assoc[righttot] = 0;
            }
            assoc[righttot]++;
            right++;
        }

        int diff = ((big - tot) % mod);
        if (diff < 0) diff += mod;

        if (iss[diff] == ct) {
            ans += assoc[diff];
        }
    }

    ct++;
    right = m;
    righttot = 0;

    tot = 0;
    big = 0;
    for (int k = m+1; k <= ed; k++) {
        tot = (tot + vec[k]) % devs;
        big = max(big, vec[k]);

        while (right >= st && vec[right] < big) {
            righttot = (righttot + vec[right]) % devs;
            if (iss[righttot] != ct) {
                iss[righttot] = ct;
                assoc[righttot] = 0;
            }
            assoc[righttot]++;
            right--;
        }

        int diff = ((big - tot) % mod);
        if (diff < 0) diff += mod;

        if (iss[diff] == ct) {
            ans += assoc[diff];
        }
    }

    ans += solve(st, m);
    ans += solve(m+1, ed);

    return ans;
}

int main() {
    scanf("%d %d", &n, &devs);
    mod = devs;
    for (int i = 0; i < n; i++) {
        scanf("%d", &vec[i]);
    }

    printf("%lld\n", solve(0, n-1));
}