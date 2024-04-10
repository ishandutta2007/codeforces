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

int n,k;
int t;
const int mod = 1000000007;
long long l, r;
int main() {
    for (cin >> t; t; t--) {
        cin >> l >> r;
        long long res = 0;
        for (int i = 60; i >= 0; i--) {
            long long pot = (1LL<<i);
            if ((l&pot) && (r&pot)) res += pot;
            else if ((l&pot)!=(r&pot)) {
                long long test = res + (2*pot) - 1;
                if (test <= r) res = test;
                else res += pot-1;
                break;
            }
        }
        cout << res << '\n';
    }
}