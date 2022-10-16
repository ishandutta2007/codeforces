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


int n, p;

void solve()
{
    scanf("%d %d", &n, &p);

    int ans = 0;
    while (1) {
        n -= p;
        ans++;

        if (n < ans) {
            ans = -1;
            break;
        }
        if (ans >= __builtin_popcount(n)) break;
    }

    printf("%d\n",ans);
}


#include <fstream>


int main() {


    solve();
}