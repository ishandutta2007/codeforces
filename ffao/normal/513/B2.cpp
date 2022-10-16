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
long long k;
long long cnt[60];

int fin[60];
int com = 0;

int main() {
    scanf("%d %I64d", &n, &k);
    
    cnt[0] = 1;
    cnt[1] = 1;
    cnt[2] = 2;
    for (int i = 2; i <= n; i++) {
        cnt[i] = cnt[i-1] * 2;
    }

    int fim = n-1;

    int inc = 0;
    for (int i = 1; i <= n; i++) {
        if (cnt[n-i] >= k) {
            fin[com++] = i;
        }
        else {
            k -= cnt[n-i];
            fin[fim--] = i;
        }
    }

    for (int i = 0; i < n; i++) printf("%d ", fin[i]);

}