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

int n, T;
int t[1100], q[1100];

vector<int> levels[1100];

int main() {
    scanf("%d %d", &n, &T);
    
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &t[i], &q[i]);
        int lvl = T - t[i];
        levels[lvl].push_back(q[i]);
    }

    for (int lvl = T - 1; lvl > 0; lvl--) {
        sort(levels[lvl].begin(), levels[lvl].end());
        for (int k = ((int)levels[lvl].size()) - 1; k >= 0; k -= 2) {
            int pp = levels[lvl][k];
            if (k-1 >= 0) pp += levels[lvl][k-1];
            levels[lvl-1].push_back(pp);
        }
    }

    sort(levels[0].begin(), levels[0].end());
    printf("%d\n", *levels[0].rbegin());
}