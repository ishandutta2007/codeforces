#include<bits/stdc++.h>
#define maxn 1555
#define F first
#define S second

using namespace std;
const int inf=1000000000;
typedef pair<int,int> pi;
int dp[maxn][maxn],v[maxn],n,m,k,t,l,r,mid,s[maxn],cc,pos;
pi a[maxn];
void Max(int &x,int y){if (y>x) x=y;}

int solve(int x){
    for (int i=1;i<=n;i++) s[i]=s[i-1]+(v[i]<=x);
    memset(dp,0,sizeof(dp)); pos=cc=0;
    for (int i=1;i<=n;i++){
        while (pos<m&&a[pos].F==i){
            Max(cc,a[pos].S-a[pos].F+1);
            pos++;
        }
        for (int j=1;j<=m;j++){
            Max(dp[i][j],dp[i-1][j]);
            Max(dp[i][j],dp[i][j-1]);
            Max(dp[i+cc-1][j],dp[i-1][j-1]+s[i+cc-1]-s[i-1]);
        }
        if (cc) cc--;
    }
    return dp[n][t];
}

int main(){
    cin >> n >> m >> t >> k;
    for (int i=1;i<=n;i++) cin >> v[i];
    for (int i=0;i<m;i++) cin >> a[i].F >> a[i].S;
    sort(a,a+m); l=0; r=inf;
    if (solve(r)<k) {puts("-1");return 0;}
    while (r-l>1){
        mid=(l+r)/2;
        if (solve(mid)<k) l=mid; else r=mid;
    }
    cout << r << endl;
    return 0;
}