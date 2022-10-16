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

long long counts[10][110000];
long long tot[10][110000];
char a[110000];
int queryfrom[110000];
char thq[110000];
string queryto[110000];
int q;

const int mod = 1000000007;

long long mypow(long long exp) {
    if (exp == 0) return 1;
    else if (exp == 1) return 10;

    long long mid = mypow(exp/2);
    mid = (mid*mid) % mod;
    if (exp&1) {
        mid = (mid * 10) % mod;
    }

    return mid;
}

int main() {
    scanf("%s", a);
    int len = strlen(a);

    scanf("%d", &q); gets(thq);
    for (int i = 0; i < q; i++) {
        gets(thq);
        queryfrom[i] = thq[0]-'0';
        //printf("%s\n", thq);
        queryto[i] = (thq+3);
    }

    for (int d = 0; d < 10; d++) {
        counts[d][q] = 1;
        tot[d][q] = d;
    }

    for (int rem = q-1; rem >= 0; rem--) {
        for (int d = 0; d < 10; d++) {
            if (queryfrom[rem] == d) {
                counts[d][rem] = 0;
                for (int i = 0; i < queryto[rem].size(); i++) {
                    counts[d][rem] = (counts[d][rem] + counts[queryto[rem][i]-'0'][rem+1]) % 1000000006;
                }
            }
            else {
                counts[d][rem] = counts[d][rem+1];
            }
        }
    }

    for (int rem = q-1; rem >= 0; rem--) {
        for (int d = 0; d < 10; d++) {
            if (queryfrom[rem] == d) {
                tot[d][rem] = 0;
                long long pot = 0;
                for (int i = queryto[rem].size()-1; i >= 0; i--) {
                    long long inc = (tot[queryto[rem][i]-'0'][rem+1] * mypow(pot)) % 1000000007;
                    tot[d][rem] = (tot[d][rem] + inc) % 1000000007;

                    pot = (pot + counts[queryto[rem][i]-'0'][rem+1]) % 1000000006;
                }
            }
            else {
                tot[d][rem] = tot[d][rem+1];
            }
        }
    }

    //printf("%s\n", queryto[0].c_str());
    //printf("%d\n", queryfrom[0]);

    long long ans = 0;
    long long pot = 0;
    for (int i = len-1; i >= 0; i--) {
        long long inc = (tot[a[i]-'0'][0] * mypow(pot)) % 1000000007;
        ans = (ans + inc) % 1000000007;

        pot = (pot + counts[a[i]-'0'][0]) % 1000000006;
    }

    cout << ans << endl;
}