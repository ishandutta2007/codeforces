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


void re(int& x);


template<class T, class... Ts> void re(T& t, Ts&... ts);


#define rep(i, a, b) for(int i = a; i < (b); ++i)


int n;
vector<int> g[51];
int sz[51];
double probs[55][55][55];
double dp[55][55][55][55];
double totprob[55][55][5];

void merge(int a, int b) {
    memset(totprob,0,sizeof(totprob));

    totprob[0][0][0]=1;
    for (int took_a = 0; took_a <= sz[a]; took_a++) {
        for (int took_b = 0; took_b <= sz[b]; took_b++) {
            for (int merged_b = 0; merged_b <= 1; merged_b++) {
                int rem_a = (sz[a]-took_a);
                int rem_b = (sz[b]-took_b);
                double tot = rem_a + rem_b + !merged_b;

                double pick_a = rem_a / tot;
                double pick_b = rem_b / tot;
                double pick_m = (!merged_b) / tot;
                
                if (rem_a) totprob[took_a+1][took_b][merged_b] += totprob[took_a][took_b][merged_b] * pick_a;
                if (rem_b) totprob[took_a][took_b+1][merged_b] += totprob[took_a][took_b][merged_b] * pick_b;
                if (!merged_b) totprob[took_a][took_b][merged_b+1] += totprob[took_a][took_b][merged_b] * pick_m;
            }
        }
    }
    
    for (int from = sz[a]+sz[b]+1; from >= 0; from--) {//from <= sz[a]+sz[b]+1; from++) {
        for (int took_a = 0; took_a <= sz[a]; took_a++) {
            for (int took_b = from-took_a-1; took_b <= sz[b]; took_b++) {
                for (int merged_a = 0; merged_a <= min(from,took_a); merged_a++) {
                    for (int merged_b = 0; merged_b <= took_b+1; merged_b++) {
                        dp[took_a][took_b][merged_a][merged_b]=0;
                    }
                }
            }
        }

        for (int took_a = 0; took_a <= sz[a]; took_a++) {
            for (int took_b = 0; took_b <= sz[b]; took_b++) {
                for (int merged_a = 0; merged_a <= min(from,took_a); merged_a++) {
                    for (int merged_b = 0; merged_b <= took_b+1; merged_b++) {
                        if (took_a + took_b + !!merged_b < from) continue;
                        if (took_a + took_b + !!merged_b == from) {
                            dp[took_a][took_b][merged_a][merged_b] = 0;
                            if (merged_b) dp[took_a][took_b][took_a][took_b+1] = totprob[took_a][took_b][1];
                            else dp[took_a][took_b][took_a][0] = totprob[took_a][took_b][0];
                        }
                        
                        int rem_a = (sz[a]-took_a);
                        int rem_b = (sz[b]-took_b);
                        double tot = rem_a + rem_b + !merged_b;

                        double pick_a = rem_a / tot;
                        double pick_b = rem_b / tot;
                        double pick_m = (!merged_b) / tot;

                        if (rem_a) dp[took_a+1][took_b][merged_a][merged_b] += dp[took_a][took_b][merged_a][merged_b] * pick_a * probs[a][merged_a][took_a+1] / probs[a][merged_a][took_a];
                        if (rem_b) {
                            if (merged_b) dp[took_a][took_b+1][merged_a][merged_b] += dp[took_a][took_b][merged_a][merged_b] * pick_b * probs[b][merged_b-1][took_b+1] / probs[b][merged_b-1][took_b];
                            else dp[took_a][took_b+1][merged_a][merged_b] += dp[took_a][took_b][merged_a][merged_b] * pick_b;
                        }
                        if (!merged_b) dp[took_a][took_b][merged_a][took_b+1] += dp[took_a][took_b][merged_a][merged_b] * pick_m * 0.5;
                    }
                }
            }
        }
        
        for (int j = from; j <= sz[a]+sz[b]+1; j++) {
            probs[a][from][j] = 0;
        } 

        for (int took_a = 0; took_a <= sz[a]; took_a++) {
            for (int took_b = from-took_a-1; took_b <= sz[b]; took_b++) {
                for (int merged_a = 0; merged_a <= min(from,took_a); merged_a++) {
                    for (int merged_b = 0; merged_b <= took_b+1; merged_b++) {
                        if (took_a + took_b + !!merged_b >= from) {
                            probs[a][from][took_a+took_b+!!merged_b] += dp[took_a][took_b][merged_a][merged_b];
                        }
                    }
                }
            }
        }
    }

    sz[a] += sz[b]+1;
}

void dfs(int v, int p) {
    sz[v] = 0;
    for (int x : g[v]) if (x != p) {
        dfs(x,v);
        merge(v, x);
    }
}

void solve()
{
    re(n);
    if (n == 1) {
        printf("1.0\n");
        return;
    }

    rep(i,0,n-1) {
        int a,b;
        re(a,b); a--; b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    rep(i,0,n) {
        dfs(i,-1);

        //for (int j = 0; j < n; j++) printf("%.15f ", probs[i][j]);
        // printf("\n"); 
        printf("%.15f\n", probs[i][0][n-1]);
    }
}


int main() {


    solve();
}


void re(int& x) { scanf("%d", &x); }


template<class T, class... Ts> void re(T& t, Ts&... ts) { 
    re(t); re(ts...); 
}