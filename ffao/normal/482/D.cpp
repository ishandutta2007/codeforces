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

#define sz size()

int n;
int p[110000];
vector<int> children[110000];
long long alldont[110000];
long long alldo[110000];
long long change[110000];
long long nochange[110000];
const int mod = 1000000007;

int main() {
    scanf("%d", &n);

    for (int i = 1; i < n; i++) {
        scanf("%d", &p[i]); p[i]--;
        children[p[i]].push_back(i);
    }

    for (int i = n-1; i >= 0; i--) {
        long long ad = 1;
        long long ap[2] = {1, 0};

        for (int j = 0; j < (int)children[i].size(); j++) {
            long long newap[2] = {0, 0};
            long long newad = (ad * (nochange[children[i][j]] + 1)) % mod;

            for (int ign = 0; ign <= 1; ign++) {
                newap[ign] = (ap[ign] * change[children[i][j]] + ap[ign^1]) % mod;
            }

            for (int ign = 0; ign <= 1; ign++) {
                ap[ign] = newap[ign];
            }
            ad = newad;
        }

        change[i] = (mod - ad) % mod;
        nochange[i] = (nochange[i] + mod - ap[!(children[i].size() & 1)]) % mod;

        long long c1 = 1;
        long long nc1 = 0;

        for (int j = ((int)children[i].size())-1; j >= 0; j--) {
            long long newc1 = (c1 * (nochange[children[i][j]] + 1) + (nc1 * change[children[i][j]])) % mod;
            long long newnc1 = (nc1 * (nochange[children[i][j]] + 1) + (c1 * change[children[i][j]])) % mod;

            c1 = newc1;
            nc1 = newnc1;
        }
        
        change[i] = (change[i] + c1 + c1) % mod;
        nochange[i] = (nochange[i] + nc1 + nc1) % mod;
    }

    printf("%lld\n", (nochange[0] + change[0]) % mod);
}