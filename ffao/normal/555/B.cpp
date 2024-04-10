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

int island, bridge;

long long l[210000];
long long r[210000];
pair<long long, int> br[210000];
pair<long long, pair<long long, int> > ints[210000];
set < pair<long long, int> > eds;
int occ[210000];

int main() {
    scanf("%d %d", &island, &bridge);

    for (int i = 0; i < island; i++) {
        scanf("%lld %lld", &l[i], &r[i]);
    }

    for (int i = 0; i < bridge; i++) {
        scanf("%lld", &br[i].first);
        br[i].second = i;
    }
    sort(br, br+bridge);

    for (int i = 0; i < island-1; i++) {
        ints[i].first = l[i+1] - r[i];
        ints[i].second.first = r[i+1] - l[i];
        ints[i].second.second = i;
    }
    sort(ints, ints+(island-1));

    int la = -1;
    int match = 0;

    for (int i = 0 ; i < bridge; i++) {
        while (la + 1 < island-1 && ints[la+1].first <= br[i].first) {
            eds.insert(ints[la+1].second);
            la++;
        }

        if (eds.begin()->first >= br[i].first) {
            pair<long long, int> cur = *eds.begin();
            eds.erase(eds.begin());
            match++;
            occ[cur.second] = br[i].second;
        }
    }

    if (match != island-1) {
        printf("No\n");
    }
    else {
        printf("Yes\n");
        for (int i = 0; i < island-1; i++) printf("%d ", occ[i]+1);
    }
}