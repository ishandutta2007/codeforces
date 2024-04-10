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
char bd[100][100];

char tt[4];
char want[] = "acef";

int main() {
    scanf("%d %d", &n, &m);
    
    for (int i = 0; i < n; i++) {
        scanf("%s", bd[i]);
    }

    int ans = 0;

    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < m-1; j++) {
            for (int dx = 0; dx <= 1; dx++) {
                for (int dy = 0; dy <= 1; dy++) {
                    tt[dx*2 + dy] = bd[i+dx][j+dy];
                }
            }

            sort(tt, tt+4);

            int cnt = 0;
            for (int k = 0; k < 4; k++) {
                cnt += (want[k] == tt[k]);
            }
            if (cnt == 4) ans++;
        }
    }

    printf("%d\n", ans);
}