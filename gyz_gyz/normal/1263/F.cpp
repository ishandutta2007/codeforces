#include<bits/stdc++.h>
#define rep(i,x,y) for(auto i=(x);i<=(y);++i)
#define dep(i,x,y) for(auto i=(x);i>=(y);--i)
using namespace std;
typedef long long ll;
const int N=2e3+10;
const int inf=1e9;
int tt1,tt2,a[N][N];vector<int>p1[N],p2[N];
int t1[N],t2[N],id1[N],id2[N],sz1[N],sz2[N],dfn1[N],dfn2[N];
void dfs1(int x){sz1[x]=1;
	for(auto&i:p1[x]){
		dfs1(i);sz1[x]+=sz1[i];
		t1[x]=min(t1[x],t1[i]);
	}
}
void ddfs1(int x){
	id1[x]=++tt1;dfn1[tt1]=x;
	sort(p1[x].begin(),p1[x].end(),[](int x,int y){return t1[x]<t1[y];});
	for(auto&i:p1[x])ddfs1(i);
}
void dfs2(int x){sz2[x]=1;
	for(auto&i:p2[x]){
		dfs2(i);sz2[x]+=sz2[i];
		t2[x]=min(t2[x],t2[i]);
	}
}
void ddfs2(int x){
	id2[x]=++tt2;dfn2[tt2]=x;
	sort(p2[x].begin(),p2[x].end(),[](int x,int y){return t2[x]<t2[y];});
	for(auto&i:p2[x])ddfs2(i);
}
int main(){int n,n1,n2;
	scanf("%d%d",&n,&n1);
	rep(i,0,n1)t1[i]=n+1;
	rep(i,2,n1){int x;
		scanf("%d",&x);p1[x].push_back(i);
	}
	rep(i,1,n){int x;
		scanf("%d",&x);t1[x]=i;
	}
	dfs1(1);ddfs1(1);
	scanf("%d",&n2);
	rep(i,0,n2)t2[i]=n+1;
	rep(i,2,n2){int x;
		scanf("%d",&x);p2[x].push_back(i);
	}
	rep(i,1,n){int x;
		scanf("%d",&x);t2[x]=i;
	}
	dfs2(1);ddfs2(1);
	rep(i,1,n1+1)rep(j,1,n2+1){
		if(i<=n1){
			if(i!=1&&t1[dfn1[i]]>=t2[dfn2[j]])
				a[i+sz1[dfn1[i]]][j]=max(a[i+sz1[dfn1[i]]][j],a[i][j]+sz1[dfn1[i]]);
			a[i+1][j]=max(a[i+1][j],a[i][j]);
		}
		if(j<=n2){
			if(j!=1&&t2[dfn2[j]]>=t1[dfn1[i]])
				a[i][j+sz2[dfn2[j]]]=max(a[i][j+sz2[dfn2[j]]],a[i][j]+sz2[dfn2[j]]);
			a[i][j+1]=max(a[i][j+1],a[i][j]);
		}
	}
	printf("%d\n",a[n1+1][n2+1]);
}