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

int a[110];
double pd[110][110][210];
int n, k;

double prob(int posa, int posb, int k) {
    if (k == 0) return 0;
    double& ans = pd[posa][posb][k];

    if (ans < 0) {
        ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                int na = posa, nb = posb;

                if (i <= posa && posa <= j) {
                    na = i+(j-posa);
                }
                if (i <= posb && posb <= j) {
                    nb = i+(j-posb);
                }

                double sw = prob(na, nb, k-1);
                if (i <= posa && posa <= j && i <= posb && posb <= j) {
                    //printf("sum\n");
                    ans += 1-sw;
                }
                else ans += sw;
            }
        }

        ans /= ((n * (n+1)) / 2.0);
    }

    return ans;
}

int main() {
    scanf("%d %d", &n, &k);
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int kk = 0; kk <= k; kk++) {
                pd[i][j][kk] = -1;
            }
        }
    }
    double ans = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            double sw = prob(i, j, k);
            //printf("%d %d %f\n", i, j, sw);
            if (a[j] > a[i]) ans += sw;
            else ans += (1-sw);
        }
    }

    printf("%.15f\n", ans);
}