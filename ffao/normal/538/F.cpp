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

int a[310000];
int violate[310000];
int t[610000];
int n;

int read(int x) {
    int s = 0;
    while (x > 0) {
        s += t[x];
        x -= x&-x;
    }
    return s;
}

void upd(int x, int d) {
    while (x <= 2*n+5) {
        t[x] += d;
        x += x&-x;
    }
}

vector< pair<int, int> > tams;

int main() {
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        tams.push_back( make_pair(a[i], i) );
    }

    sort(tams.begin(), tams.end());

    for (pair<int, int> kp : tams) {
        int i = kp.second;

        for (int k = 1; k*i < n && k < n; k++) {
            int f = k*i + 1;
            int la = f + k - 1;

            violate[k] += read(la+1) - read(f);
        }

        upd(i+1, 1);
    }
    
    for (int i = 1; i < n; i++) {
        printf("%d ", violate[i]);
    }
    printf("\n");
}