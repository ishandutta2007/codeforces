#include<bits/stdc++.h>
using namespace std;
const int N=1010;
int mod;
int qpow(int a,int b) {
	int ans=1;
	while(b) {
		if(b&1)ans=1ll*ans*a%mod;
		a=1ll*a*a%mod;
		b>>=1;
	}
	return ans;
}
struct mat {
	int v[N][N];
	int calc(int n) {
		int ans=1;
		for(int i=1;i<=n;i++) {
			int k=-1;
			for(int j=i;j<=n&&k==-1;j++)
				if(v[j][i])k=j;
			swap(v[i],v[k]);
			if(i!=k)ans=mod-ans;
			ans=1ll*ans*v[i][i]%mod;
			for(int j=i+1;j<=n;j++) {
				int t=1ll*v[j][i]*qpow(v[i][i],mod-2)%mod;
				for(int k=i;k<=n;k++)
					v[j][k]=(v[j][k]-1ll*t*v[i][k]%mod+mod)%mod;
			}
		}
		return ans;
	}
}A,B;
char s[N][N];
int fa[N*N],G[N*N],cnt[2];
int get(int x) {
	return x==fa[x]?x:fa[x]=get(fa[x]);
}
void merge(int a,int b) {
	// cerr<<a<<' '<<b<<endl;
	int p=get(a),q=get(b);
	if(p==q)return;
	fa[p]=q;
}
void add(int a,int b,int f) {
	a=G[get(a)],b=G[get(b)];
	if(f) {
		B.v[a][b]--;
		B.v[b][a]--;
		B.v[a][a]++;
		B.v[b][b]++;
	} else {
		A.v[a][b]--;
		A.v[b][a]--;
		A.v[a][a]++;
		A.v[b][b]++;
	}
}
#define bh(i,j) (((i)-1)*(m+1)+(j))
int main() {
	int n,m;
	scanf("%d%d%d",&n,&m,&mod);
	for(int i=1;i<=n;i++)
		scanf("%s",s[i]+1);
	for(int i=1;i<=(n+1)*(m+1);i++)
		fa[i]=i;
	for(int i=1;i<=n;i++) {
		for(int j=1;j<=m;j++) {
			if(s[i][j]=='/')merge(bh(i+1,j),bh(i,j+1));
			else if(s[i][j]=='\\')merge(bh(i,j),bh(i+1,j+1));
		}
	}
	for(int i=1;i<=(n+1);i++)
		for(int j=1;j<=(m+1);j++)
			if(fa[bh(i,j)]==bh(i,j))G[bh(i,j)]=++cnt[(i&1)^(j&1)];
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if(s[i][j]=='*') {
				int f=(i&1)^(j&1);
				add(bh(i,j),bh(i+1,j+1),f);
				add(bh(i,j+1),bh(i+1,j),f^1);
			}
	cout<<(A.calc(cnt[0]-1)+B.calc(cnt[1]-1))%mod<<endl;
	return 0;
}