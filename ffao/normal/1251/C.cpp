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
 
 
int t;
char s[1123456];
char odd[1123456];
char even[1123456];
 
void solve()
{
    for (scanf("%d", &t); t; t--) {
        scanf("%s", s);
        int l = strlen(s);
 
        int co = 0, ce = 0;
        
        for (int i = 0; i < l; i++) {
            int v = s[i]-'0';
            if (v%2 == 1) odd[co++] = v;
            else even[ce++] = v;
        }
 
        int o = 0, e = 0;
        while (o < co || e < ce) {
            if (e == ce || (o != co && odd[o] < even[e])) {
                printf("%d", odd[o++]);
            }
            else {
                printf("%d", even[e++]);
            }
        }
        printf("\n");
    }
}
 
 
#include <fstream>
 
 
int main() {
 
 
    solve();
}