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

int n;
pair<int, int> cubes[110000];
map< pair<int, int>, int> indexes;
int blocked[110000];
int supported[110000];
int mark[110000];
set<int> can_remove;

const int mod = 1000000009;

int a, b;
vector<int> get_smaller[1010];
vector<int> get_larger[1010];
vector<int> all;

int main() {
    scanf("%d", &n);
    int W = 0;
    int mm = 0;
    int flips = n/2;

    for (int i = 0; i < n; i++) {
        scanf("%d %d", &a, &b);
    	if (a >= b) {
    		get_smaller[a].push_back(a-b);
    		W += a;
    	}
    	else {
    		get_larger[b].push_back(b-a);
    		flips--;
    		W += b;
    	}

    	mm = max(min(a, b), mm);
    }

    int best = 1000000001;
    for (int total_height = 1; total_height <= 1000; total_height++) {
    	for (int k : get_larger[total_height]) {
    		flips++;
    		W -= k;
    	}

    	for (int k : get_smaller[total_height]) {
    		all.push_back(k);
    	}

    	if (flips < 0) continue;
    	if (total_height < mm) continue;

    	sort(all.rbegin(), all.rend());
    	int tW = W;
    	for (int j = 0; j < flips && j < all.size(); j++) tW -= all[j]; 
    	best = min(best, tW * total_height);
    }	

    printf("%d\n", best);
}