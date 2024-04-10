#include<bits/stdc++.h>
using namespace std;

int main(){
#ifdef flukehn
	freopen("a.in","r",stdin);
#endif
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout<<fixed<<setprecision(12);
	//int T;cin>>T;
	int n;
	while(cin>>n){
		vector<int> x(n),y(n);
		for(int i=0;i<n;++i)cin>>x[i]>>y[i];
		auto wk= [&](){
			if(n<2) return -1;
			if(n>2) {
				sort(x.begin(),x.end());
				sort(y.begin(),y.end());
				return (x[n-1]-x[0])*(y[n-1]-y[0]);
			}
			return (x[0]!=x[1]&&y[0]!=y[1]) ? abs(x[1]-x[0]) * abs(y[1]-y[0]) : -1;
		};
		cout<<wk()<<"\n";
	}
}