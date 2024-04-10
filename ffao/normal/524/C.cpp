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

int n, k, v, q;

int denoms[5001];
map< int, vector<int> > can;

int main() {
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++) {
        scanf("%d", &denoms[i]);
        for (int m = 0; m <= k; m++) {
            can[denoms[i] * m].push_back(i);
        }
    }

    scanf("%d", &q);
    
    for (int i = 0; i < q; i++) {
        scanf("%d", &v);
        int b = k+1;

        for (int j = 0; j < n; j++) {
            for (int m = 0; m <= k; m++) {
                int rem = v - denoms[j]*m;
                
                if (rem == 0) {
                    b = min(b, m);
                }

                if (can.find(rem) != can.end()) {
                    int will = -1;

                    if (*can[rem].rbegin() != j) {
                        will = *can[rem].rbegin();
                    }
                    else if (can[rem].size() > 1) {
                        will = can[rem][can[rem].size() - 2];
                    }

                    if (will != -1) b = min(b, m + rem / denoms[will]);
                }
            }
        }
        
        printf("%d\n", (b==k+1) ? -1 : b);
    }


}