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
 
 
char s[1100];
int t;
 
void solve()
{
    for (scanf("%d", &t); t; t--) {
        scanf("%s", s);
        for (char c = 'a'; c <= 'z'; c++) {
            bool ok = false;
            for (int i = 0; s[i]!='\0'; i++) {
                if (s[i] == c) {
                    if (s[i+1] != c) {
                        ok = true;
                        break;
                    }
                    i++;
                }
            }
 
            if (ok) printf("%c", c);
        }
        printf("\n");
    }    
}
 
 
#include <fstream>
 
 
int main() {
 
 
    solve();
}