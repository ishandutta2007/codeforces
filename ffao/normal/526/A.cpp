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

int n;
char s[110];

int main() {
    scanf("%d", &n);
    scanf("%s", s);

    bool found = false;
    for (int j = 1; j < n; j++) {
        for (int i = 0; i < n; i++) {
            bool ok = true;
            for (int k = 0; k < 5; k++) {
                if (i + k * j >= n) {
                    ok = false;
                    break;
                }
                else if (s[i+k*j] == '.') {
                    ok = false;
                    break;
                }
            }
            found = (found || ok);
        }
    }
    
    printf("%s\n", found ? "yes" : "no");
}