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

int n, k;
int a[40000];
int pd[30001][201][3][3][2];

int rec(int v, int k, int sign, int sign_la, int mid) {
    if (v == n) {
        if (k > 0) return -1000000000;
        return 0;
    }

    int& ret = pd[v][k][sign+1][sign_la+1][mid];
    int th;

    if (ret == -1) {
        ret = -1000000000;

        // use this on current
        if (mid) {
            th = a[v] * (sign+sign_la) + rec(v+1, k, sign, sign_la, 1);
            ret = max(ret, th);
        }

        // stop using
        th = rec(v+1, k, sign, sign_la, 0);
        ret = max(th, ret);

        // create new
        if (k > 0) {
            int la_contribution = -sign_la;

            if (k > 1) {
                for (int new_sign = -1; new_sign <= 1; new_sign++) {
                    if (new_sign == 0) continue;
                    int th = a[v] * (new_sign + la_contribution) + rec(v+1, k-1, la_contribution, new_sign, 1);
                    ret = max(ret, th);
                }
            }
            else {
                int new_sign = 0;
                th = a[v] * (new_sign + la_contribution) + rec(v+1, k-1, la_contribution, new_sign, 1);
                ret = max(ret, th);
            }   
        }

    }

    return ret;
}

int main() {
    memset(pd,-1,sizeof(pd));
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);

    printf("%d\n", rec(0, k, 0, 0, 0));
}