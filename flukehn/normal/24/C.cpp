#include<bits/stdc++.h>
using namespace std;

int main(){
#ifdef flukehn
	freopen("a.in","r",stdin);
#endif
	ios::sync_with_stdio(0);cin.tie(0);
	int n;
	long long m;
	long long u,v;
	while(cin>>n>>m){
		cin>>u>>v;
		vector<int> x(n),y(n);
		for(int i=0;i<n;++i)cin>>x[i]>>y[i];
		m%=2*n;
		for(int i=0;i<m;++i){
			int j=i%n;
			u=2*x[j]-u;
			v=2*y[j]-v;
		//	cerr<<u<<" "<<v<<endl;
		}
		cout<<u<<" "<<v<<endl;
	}
}