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

int n, a;
int arr[210000];

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    sort(arr, arr+n);
    n = unique(arr, arr+n) - arr;

    int best = 0;
    for (int i = 0; i < n; i++) {
        for (int j = arr[i]; ; j += arr[i]) {
            int k = lower_bound(arr, arr+n, j) - arr - 1;
            if (k >= 0 && k < n && arr[k] > arr[i] ) best = max(best, arr[k] % arr[i]);
            if (j >= 1000000) break;
        }
    }

    printf("%d\n", best);
}