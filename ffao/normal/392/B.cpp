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

int t[3][3];
int n;
long long pd[50][3][3];

long long calc(int n, int st, int end) {
    if (n == 0) return 0;

    int ot = 0;
    for (int i = 0; i < 3; i++) if (i != st && i != end) ot = i;

    if (n == 1) {
        return min(t[st][end], t[st][ot] + t[ot][end]);
    }

    long long &ret = pd[n][st][end];
    if (ret) return ret;

    return ret = min(
            calc(n-1, st, ot) + t[st][end] + calc(n-1, ot, end),
            calc(n-1, st, end) + t[st][ot] + calc(n-1, end, st) + t[ot][end] + calc(n-1, st, end)
            );
}

int main() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            scanf("%d", &t[i][j]);
        }
    }

    scanf("%d", &n);
    cout << calc(n, 0, 2) << endl;
}