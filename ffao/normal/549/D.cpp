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

int n, m;
char bd[110][110];
long long ct[110][110];

int main() {
    scanf("%d %d", &n, &m);

    for (int i = 0; i < n; i++) {
        scanf("%s", bd[i]);
    }

    long long ans = 0;

    for (int i = n-1; i >= 0; i--) {
        for (int j = m-1; j >= 0; j--) {
            long long tct = ct[i][j+1] + ct[i+1][j] - ct[i+1][j+1];
            long long tgt = (bd[i][j] == 'W' ? 1 : -1);

            if (tgt - tct) ans++;
            ct[i][j] = tgt;
        }
    }

    cout << ans << endl;
}