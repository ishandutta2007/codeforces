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

int n,k;
const int mod = 1000000007;

int main() {
    scanf("%d %d", &n, &k);
    while (n > k+1) {
        printf("%d ", n);
        n--;
    }

    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) printf("%d ", n - (i/2));
        else printf("%d ", i/2+1);
    }
}