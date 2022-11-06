#include<bits/stdc++.h>
using namespace std;
const int N=1e5+11;
pair<int,int> a[N];
int rk[N];
int n,k;
int main(){
#ifdef flukehn
	freopen("b.in","r",stdin);
#endif
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--){
		cin>>n>>k;
		for(int i=1;i<=n;++i)
			cin>>a[i].first,a[i].second=i;
		sort(a+1,a+n+1);
		for(int i=1;i<=n;++i)rk[a[i].second]=i;
		int tot=0,p=-1;
		for(int i=1;i<=n;p=rk[i++])
			if(rk[i]!=p+1)
				++tot;
		cout<<(tot<=k?"Yes":"No")<<"\n";
	}
}