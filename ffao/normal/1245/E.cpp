#include <string>
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


void re(int& x);


int ladders[100];
double expected[110];

pair<int, int> ntorc(int n) {
    int r = n/10, c = n%10;
    if (r % 2 == 1) c = 9-c;
    return {r,c};
}

int rcton(int r, int c) {
    if (r % 2 == 1) c = 9-c;
    return r*10+c;
}

void solve()
{
    for (int r = 9; r >= 0; r--) {
        for (int c = 0; c < 10; c++) {
            re(ladders[rcton(r,c)]);
        }
    }

    for (int i = 98; i>= 0; i--) {
        expected[i] = 1;
        for (int roll = 1; roll <= 6; roll++) if (i+roll < 99) {
            int sq = i+roll;
            int r,c;
            tie(r,c) = ntorc(sq);

            int ladder_dest = rcton(r + ladders[sq], c);
            expected[i] += min(expected[sq], expected[ladder_dest])/6;
        }

        if (i >= 94) {
            expected[i] = expected[i] * 6.0 / (99-i);
        }
    }

    printf("%.15f\n", expected[0]);
}


int main() {


    solve();
}


void re(int& x) { scanf("%d", &x); }