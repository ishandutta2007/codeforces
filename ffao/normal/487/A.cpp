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

int hy, ay, dy;
int hm, am, dm;
int ph, pa, pd;

int main() {
    scanf("%d %d %d", &hy, &ay, &dy);
    scanf("%d %d %d", &hm, &am, &dm);
    scanf("%d %d %d", &ph, &pa, &pd);

    int best = 1000000000;
    for (int d = dy; d <= 201; d++) {
        for (int a = max(ay, dm+1); a <= 201; a++) {
            int cost = (a-ay)*pa + (d-dy)*pd;

            int my_dmg = a-dm;
            int ot_dmg = max(0, am-d);
            
            int turns_to_win = (hm + my_dmg - 1) / my_dmg;
            int min_hp = max(hy, ot_dmg * turns_to_win + 1);

            best = min(best, cost + (min_hp - hy) * ph);
        }
    }

    printf("%d\n", best);
}