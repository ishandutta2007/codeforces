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

int n, q;
int a;
char o;
int op;
set< pair<int, int> > eaten[2];

int main() {
    scanf("%d %d", &n, &q);
    for (int i = 0; i < q; i++) {
        scanf("%d %*d %c", &a, &o);
        op = (o == 'U');

        if (op == 1) {
            int nv = n+1;
            int next_vert_block = n+1;
            auto next_vert = eaten[op].lower_bound( {a, -1} );
            
            if (next_vert != eaten[op].end()) {
                if (next_vert->first == a) {
                    printf("0\n");
                    continue;
                }

                nv = next_vert->first;
                next_vert_block = next_vert->second;
            }  

            int horiz_block = n+1;
            auto next_horiz = eaten[op^1].lower_bound( {a, -1} );
            if (next_horiz != eaten[op^1].end()) {
                if (next_horiz->first < nv) {
                    horiz_block = next_horiz->first;
                }
            }

            int block = min(horiz_block, next_vert_block);
            printf("%d\n", block - a);
            eaten[op].insert( {a, block} );
        }

        else {
            int nv = 0;
            int next_vert_block = 0;
            
            auto next_vert = eaten[op].lower_bound( {a+1, -1} );
            if (next_vert != eaten[op].begin()) {
                next_vert--;
                if (next_vert->first == a) {
                    printf("0\n");
                    continue;
                }

                nv = next_vert->first;
                next_vert_block = next_vert->second;
            }  

            int horiz_block = 0;
            auto next_horiz = eaten[op^1].lower_bound( {a+1, -1} );
            if (next_horiz != eaten[op^1].begin()) {
                next_horiz--;
                if (next_horiz->first > nv) {
                    horiz_block = next_horiz->first;
                }
            }

            int block = max(horiz_block, next_vert_block);
            printf("%d\n", a - block);
            eaten[op].insert( {a, block} );
        }

    }
}