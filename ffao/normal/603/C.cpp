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

#define REP(i,n) for(int(i)=0;(i)<(int)(n);(i)++)

int dairy[] = {0,1,0,1,2,0,2,0};

int moo(int cow) {
    if (cow <= 6) return dairy[cow];

    if (cow % 2 == 1) return 0;

    int beef = cow;
    int calf = 0;
    while (beef % 2 == 0) {
        beef /= 2;
        calf++;
    }

    if (beef == 1 && calf % 2 == 0) return 2;
    if (beef == 3 && calf % 2 == 1) return 2;
    if (beef != 1 && beef != 3 && calf % 2 == 0) return 2;

    return 1;
}

int moo2(int cow) {
    if (cow <= 2) return cow;

    return 1 ^ (cow % 2);
}

int n, k;
int bull;

int main() {
    scanf("%d %d", &n, &k);
    k %= 2;

    int cheese = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", &bull);
        if (k == 1) cheese ^= moo(bull);
        else cheese ^= moo2(bull);
    }

    printf("%s\n", cheese ? "Kevin" : "Nicky");
}