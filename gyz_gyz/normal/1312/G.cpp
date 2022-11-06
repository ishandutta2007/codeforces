#include<bits/stdc++.h>
#define rep(i,x,y) for(auto i=(x);i<=(y);++i)
#define dep(i,x,y) for(auto i=(x);i>=(y);--i)
#define fr first
#define sc second
using namespace std;
typedef long long ll;
const int N=1e6+10;
const int inf=1e9;
const int mo=998244353;
int a[N],b[N],s[N],q[N],t[26][N];
void dfs(int x){
	b[x]=min(b[x],a[x]);
	if(s[x])a[x]=min(a[x],b[x]+1);
	rep(i,0,25)if(t[i][x]){int j=t[i][x];
		a[j]=min(a[j],a[x]+1);
		b[j]=min(b[j],b[x]+s[x]);
		dfs(j);s[x]+=s[j];
	}
}
char c[9];
int main(){int n;
	scanf("%d",&n);
	rep(i,1,n){int x;
		scanf("%d %s",&x,c);
		t[c[0]-'a'][x]=i;
	}
	int m;scanf("%d",&m);
	rep(i,1,m){
		scanf("%d",&q[i]);
		++s[q[i]];
	}
	rep(i,1,n)a[i]=b[i]=inf;dfs(0);
	rep(i,1,m)printf("%d%c",a[q[i]],i==m?'\n':' ');
}