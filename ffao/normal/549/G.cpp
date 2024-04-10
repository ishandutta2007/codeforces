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
int line[310000];

int main() {
    scanf("%d", &n);
    for (int i = n-1; i >= 0; i--) {
        scanf("%d", &line[i]);
        line[i] -= i;
    }   

    sort(line, line+n, greater<int>());

    for (int i = 0; i < n-1; i++) {
        if (line[i] < line[i+1] + 1) {
            printf(":(\n");
            return 0;
        } 
    }

    for (int i = 0; i < n; i++) {
        printf("%d ", line[n-i-1] + n-i-1);
    }
    printf("\n");
}