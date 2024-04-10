#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define SZ(x) ((int)(x).size())
#define fi first
#define se second
typedef vector<int> VI;
typedef long long ll;
typedef pair<int,int> PII;
const ll mod=1000000007;
ll powmod(ll a,ll b) {ll res=1;a%=mod;for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
// head

int n,p,fg;
char c[1010],s[1010];
void dfs(int u,bool fg) {
	if (u==n) {
		if (fg) {
			puts(c);
			throw 0;
		} 
	} else {
		if (fg) {
			rep(i,'a','a'+p) {
				if ((u==0||i!=c[u-1])&&(u<=1||i!=c[u-2])) {
					c[u]=i;
					dfs(u+1,1);
				}
			}
		} else {
			rep(i,s[u],'a'+p) {
				if ((u==0||i!=c[u-1])&&(u<=1||i!=c[u-2])) {
					c[u]=i;
					dfs(u+1,s[u]!=i);
				}
			}
		}
	}
}
int main() {
	scanf("%d%d",&n,&p);
	scanf("%s",s);
	try {
		dfs(0,0);
	} catch(int e) {
		fg=1;
	}
	if (!fg) puts("NO");
}