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


template <typename T> T extGcd(T a, T b, T& x, T& y);


using namespace std;


#define REP(i,n) for(int (i)=0;(i)<(int)(n);(i)++)

multiset<int> all;
int n, tx, ty;

void solve()
{
    scanf("%d", &n);
    all.clear();
    REP(i, n*n) {
        int a;
        scanf("%d", &a);
        all.insert(a);
    }

    vector<int> selected;
    REP(i, n) {
        int ele = *all.rbegin();
        printf("%d ", ele);
        all.erase(all.find(ele));

        for (int k : selected) {
            all.erase(all.find(extGcd(k, ele,tx,ty)));
            all.erase(all.find(extGcd(k, ele,tx,ty)));
        }
        selected.push_back(ele);
    }

}
int main() {
    solve();
}


template <typename T>
T extGcd(T a, T b, T& x, T& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    else {
        int g = extGcd(b, a % b, y, x);
        y -= a / b * x;
        return g;
    }
}