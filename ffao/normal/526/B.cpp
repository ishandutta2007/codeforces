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

int n;
int totlit[4100];
int par[4100];

int main() {
    scanf("%d", &n);
    int vert = (1<<n) * 2 - 1;

    for (int i = 2; i <= vert; i++) {
        scanf("%d", &par[i]);
    }

    int ans = 0;
    for (int i = vert; i >= 2; i -= 2) {
        int left = totlit[i-1] + par[i-1];
        int right = totlit[i] + par[i];

        ans += max(right, left) - min(right, left);
        totlit[i/2] = max(right, left);
    }

    printf("%d\n", ans);
}