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

int a[1000];
int sum[1000];
int n,k;

multiset<int, greater<int> > big;
multiset<int> small;

int main() {
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);

    for (int i = 0; i < n; i++) {
        sum[i+1] = sum[i] + a[i];
    }

    int best = -1001;

    for (int i = 0; i < n; i++) {
        big.clear();
        small.clear();

        for (int p = n-1; p >= 0; p-- ) {
            big.insert(a[p]);
        }

        for (int j = i; j < n; j++) {
            big.erase(big.find(a[j]));
            small.insert(a[j]);

            int sw = min((int)big.sz, min((int)small.sz, k));
                
            multiset<int, greater<int> >::itr big_it = big.begin();
            multiset<int>::itr sm_it = small.begin();
            int delta = 0;

            for (int m = 0; m < sw; m++) {
                if (*big_it > *sm_it) delta += *big_it - *sm_it;
                else break;

                big_it++;
                sm_it++;
            }

            //printf("%d %d %d %d %d\n", i, j, sum[j+1], sum[i], delta);
            best = max(best, sum[j+1]-sum[i]+delta);
        }
    }

    printf("%d\n", best);
}