#include<bits/stdc++.h>
using namespace std;
#define N 200020
#define M 125
typedef long long ll;
typedef array<int,6> A6;
int n,m,id[N],cnt,a[N],tr[M][M];
A6 g[M];
int Get(const A6 &a){
	int t=0;
	for(int i=1;i<=m;++i){
		t=t*10+a[i];
	}
	return t;	
}
A6 operator + (const A6 &a,const A6 &b){
	A6 c;
	for(int i=1;i<=m;++i){
		c[i]=a[b[i]];	
	}
	return c;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	static A6 p;
	for(int i=1;i<=m;++i)p[i]=i;
	do{
		id[Get(p)]=++cnt;
		g[cnt]=p;
	}while(next_permutation(p.begin()+1,p.begin()+m+1));
	for(int i=1;i<=cnt;++i){
		for(int j=1;j<=cnt;++j){
			tr[i][j]=id[Get(g[i]+g[j])];
		}
	}
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			cin>>p[j];	
		}
		a[i]=id[Get(p)];
	}
	A6 tmp;
	for(int i=1;i<=m;++i){
		tmp[i]=i;
	}
	a[0]=1;
	vector<int> A;
	A.push_back(0);
	ll ans=0;
	for(int i=1;i<=n;++i){
		static int vis[M];
		vector<int> st({1}),B;
		vis[1]=1;
		A.push_back(i);
		int las=0;
		for(int j=(int)A.size()-1;j>=1;--j){
			for(int k=0;k<(int)st.size();++k){
				function<void(int)> Insert=[&](int x)->void{
					if(vis[x])return;
					vis[x]=1;
					st.push_back(x);
					for(int z=(int)A.size()-1;z>j;--z){
						Insert(tr[x][a[A[z]]]);		
					}
				};
				Insert(tr[st[k]][a[A[j]]]);
			}
			ans+=(A[j]-A[j-1])*st.size();
			if(st.size()!=las){
				las=st.size();
				B.push_back(A[j]);
			}
		}
		for(auto x:st)vis[x]=0;
		B.push_back(0);
		reverse(B.begin(),B.end());
		A=B;
	}
	cout<<ans<<'\n';
	return 0;
}