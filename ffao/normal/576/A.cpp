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

#define REP(i,n) for((i)=0;(i)<(int)(n);(i)++)

vector<int> g;
int n;

int main() {
    scanf("%d", &n);
    for (int i = 2; i <= n; i++) {
        bool ok = true;
        for (int j = 2; j < i; j++) {
            if (i % j == 0) {
                ok = false;
                break;
            }
        }
        if (ok) {
            int tt = i;
            while (tt <= n) {
                g.push_back(tt);
                tt *= i;
            }
        }
    }   

    printf("%d\n", g.size());
    for (int k : g) printf("%d ", k);
}