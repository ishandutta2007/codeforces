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

#define MAXN 3500
#define MAXM 1100

//tudo indexado a partir de 0 agora!!! 
char t[MAXN]; 
//string onde se quer achar o padro 
char p[MAXM]; 
//padro 
int pos[MAXM]; 
//funo de transio 
int n, m; //tamanhos do texto e padro 

int dp[3100];
int dp2[3100][3100];

int gt(int a, int b) {
    if (a == n) {
        return b==0 ? 0 : -INF;
    }

    int &ret = dp2[a][b];
    if (ret == -1) {
        ret = gt(a+1, b);
        if (b) ret = max(ret, gt(a+1,b-1));

        if (dp[a] != -1 && dp[a] <= b) {
            ret = max(ret, 1+gt(a+m+dp[a], b-dp[a]));
        }
    }
    return ret;
}

int main() {
    memset(dp2,-1,sizeof(dp2));

    scanf("%s %s", t, p);
    n = strlen(t);
    m = strlen(p);

    int i, j; 

    for (int st=0 ; st<n; st++) {
        dp[st]=-1;
        i=st;
        j=-1;
        int cnt = 0;
        for ( i=st; i<n; i++ ) {
            if (t[i]!=p[j+1]) cnt++;
            else {
                j++;
                if (j==m-1) {
                    dp[st]=cnt;
                    break;
                }
            }
        }
    }

    for (int i=0; i<=n; i++) {
        printf("%d ", gt(0, i));
    }
}