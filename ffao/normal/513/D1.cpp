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

int maxl[1100000];
int minr[1100000];
int maxr[1100000];
vector<int> ans;
int n,c;

int build(int root, int maxChild) {
    int maxLeft = root;
    if (maxl[root] > root) {
        maxLeft = build(root+1, maxl[root]);
    }

    ans.push_back(root);

    if (maxLeft >= minr[root]) {
        printf("IMPOSSIBLE\n");
        exit(0);
    }

    int maxRight = max(maxLeft, max(maxr[root], maxChild));
    if (maxRight > maxLeft) {
        maxRight = build(maxLeft+1, maxRight);
    }
    return maxRight;
}

int main() {

    scanf("%d %d", &n, &c);
    for (int i = 0; i <= n; i++) {
        maxl[i] = maxr[i] = -1;
        minr[i] = 1000000000;
    }

    for (int i = 0; i < c; i++) {
        int a, b;
        char loc[100];
        scanf("%d %d %s", &a, &b, loc);

        if (b <= a) {
            printf("IMPOSSIBLE\n");
            return 0;
        }

        if (loc[0] == 'L') {
            maxl[a] = max(b, maxl[a]);
        }
        else {
            minr[a] = min(b, minr[a]);
            maxr[a] = max(b, maxr[a]);
        }
    }

    build(1, n);

    for (int i = 0; i < n; i++) printf("%d ", ans[i]);
}