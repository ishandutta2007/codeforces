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

typedef long long ll; 
typedef pair<int, int> pii;

#define INF 1000000000
#define pb push_back 
#define itr iterator 
#define sz size() 
#define mp make_pair

int n, p;

int main() {
    scanf("%d", &n);    
    
    printf("+------------------------+\n");
    for (int row = 0; row < 4; row++) {
        printf("|");
        for (int pl = 0; pl < 11; pl++) {
            int t = row + 1;
            if (row == 3 && pl > 0) t--; 
            
            if (row == 2 && pl > 0) {
                printf("..");
                continue;
            }

            if (pl > 0) {
                t += 4;
                t += (pl-1) * 3;
            }

            if (t <= n) printf("O");
            else printf("#");
            printf(".");
        }

        printf("%s", row == 2 ? "." : "|");
        printf("%s|", row == 0 ? "D" : ".");
        if (row == 0 || row == 3) printf(")\n");
        else printf("\n");
    }

    printf("+------------------------+\n");
}