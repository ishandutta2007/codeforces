#include<bits/stdc++.h>
using namespace std;
#define N 200020
typedef long long ll;
int n,a[N],b[N],m,l[N],r[N],ans[N];
void Solve(){
	cin>>n>>m;
	ll tot=0;
	for(int i=1;i<=n;++i){
		cin>>a[i]>>b[i];
		tot+=a[i]-b[i]+m;
		l[i]=max(0,m-b[i]);
		r[i]=min(a[i],m);
		tot-=2*l[i];
		ans[i]=l[i];
	}
	for(int i=1;i<=n;++i){
		if(tot>0){
			int jb=min(tot/2,(ll)r[i]-l[i]);
			ans[i]+=jb;
			tot-=2*jb;	
		}
	}
	cout<<llabs(tot)<<'\n';
	for(int i=1;i<=n;++i){
		cout<<ans[i]<<' '<<m-ans[i]<<'\n';
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--)Solve();
	return 0;
}