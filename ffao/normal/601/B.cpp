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

int n, q;
int a[110000];
int le[110000];
int ri[110000];

long long calc(int l, int r) {
    stack< pair<int, int> > big;
    for (int i = l; i <= r; i++) {
        while (!big.empty() && big.top().first < a[i]) big.pop();
        if (!big.empty()) le[i] = big.top().second;
        else le[i] = l-1;
        big.push( {a[i], i} );
    }

    while (!big.empty()) big.pop();
    for (int i = r; i >= l; i--) {
        while (!big.empty() && big.top().first <= a[i]) big.pop();
        if (!big.empty()) ri[i] = big.top().second;
        else ri[i] = r+1;
        big.push( {a[i], i} );
    }


    long long ans = 0;
    for (int i = l; i <= r; i++) {
        //printf("%d %d %d\n", i, le[i], ri[i]);
        ans += a[i] * 1ll * (i-le[i]) * 1ll * (ri[i]-i);
    }
    return ans;
}

int main() {
    scanf("%d %d", &n, &q);

    REP(i,n) scanf("%d", &a[i]);
    REP(i,n-1) a[i] = abs(a[i+1]-a[i]);

    REP(itt, q) {
        int l, r;
        scanf("%d %d", &l, &r); l--; r--;

        printf("%lld\n", calc(l,r-1));
    }

}