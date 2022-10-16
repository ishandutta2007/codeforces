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

int n, m;
pair< pair<int, int>, int> edge[210000];
int ed1[210000];
int ed2[210000];

int v1 = 1;
int v2 = 2;

void advance(int &v1, int &v2) {
    v1++;
    if (v1 == v2) {
        v2++;
        v1 = 1;
    }
}

int main() {
    scanf("%d %d", &n, &m);

    for (int i = 0; i < m; i++) {
        edge[i].second = i;
        scanf("%d %d", &edge[i].first.first, &edge[i].first.second);
        edge[i].first.second = -edge[i].first.second;
    }
    
    sort(edge, edge+m);

    int included = 0;
    for (int i = 0; i < m; i++) {
        if (edge[i].first.second) {
            ed1[edge[i].second] = 0;
            ed2[edge[i].second] = ++included;
        }
        else {
            if (v2 > included) {
                printf("-1\n");
                return 0;
            }

            ed1[edge[i].second] = v1;
            ed2[edge[i].second] = v2;
            advance(v1, v2);
        }
    }

    for (int i = 0; i < m; i++) {
        printf("%d %d\n", ed1[i]+1, ed2[i]+1);
    }
}