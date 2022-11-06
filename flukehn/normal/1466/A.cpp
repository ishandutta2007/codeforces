#include<bits/stdc++.h>
using namespace std;

int main(){
#ifdef flukehn
	freopen("a.in","r",stdin);
#endif
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--){
		int n;
		cin>>n;
		vector<int> a(n);
		for(int i=0;i<n;++i)cin>>a[i];
		set<int> s;
		for(int i=0;i<n;++i)
		for(int j=i+1;j<n;++j)
			s.insert(a[j]-a[i]);
		cout<<s.size()<<"\n";
	}
}