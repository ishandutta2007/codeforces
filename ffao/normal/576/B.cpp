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

int p[110000];
int seen[110000];
vector< vector<int> > cycles;
int n;

int main() {
    scanf("%d", &n);
    REP(i, n) {
        scanf("%d", &p[i]);
        p[i]--;
    }

    REP(i, n) {
        if (p[i] == i) {
            printf("YES\n");
            for (int j = 0; j < n; j++) if (j != i) {
                printf("%d %d\n", i+1, j+1);
            }
            return 0;
        }
    }

    REP(i, n) if (!seen[i]) {
        int curr = i;
        vector<int> cc;
        while (!seen[curr]) {
            seen[curr] = 1;
            cc.push_back(curr);
            curr = p[curr];
        }
        cycles.push_back(cc);
    }

    int center = -1;
    bool ok = true;
    for (int i = 0; i < (int)cycles.size(); i++) {
        if (cycles[i].size() % 2 != 0) ok = false;
        if (cycles[i].size() == 2) center = i;
    }

    if (!ok || center == -1) {
        printf("NO\n");
        return 0;
    }

    printf("YES\n");
    printf("%d %d\n", cycles[center][0]+1, cycles[center][1]+1);
    for (int i = 0; i < (int)cycles.size(); i++) if (i != center) {
        
        for (int j = 0; j < (int)cycles[i].size(); j++) {
            printf("%d %d\n", cycles[i][j]+1, cycles[center][j&1]+1);
        }
    
    }
}