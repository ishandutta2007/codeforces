#include<bits/stdc++.h>
using namespace std;
int main(){
#ifdef flukehn
	freopen("a.in","r",stdin);
#endif
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout<<fixed<<setprecision(12);
	int n;
	while(cin>>n){
		vector<int> a(n);
		for(int i=0;i<n;++i)cin>>a[i];
		sort(a.begin(),a.end());
		int ans=0;
		for(int i=0;i<n-2;++i)
			if(a[i+2]<a[i]+a[i+1])ans=1;
		puts(ans?"YES":"NO");
	}
}