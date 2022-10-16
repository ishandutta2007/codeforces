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
long long fib[110];

void get_nth(int n, long long k, int inc) {
    for (int i = 0; i < min(2, n); i++) {
        long long t = fib[n-i-1];
        if (t >= k) {
            for (int j = i; j >= 0; j--) {
                printf("%d ", j + inc);
            }
            get_nth(n-i-1, k, inc + i + 1);
            return;
        }
        else {
            k -= t;
        }
    }
}

int main() {
    scanf("%d %lld", &n, &k);

    fib[0]=fib[1]=1;
    for (int i = 2; i <= 51; i++) fib[i] = fib[i-1]+fib[i-2];
    
    get_nth(n, k, 1);   
}