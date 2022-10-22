#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int>pi;
typedef vector<int>vi;
#define ST first
#define ND second
#define PB push_back

const int MAXN = 501;
const int INF = 1000*1000*1000;
int n,k;
string s;
int dp[MAXN][MAXN];
int dp2[MAXN][MAXN];
int fll[MAXN][MAXN];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>s>>k;
    n = (int)s.size();
    for(int j=2; j<=n;j++) {
        for(int i=0; i<n;i++) {
            int p = i+j-1; if(p>=n) break;
            dp[i][p] = dp[i+1][p-1];
            if(s[i]!=s[p]) dp[i][p]++;
        }
    }
    for(int i=0; i<n;i++) {
        dp2[i][1] = dp[0][i];
        fll[i][1] = 0;
    }
    for(int i=0; i<n;i++) {
        for(int j=2; j<=k;j++) {
            dp2[i][j] = dp2[i][j-1];
            fll[i][j] = fll[i][j-1];
            for(int ii=1; ii<=i; ii++) {
                if(dp2[i][j]>dp[ii][i]+dp2[ii-1][j-1]) {
                    dp2[i][j] = dp[ii][i]+dp2[ii-1][j-1];
                    fll[i][j] = ii;
                }
            }
        }
    }
    int pos = n-1,lvl=k;
    vi seq;
    while(pos>-1) {
        seq.PB(pos);
        pos = fll[pos][lvl];
        lvl--;
        seq.PB(pos);
        pos--;
    }
    vector<char>pom;
    for(int i=0; i<seq.size();i++) {
        int x = seq[i], y=seq[i+1], cen = (x+y+1)/2;
        for(int j=x; j>=cen;j--) pom.PB(s[j]);
        if((x-y+1)%2==1) cen++;
        for(int j=cen; j<=x; j++) pom.PB(s[j]);
        if(i+2!=seq.size()) pom.PB('+');
        i++;
    }
    reverse(pom.begin(),pom.end());
    cout<<dp2[n-1][k]<<"\n";
    for(auto it:pom) cout<<it;
}