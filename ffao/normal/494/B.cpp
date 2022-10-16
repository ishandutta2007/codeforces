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

const int MAXN = 110000, MAXM = 110000;

char t[MAXN]; 
char p[MAXM]; 
int pos[MAXM]; 
int ways[MAXN];
int sumways[MAXN];
int firstmatch[MAXN];
int n, m;

void func(){ int i, j=-1; pos[0]=-1; for( i=1 ; i<m ; i++ ){ while( j>=0 && p[j+1]!=p[i] ) j=pos[j]; if( p[j+1]==p[i] ) j++; pos[i]=j; } } 
vector<int> kmp(){ vector<int> ans; int i, j=-1; for( i=0 ; i<n ; i++ ){ while( j>=0 && t[i]!=p[j+1] ) j=pos[j]; if( t[i]==p[j+1] ) j++; if( j==m-1 ){ ans.push_back(i-m+1); j=pos[j]; } } return ans; }

const int mod = 1000000007;

int main() {
    scanf("%s %s", t, p);
    n = strlen(t);
    m = strlen(p);

    func();
    vector<int> matches = kmp();

    int maa = matches.size() - 1;

    firstmatch[n] = n+1;
    for (int j = n-1; j >= 0; j--) {
        firstmatch[j] = firstmatch[j+1];
        if (maa >= 0 && matches[maa] == j) {
            firstmatch[j] = j+m;
            maa--;
        }
    }

    ways[n] = 1;
    sumways[n] = 1;
    for (int j = n-1; j >= 0; j--) {
        ways[j] = (ways[j+1] + sumways[firstmatch[j]]) % mod;
        sumways[j] = (sumways[j+1] + ways[j]) % mod;
    }

    ways[0] = (ways[0]+mod-1)%mod;
    printf("%d\n", ways[0]);
}