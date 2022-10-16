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

#define REP(i,n) for(int(i)=0;(i)<(int)(n);(i)++)

int n, m;
int k[1100];
int dp[1100][1100];

int rec(int lt, int rt) {
    if (lt >= rt) return 1;

    int &ret = dp[lt][rt];
    if (ret != 0) return ret;

    ret = 1000000000;
    if (k[lt] == k[rt-1]) {
        ret = rec(lt+1,rt-1);
    }
    
    for (int mid = lt+1; mid < rt; mid++) {
        ret = min(ret, rec(lt, mid) + rec(mid, rt));
    }

    return ret;
}

int main() {
    scanf("%d", &n);

    REP(i, n) scanf("%d", &k[i]);

    printf("%d\n", rec(0, n));
}