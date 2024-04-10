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
#include <tuple>

using namespace std;

typedef long long ll;

int n, m, k;
int p;

int a[310000];
int pp[310000][32];
int ans[310000];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[n+i] = a[i];
        a[n+n+i] = a[i];
    }

    for (int i = 0; i < 3*n; i++) {
        pp[i][0] = a[i];
    }

    for (int j = 1; j < 21; j++) {
        int l = (1<<(j-1));
        for (int i = 0; i < 3*n; i++) {
            pp[i][j] = pp[i][j-1];
            if (i+l < 3*n) {
                pp[i][j] = min(pp[i][j], pp[i+l][j-1]);
            }
        }
    }

    for (int i = 0; i < 3*n; i++) {
        int tgt = (a[i]-1)/2;
        int upt = i;
        for (int j = 20; j >= 0; j--) {
            int l = (1<<j);
            if (upt+l <= 3*n && pp[upt][j] > tgt) {
                upt += l;
            }
        }

        //cout << upt;
        ans[i] = upt;
    }

    for (int i = 3*n-2; i >= 0; i--) {
        ans[i] = min(ans[i], ans[i+1]);
    }

    for (int i = 0; i < n; i++) {
        //cout << i << " " << ans[i] << endl;
        int t = ans[i] - i;
        if (ans[i] == 3*n) cout << -1;
        else cout << t;
        cout << " ";
    }

    cout << endl;
}