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

int n;
char s[1100];

void solve()
{
    scanf("%d", &n);
    REP(i, n) {
        scanf("%s", s);
        int l = strlen(s);
        if (l > 10) {
            printf("%c%d%c\n", s[0], l - 2, s[l - 1]);
        }
        else {
            printf("%s\n", s);
        }
    }
}
int main() {
    solve();
}