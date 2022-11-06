
#include<bits/stdc++.h>
#define rep(i,x,y) for(auto i=(x);i<=(y);++i)
#define dep(i,x,y) for(auto i=(x);i>=(y);--i)
#define fr first
#define sc second
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int>pii;
const int N=2e3+10;
const int inf=1e9;
const int mo=998244353;
char s[N],t[N];int vs[N][26],vt[N][26];
int a[N][N];
void sol(){int n;
	scanf("%d",&n);
	scanf("%s%s",s+1,t+1);
	rep(i,1,n){
		rep(j,0,25)vs[i][j]=vs[i-1][j]+(s[i]-'a'==j);
		rep(j,0,25)vt[i][j]=vt[i-1][j]+(t[i]-'a'==j);
	}
	rep(i,0,25)if(vs[n][i]!=vt[n][i]){
		printf("-1\n");return;
	}
	rep(i,0,n)rep(j,0,n)a[i][j]=n;a[0][0]=0;
	rep(i,0,n)rep(j,0,n){
		if(i&&j&&s[i]==t[j])a[i][j]=min(a[i][j],a[i-1][j-1]);
		if(j)a[i][j]=min(a[i][j],a[i][j-1]+1);
		if(i&&vs[i][s[i]-'a']<=vt[j][s[i]-'a'])a[i][j]=min(a[i][j],a[i-1][j]);
	}
	printf("%d\n",a[n][n]);
}
int main(){int t;
	scanf("%d",&t);
	rep(i,1,t)sol();
}