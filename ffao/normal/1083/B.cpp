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


int pd[510000][2][2];

int n, k;
char s[510000];
char t[510000];


void solve()
{
	scanf("%d %d", &n, &k);
	scanf("%s %s", s, t);

	pd[0][1][1] = 1;
    for (int p = 0; p < n; p++) {
    	for (int eq_s = 0; eq_s <= 1; eq_s++) {
    		for (int eq_t = 0; eq_t <= 1; eq_t++) {
    			for (char c = 'a'; c <= 'b'; c++) {
    				if (c < s[p] && eq_s) continue;
    				if (c > t[p] && eq_t) continue;

    				int neq_s = eq_s && (c == s[p]);
    				int neq_t = eq_t && (c == t[p]);
    				pd[p+1][neq_s][neq_t] = min(k, pd[p+1][neq_s][neq_t] + pd[p][eq_s][eq_t]);
    			}
    		}
    	}
    }

    long long tot = 0;
    for (int len = 1; len <= n; len++) {
    	int th = 0;
    	for (int eq_s = 0; eq_s <= 1; eq_s++) {
    		for (int eq_t = 0; eq_t <= 1; eq_t++) {
    			th = min(k, th + pd[len][eq_s][eq_t]);
    			//printf("%d %d %d -> %d\n", len, eq_s, eq_t, pd[len][eq_s][eq_t]);
    		}
    	}
    	tot += th;
    }

    printf("%lld\n", tot);
}


#include <fstream>


int main() {


    solve();
}