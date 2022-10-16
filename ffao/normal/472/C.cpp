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

pair<string, int> all[212345];
char str[100];
int sa[212345];
int n;

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", str);
        all[2*i].first = str;
        all[2*i].second = 2*i;
        scanf("%s", str);
        all[2*i+1].first = str;
        all[2*i+1].second = 2*i+1;
    }

    sort(all, all+2*n);

    for (int i = 0; i < 2*n; i++) {
        sa[all[i].second] = i;
    }

    bool ok = true;
    int last = -1;
    for (int i = 0; i < n; i++) {
        int a;
        scanf("%d", &a); a--;

        int big = max(sa[2*a], sa[2*a+1]);
        int small = min(sa[2*a], sa[2*a+1]);

        if (small > last) {
            last = small;
        }
        else {
            if (big > last) last = big;
            else ok = false;
        } 
    }

    printf("%s\n", ok ? "YES" : "NO");
}