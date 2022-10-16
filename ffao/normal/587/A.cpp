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


#define REP(i,n) for(int (i)=0;(i)<(int)(n);(i)++)

int a[1200000];
int ct[1200000];
int n;

int main() {
    scanf("%d", &n);
    REP(i, n) {
        scanf("%d", &a[i]);
        ct[a[i]]++;
    }
    
    REP(i, 1100000) {
        int r = ct[i]/2;
        ct[i] -= 2*r;
        ct[i+1] += r;
    }

    int ans = 0;
    REP(i, 1100000) {
        ans += ct[i];
    }
    printf("%d\n", ans);
}