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
 
 
int t, n;
 
void solve()
{
    for (scanf("%d", &t); t; t--) {
        scanf("%d", &n);
        vector<int> p(n), m(n);
        vector< vector<int> > costs_per_m(n, vector<int>());
 
        for (int i = 0; i < n; i++) {
            scanf("%d %d", &m[i], &p[i]);
            costs_per_m[m[i]].push_back(p[i]);
        }
 
        long long ans = 0;
        int rem = n;
        multiset<int> rem_costs;
 
        for (int i = n-1; i >= 0; i--) {
            for (int k : costs_per_m[i]) rem_costs.insert(k);
            
            while (rem - rem_costs.size() < i) {
                ans += *rem_costs.begin();
                rem_costs.erase(rem_costs.begin());
            }
        }
 
        printf("%lld\n", ans);
    }
}
 
 
#include <fstream>
 
 
int main() {
 
 
    solve();
}