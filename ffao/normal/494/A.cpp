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

char as[110000];

int main() {
    scanf("%s", as);
    int len = strlen(as);

    int last = -1;
    int tot = 0;
    for (int j = len-1; j >= 0; j--) {
        if (as[j] == ')') tot--;
        else if (as[j] == '(') tot++;
        else if (as[j] == '#') {
            last = j;
            break;
        }
    }

    int cnt = 0;
    vector<int> ans;
    for (int i = 0; i < len; i++) {
        if (as[i] == '(') cnt++;
        else if (as[i] == ')') cnt--;
        else {
            int rem = 0;
            if (i == last) rem = cnt + tot;
            else rem = 1;

            if (rem <= 0) {
                printf("-1\n");
                return 0;
            }

            ans.push_back(rem);
            cnt -= rem;
        }

        if (cnt < 0) {
            printf("-1\n");
            return 0;
        }
    }

    if (cnt > 0) {
        printf("%d\n", -1);
        return 0;
    }

    for (int i = 0; i < ans.size(); i++) {
        printf("%d\n", ans[i]);
    }
}