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

int n, m, b, v;
int cc;
int C[510][510];
int a[510];

int main() {
    scanf("%d %d %d %d", &n, &m, &b, &v);
    
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    if (m < 0 || b < 0) {
        printf("0\n");
        return 0;
    }

    //for (int bb = 0; bb <= b; bb++)
    C[0][0] = 1;

    for (int i = n-1; i >= 0; i--) {
        for (int rem = 0; rem <= m; rem++) {
            for (int bb = 0; bb <= b; bb++) {
                if (rem > 0 && a[i] <= bb) 
                    C[rem][bb] = (C[rem][bb] + C[rem-1][bb-a[i]]) % v;
                
            }
        }
    }

    int k = 0;
    for (int bb = 0; bb <= b; bb++) k = (k + C[m][bb]) % v;
    printf("%d\n", k);
}