#include <iostream>
#include <cstdio>

#include <string>
#include <cassert>

using namespace std;

typedef long long ll;
#define tc(x) static_cast<char>(x)

const int MAXN = 200 + 10;
const int MAXM = 200 + 10;
const ll INF = 1e18 + 1e9;

int N, M;
ll K, t;

int z[MAXM];
int As[MAXM][2];
ll v[MAXM][MAXM];
int Af[MAXM][MAXM];
void build(const string& s, bool output = false) {
    z[0] = 0;
    for(int i = 1;i < s.size();i++) {
        z[i] = z[i - 1];
        while(z[i] != 0 and s[i] != s[z[i]]) z[i] = z[z[i] - 1];
        if(s[z[i]] == s[i]) z[i]++;
    }
    //for(int i = 0;i < s.size();i++) printf("%d\n", z[i]);
    for(int i = 0;i <= s.size();i++) {
        for(int j = 0;j < 2;j++) {
            As[i][j] = i;
            while(As[i][j] != 0 and tc(j + 48) != s[As[i][j]]) As[i][j] = z[As[i][j] - 1];
            if(s[As[i][j]] == tc(j + 48)) As[i][j]++;
        }
    }
    //for(int i = 0;i <= s.size();i++) printf("%d: %d %d\n", i, As[i][0], As[i][1]);
    for(int i = 0;i <= 1;i++) {
        for(int j = 0;j <= s.size();j++) {
            Af[i][j] = As[j][i];
            if(Af[i][j] == s.size()) v[i][j] = 1; else v[i][j] = 0;
        }
    }
    for(int i = 2;i <= N;i++) {
        for(int j = 0;j <= s.size();j++) {
            Af[i][j] = Af[i - 1][Af[i - 2][j]];
            v[i][j] = (t = v[i - 2][j] + v[i - 1][Af[i - 2][j]]) < INF ? t : INF;
        }
    }
    if(output) for(int i = 0;i <= N;i++, printf("\n")) for(int j = 0;j <= s.size();j++) printf("%lld ", static_cast<ll>(v[i][j]));
}

int main() {
    scanf("%d%lld%d", &N, &K, &M);      //reduce K to 1
    
    string ans = "";
    for(int i = 0;i < M;i++) {
        if(i) {
            build(ans);
            if(Af[N][0] == i) {
                assert(K >= 1);
                if(K == 1) break;
                else K--;
            }
        }
        
        build(ans + '0');
        
        if(K > v[N][0]) {
            K -= v[N][0];
            ans += '1';
        } else ans += '0';
        
        //cerr << i << " " << K << "\n";
    }
    printf("%s\n", ans.c_str());
    
    //build("0", true);
    
    return 0;
}