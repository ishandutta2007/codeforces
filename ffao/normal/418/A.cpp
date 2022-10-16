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

int main() {
    scanf("%d", &n);
    scanf("%d", &k);
    int matches = n*(n-1)/2;
    int wins = n*k;
    if (matches < wins) {
        printf("-1\n");
        return 0;
    }
    
    printf("%d\n", wins);
    for (int w = 1; w <= k; w++) {
        for (int i = 0; i < n; i++) {
            printf("%d %d\n", i+1, ((i+w)%n)+1);
        }
    }
}