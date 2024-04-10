#include <string>
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


#include <tuple>


char s[1100000];

void solve()
{
    scanf("%s", s);
    int n = strlen(s);
    int ans = n;
    for (int i = 0; i < n; i++) {
        if (s[i] != s[(i+1)%n]) {
            int ta = 1;
            for (int j = (i+2)%n; j != i && j != (i+1)%n; j=(j+1)%n) {
                if (s[j] != s[(j+n-1)%n]) {
                    ta++;
                    j = (j+1)%n;
                }
            }
            ans = min(ans,ta);

            ta = 1;
            for (int j = (i+n-1)%n; j != i && j != (i+1)%n; j=(j+n-1)%n) {
                if (s[j] != s[(j+1)%n]) {
                    ta++;
                    j = (j+n-1)%n;
                }
            }
            ans = min(ans,ta);

            break;
        }
    }
    printf("%d\n", ans);
}


int main() {


    solve();
}