#include<bits/stdc++.h>
using namespace std;
int n,m;
const int N=311;
int a[N];
int main(){
#ifdef flukehn
	freopen("a.in","r",stdin);
#endif
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T;cin>>T;
	while(cin>>n>>m){
		for(int i=1;i<=m;++i)cin>>a[i];
		int ans=0;
		for(int i=1;i<=m;++i)
			for(int j=1;j<i;++j)
				if(a[i]>a[j])++ans;
		cout<<ans<<"\n";
	}
}