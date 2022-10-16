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
int sc[110000][2];
int tally[2];
int winner;

int advance(int curr, int t) {
    int st = curr, end = n;

    while (st < end) {
        int mid = (st+end)/2;

        int sum0 = sc[mid][0] - sc[curr-1][0];
        int sum1 = sc[mid][1] - sc[curr-1][1];
        int big = max(sum0, sum1);

        if (big >= t) end = mid;
        else st = mid+1;
    }

    int sum0 = sc[st][0] - sc[curr-1][0];
    int sum1 = sc[st][1] - sc[curr-1][1];

    if (sum0 == t) tally[0]++;
    if (sum1 == t) tally[1]++;
    return st+1;
}

int main() {
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        int a;
        scanf("%d", &a); a--;
        sc[i][0] = sc[i-1][0];
        sc[i][1] = sc[i-1][1];
        sc[i][a]++;
        winner = a;
    }

    vector< pair<int, int> > ans;

    for (int t = 1; t <= n; t++) {
        int curr = 1;
        tally[0] = tally[1] = 0;

        while (1) {
            int os0 = tally[0], os1 = tally[1];
            curr = advance(curr, t);

            if (os0 == tally[0] && os1 == tally[1]) break;
            if (curr == n+1) {
                if (tally[winner] > tally[1-winner]) {
                    ans.push_back(mp(tally[winner], t));
                }
                break;
            }
        }
    }
    
    sort(ans.begin(), ans.end());
    printf("%d\n", ans.size());
    for (int i = 0; i < (int)ans.size(); i++) {
        printf("%d %d\n", ans[i].first, ans[i].second);
    }
}