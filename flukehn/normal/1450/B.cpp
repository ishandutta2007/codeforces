#include<bits/stdc++.h>
using namespace std;

int main(){
#ifdef flukehn
	freopen("a.in","r",stdin);
#endif
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout<<fixed<<setprecision(12);
	int T;
	cin>>T;
	int n,k;
	while(cin>>n>>k){
		vector<int> x(n),y(n);
		for(int i=0;i<n;++i)cin>>x[i]>>y[i];
		int ans=0;
		for(int i=0;i<n;++i){
			int j;
			for(j=0;j<n;++j)
				if(abs(x[i]-x[j])+abs(y[i]-y[j])>k)break;
			if(j==n)ans=1;
		}
		cout<<(ans?"1":"-1")<<"\n";
	}
}