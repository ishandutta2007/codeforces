#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int INF = ~0U>>1;
typedef long long LL;
const int N = 100500;
int n,m,p;
LL a[N],s[N],t[N];
LL dp[2][N];
LL g[N],ans;
int now,pre;

LL up(int x,int y) {
    return dp[pre][x]+s[x] - (dp[pre][y]+s[y]);
}

LL down(int x, int y) {
    return x-y;
}

void init() {
    scanf("%d%d%d", &n, &m, &p);
    a[1] = 0;
    int x;
	for(int i=2; i<=n; i++) {
        scanf("%d",&x);
        a[i]=a[i-1]+x;
    }
	for(int i=1; i<=m; i++) {
        scanf("%d%d",&x,&t[i]);
        t[i]-=a[x];
    }
    sort(t+1, t+1+m);
    if(p>=m) {
		cout<<'0'<<endl;
		return;
	}
    for(int i=1;i<=m;i++) s[i]=s[i-1]+t[i];
    g[0]=0;
    memset(dp, 63, sizeof(dp));
    dp[0][0]=0;
}

int l,r,q[N];

void solve() {
    now = 0;
    for(int i=1;i<=p;i++){
        pre=now, now^=1;
        q[l]=0;l=r=0;
        for(int i=1;i<=m;i++){
            while(l<r && up(q[l+1],q[l]) <= LL( t[i] * down(q[l+1],q[l]) )  ) l++;
            dp[now][i]=dp[pre][q[l]]+ t[i]* (i-q[l]) + s[q[l]] - s[i] ;
            while(l<r && up(q[r],q[r-1]) * down(i,q[r]) > up(i,q[r]) * down(q[r],q[r-1])) r--;
            q[++r]=i;
        }
        ans = min(ans, dp[now][m]);
    }
    cout<<dp[now][m]<<endl;
}

int main() {
    init();
    solve();
    return 0;
}