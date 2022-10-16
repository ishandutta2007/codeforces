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

char row[1100][1100];
bool diff[1100];
int n, m;

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%s", row[i]);
    }

    int ans = 0;

    for (int i = 0; i < m; i++) {
        bool ok = true;
        for (int j = 0; j < n-1; j++) {
            if (!diff[j] && row[j][i] > row[j+1][i]) ok = false;
        }

        if (!ok) {
            ans++;
            continue;
        }

        for (int j = 0; j < n-1; j++) {
            if (row[j][i] < row[j+1][i]) diff[j] = true;
        }
    }

    printf("%d\n", ans);
}