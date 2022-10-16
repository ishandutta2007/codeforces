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
int L[10], R[10];

double test(int target, int i, int equal_to, int higher) {
    if (i == n) {
        if (higher == 0) {
            higher++;
            equal_to--;
        }

        return (higher == 1 && equal_to > 0);
    }

    double ret = 0;
    double prob_smaller = 0, prob_eq = 0, prob_higher = 0;

    if (L[i] < target) {
        if (target <= R[i]) prob_smaller = 1.0 * (target - L[i]) / (R[i]-L[i]+1);
        else prob_smaller = 1.0;

        ret += prob_smaller * test(target, i+1, equal_to, higher);
    }

    if (L[i] <= target && target <= R[i]) {
        prob_eq = 1.0 / (R[i]-L[i]+1);

        ret += prob_eq * test(target, i+1, equal_to+1, higher);
    }

    if (R[i] > target) {
        if (target >= L[i]) prob_higher = 1.0 * (R[i]-max(L[i]-1, target)) / (R[i]-L[i]+1);
        else prob_higher = 1.0;

        ret += prob_higher * test(target, i+1, equal_to, higher+1);
    }

    return ret;
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &L[i], &R[i]);
    }

    double ep = 0;
    for (int price = 10000; price >= 1; price--) {
        double pr = test(price, 0, 0, 0);
        //if (pr > 0) printf("%d %f\n", price, pr);
        ep += price * pr;
    }

    printf("%.15f\n", ep);
}