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
 
int marks[110000];
set<int> smar;

set<int> wantx;
set<int> wanty;
bool hasx = false, hasy = false;

int n,l,x,y;

 int main() {
    scanf("%d %d %d %d", &n, &l, &x, &y);

    vector<int> ans = {1,1,1};

    for (int i = 0; i < n; i++) {
        scanf("%d", &marks[i]);

        if (smar.count(marks[i] - x)) hasx = true;
        if (smar.count(marks[i] - y)) hasy = true;
        smar.insert(marks[i]);
        if (marks[i] - x > 0) wantx.insert(marks[i] - x);
        if (marks[i] + x < l) wantx.insert(x + marks[i]);
        if (marks[i] - y > 0) wanty.insert(marks[i] - y);
        if (marks[i] + y < l) wanty.insert(y + marks[i]);
    }

    if (hasx && hasy) {
        printf("0\n");
        return 0;
    }

    if (hasx) {
        swap(hasx,hasy);
        swap(wantx,wanty);
        swap(x,y);
    }

    //printf("%d %d\n", hasx, hasy);
    for (int kkk : wantx) {
        bool xx = hasy || wanty.count(kkk);
        if (xx) {
            printf("1\n");
            printf("%d\n", kkk);
            return 0;
        }
    }

    printf("2\n%d %d\n",x,y);
 }