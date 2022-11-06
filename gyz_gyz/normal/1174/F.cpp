#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define dep(i,x,y) for(int i=(x);i>=(y);--i)
#define see(x) (cerr<<(#x)<<'='<<(x)<<endl)
#define pb push_back
#define fr first
#define sc second
using namespace std;
typedef long long ll;
const int N=2e5+10;
const int mo=1e9+7;
int s[N],f[N],h[N],ms[N],ed[N];vector<int>p[N];
void dfs(int x){s[x]=1;
	for(auto i:p[x])if(i!=f[x]){
		f[i]=x;h[i]=h[x]+1;
		dfs(i);s[x]+=s[i];
		if(s[i]>s[ms[x]])ms[x]=i;
	}
	ed[x]=ms[x]?ed[ms[x]]:x;
}
int main(){int n;
	scanf("%d",&n);
	rep(i,1,n-1){int x,y;
		scanf("%d%d",&x,&y);
		p[x].pb(y);p[y].pb(x);
	}dfs(1);int H,x=1;
	printf("d 1\n");fflush(stdout);scanf("%d",&H);
	if(!H)return printf("! 1\n"),0;
	for(;;){int d=ed[x],md;
		printf("d %d\n",d);fflush(stdout);scanf("%d",&md);
		while(H+h[d]-h[x]*2>md)x=ms[x];
		if(h[x]==H)return printf("! %d\n",x),0;
		printf("s %d\n",x);fflush(stdout);scanf("%d",&x);
	}
}