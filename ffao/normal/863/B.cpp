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

int t,n,p;
int a[100];


int main() {
    scanf("%d", &n); n*=2;
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    sort(a, a+n);

    int ans = 1000000000;
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            vector<int> b;
            for (int k = 0; k < n; k++) if (k != i && k != j) {
                b.push_back(a[k]);
            }

            int th = 0;
            for (int i = 1; i < b.size(); i += 2) {
                th += b[i]-b[i-1];
            }
            ans = min(ans,th);
        }
    }
    printf("%d\n",ans);
}