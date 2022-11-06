#include<bits/stdc++.h>
using namespace std;
const int N=1e6+11;
char s[N],t[N];
int f[N];
int n,m;
int main(){
#ifdef flukehn
	freopen("c.in","r",stdin);
#endif
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T=1;//cin>>T;
	while(cin>>n>>m){
		cin.getline(s,N);
		for(int i=1;i<=m;++i)f[i]=0;
		cin.getline(s+1,N);
		for(int i=1;i<n;++i){
			for(int j=1;j<=m;++j)t[j]=s[j];
			cin.getline(s+1,N,'\n');
			for(int j=2;j<=m;++j)if(s[j-1]=='X'&&t[j]=='X')++f[j];
		}
		for(int i=1;i<=m;++i)f[i]+=f[i-1];
		int Q;
		cin>>Q;
		while(Q--){
			int x,y;
			cin>>x>>y;
			cout<<(f[x]==f[y]?"YES":"NO")<<"\n";
		}
	}
}