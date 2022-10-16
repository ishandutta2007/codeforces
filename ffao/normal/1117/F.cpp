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


#include <tuple>


int n, p;
char s[110000];
int A[20][20];

int has[110000][20];
int dp[20][20][132000];
int la[20];
int cnt[20];
int hm[132000];
int ok[132000];

int get(int i, int j) {
    int dist = j-i+1;
    int k = 0, p2 = 1;
    for (; p2*2 <= dist; p2<<=1, k++);

    //printf("get %d %d = %d (%d %d %d %d)\n", i,j,  has[i][k] | has[j-p2+1][k], p2, k, has[i][k] ,has[j-p2+1][k]);
    return has[i][k] | has[j-p2+1][k];
}

void solve()
{
    scanf("%d %d", &n, &p);
    scanf("%s", s);
    for(int i = 0; i < p; i++) for (int j = 0; j < p; j++) scanf("%d", &A[i][j]);

    for (int i = 0; i < n; i++) has[i][0] = (1<<(s[i]-'a'));
    for (int j = 1; j < 18; j++) {
        for (int i = 0; i < n; i++) {
            has[i][j] = has[i][j-1];
            if (i + (1<<(j-1)) < n) has[i][j] |= has[i + (1<<(j-1))][j-1];
        }
    }

    for (int i = 0; i < p; i++) la[i] = -1;
    for (int i = 0; i < n; i++) {
        int c = s[i]-'a'; cnt[c]++;
        for (int ot = 0; ot < p; ot++) if (!A[c][ot] && la[ot] != -1 && la[c] <= la[ot]) {
            int inter = get(la[ot]+1, i-1);
            //printf("%d is not ok from %c %c\n", inter, 'a'+c, 'a'+ot);
            dp[c][ot][inter] = dp[ot][c][inter] = 1;
        }
        la[c] = i;
    }

    for (int i = 1; i < (1<<p); i++) {
        if (!(i & (i-1))) hm[i] = cnt[__builtin_ctz(i)];
        else hm[i] = hm[i&-i] + hm[i - (i&-i)];
    }

    for (int c1 = 0; c1 < p; c1++) {
        for (int c2 = 0; c2 < p; c2++) {
            for (int b = 0; b < p; b++) {
                for (int bm = 0; bm < (1<<p); bm++) if (!(bm&(1<<c1)) && !(bm&(1<<c2))) {
                    if (bm & (1<<b)) dp[c1][c2][bm] |= dp[c1][c2][bm ^ (1<<b)];
                    if (dp[c1][c2][bm]) {
                        //printf("from %c %c: %d is not ok\n", 'a'+c1, 'a'+c2, ((1<<p)-1) ^ bm);
                        ok[ ((1<<p)-1) ^ bm ] = -1;
                    }
                }
            }
        }
    }

    int ans = n;
    queue<int> q;
    q.push((1<<p)-1);
    hm[(1<<p)-1] = -1;

    while (!q.empty()) {
        int bm = q.front();
        //printf("bm %d\n", bm);
        q.pop();

        int tbm = bm;
        while (tbm) {
            int bit = tbm&-tbm;
            tbm -= bit;

            if (ok[bm^bit] != -1) {
                ok[bm^bit] = -1;
                q.push(bm^bit);
                ans = min(ans, hm[bm^bit]);
            }
        }
    }

    printf("%d\n", ans);
}


int main() {
    solve();
}