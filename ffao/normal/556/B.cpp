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

int n, num;

void solve()
{
    scanf("%d", &n);

    int ld = -1;
    bool ok = true;
    REP(i, n) {
        scanf("%d", &num);

        int delta;
        if (i % 2 == 0) delta = (i - num + n) % n;
        else delta = (num - i + n) % n;
        if (ld == -1 || ld == delta) {
            ld = delta;
        }
        else ok = false;
    }

    printf("%s", ok ? "Yes" : "No");
}
int main() {
    solve();
    return 0;
}