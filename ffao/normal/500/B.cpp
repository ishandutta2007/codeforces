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

char A[310][310];
int perm[320];
int cont[320];
int cc, n;

void dfs(int i) {
    cont[i] = cc;
    for (int j = 0; j < n; j++) {
        if (A[i][j] == '1' && !cont[j]) dfs(j);
    }
}

int main() {
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &perm[i]);
    }

    for (int i = 0; i < n; i++) {
        scanf("%s", A[i]);
    }

    for (int i = 0; i < n; i++) {
        if (cont[i] == 0) {
            cc++;
            dfs(i);

            vector<int> curr;
            for (int j = 0; j < n; j++) {
                if (cont[j] == cc) {
                    curr.push_back(perm[j]);
                }
            } 

            sort(curr.begin(), curr.end());
            int cr = 0;

            for (int j = 0; j < n; j++) {
                if (cont[j] == cc) {
                    perm[j] = curr[cr++];
                }
            }
        }
    }

    for (int i = 0; i < n; i++) {
        printf("%d ", perm[i]);
    }
}