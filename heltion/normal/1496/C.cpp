#include <bits/stdc++.h>
using namespace std;
#define dbgv(v) cout<<'>'<< #v <<':';for(auto ii:v)cout<<ii<<' ';cout<<endl;
#define dbg(x) cout<<'>'<< #x <<':'<< x <<endl;
#define int long long

void run_case(){
	int n;
	cin>>n;
	vector<double> x,y;
	for(int i =0;i<2*n;i++){
	    int uu,vv;
	    cin>>uu>>vv;
		double u,v;
		u=uu;
		v=vv;
		if(u<0)u = -u;
		if(v<0)v = -v;
		if(u==0.0)y.push_back(v);
		else x.push_back(u);
	}
	sort(x.begin(),x.end());
	sort(y.begin(),y.end());
	
	long double ans = 0.0;
	
	for(int i =0;i<n;i++){
		ans += sqrt(y[i]*y[i] + x[i]*x[i]);
	}
	cout<<fixed<<setprecision(20)<<ans<<endl;
	
}

signed main(){
ios_base::sync_with_stdio(false);
cin.tie(0);cout.tie(0);int tc=1;
cin>>tc;
while(tc--)run_case();
return 0;
}