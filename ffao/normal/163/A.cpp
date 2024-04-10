#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
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
int N, M;

#define INF 1000000000
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REP(i,n) FOR(i,0,n)
#define pb push_back
#define itr iterator
#define sz size()

#define MOD 1000000007

int tab[5010];
int curr[5010];
char s1[5010], s2[5010];

int main() {
    gets(s1);
    gets(s2);
    int l1 = strlen(s1);
    int l2 = strlen(s2);    
    
    int tot = 0;
    REP(i,l2) {
        REP(j, l1) {
            curr[j+1] = ((s1[j]==s2[i])? 1 + tab[j] : 0) % MOD;
            tot = (tot + curr[j+1]) % MOD;
        }
        
        REP(j, l1) {
            tab[j+1] = (tab[j+1] + curr[j+1]) % MOD;
        }
    }
    
    printf("%d\n",tot);
    
}