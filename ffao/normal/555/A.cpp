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

int n, k;
int tt, x;

int main() {
    scanf("%d %d", &n, &k);
    int ans = 0;

    for (int i = 0; i < k; i++) {
        scanf("%d", &tt);
        bool ok = true;
        int la = 0;

        for (int t = 0; t < tt; t++) {
            scanf("%d", &x);
            if (t == 0) {
                ok = (x == 1);
            }
            else if (!ok || x != la+1) {
                ok = false;
                ans += 2;
            }
            la = x;
        }
    }

    printf("%d\n", ans + k - 1);
}