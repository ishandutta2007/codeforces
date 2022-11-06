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

const int N=101000;
string t[N];
char s[N];
ll len[20],val[20];
int n;
int main() {
	scanf("%s",s);
	scanf("%d",&n);
	rep(i,0,n) cin>>t[i];
	rep(i,0,10) len[i]=1,val[i]=i;
	per(i,0,n) {
		int l=t[i][0]-'0';
		ll le=0,va=0;
		rep(j,3,SZ(t[i])) {
			int r=t[i][j]-'0';
			va=(va*powmod(10,len[r])+val[r])%mod;
			le=le+len[r];
		}
		len[l]=le%(mod-1);
		val[l]=va%mod;
	}
	ll va=0;
	int lenn=strlen(s);
	rep(i,0,lenn) {
		int r=s[i]-'0';
		va=(va*powmod(10,len[r])+val[r])%mod;
	}
	printf("%I64d\n",va);
}