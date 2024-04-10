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

char s[110000];
int cnt[1100];

int main() {
    scanf("%d", &n);
    scanf("%s", s);

    for (int i = 0; i < n; i++) {
        cnt[s[i]]++;
    }   

    int tt = 0;
    int b = *max_element(cnt, cnt+1100);
    for (char c = 'A'; c <= 'Z'; c++) {
        if (cnt[c] == b) {
            tt++;
        }
    }

    long long ans = 1;
    for (int i = 0; i < n; i++) {
        ans = (ans * tt) % 1000000007;
    }

    printf("%d\n", (int)ans);
}