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

int diff[1100000];
int sn[1100000];
int n, t;

int main() {
    scanf("%d %d", &n, &t);

    for (int i = 0; i < n-1; i++) {
        scanf("%d", &diff[i]);
    }

    int c = 0;
    t--;

    while (c < t) {
        if (sn[c]) break;
        sn[c]=1;

        c = c + diff[c];
    }

    printf("%s\n", c == t ? "YES" : "NO");
}