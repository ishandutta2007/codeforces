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
int a[110000];
int st[110000];
int ed[110000];

int gl(int p) {
    if (p >= n || p < 0) return 0;
    return ed[p] - st[p] + 1;
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    for (int i = 0; i < n; i++) {
        if (i == 0 || a[i] <= a[i-1]) {
            st[i] = i;
            for (int j = i-1; j >= 0; j--) {
                ed[j] = i-1;
                if (st[j] == j) break;
            }
        }
        else {
            st[i] = st[i-1];
        }
    }

    for (int j = n-1; j >= 0; j--) {
        ed[j] = n-1;
        if (st[j] == j) break;
    }

    int best = 0;

    for (int i = 0; i < n; i++) {
        best = max(best, gl(i));
    }

    for (int i = 0; i < n; i++) {
        if (ed[i] == i) {
            if (st[i] == i || a[i-1]+1 < a[i+1]) {
                best = max(best, gl(i) + gl(i+1));
            }
        }

        if (st[i] == i) {
            if (ed[i] == i || a[i+1]-1 > a[i-1]) {
                best = max(best, gl(i) + gl(i-1));
            }
        }


        if (ed[i] == i) {
            best = max(best, 1 + gl(i+1));
        }

        if (st[i] == i) {
            best = max(best, 1 + gl(i-1));
        }
    }

    printf("%d\n", best);
}