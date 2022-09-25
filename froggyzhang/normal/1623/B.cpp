#include<bits/stdc++.h>
using namespace std;
#define N 2333
typedef long long ll;
int n,l[N],r[N],p[N],del[N];
void Solve(){
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>l[i]>>r[i];
		del[i]=l[i];
		p[i]=i;
	}
	sort(p+1,p+n+1,[&](int i,int j){return r[i]-l[i]>r[j]-l[j];});
	for(int i=1;i<=n;++i){
		int u=p[i];
		for(int j=i-1;j>=1;--j){
			int v=p[j];
			if(l[u]>=l[v]&&r[u]<=r[v]){
				if(l[u]==l[v])del[v]=r[u]+1;
				else del[v]=l[u]-1;
				break;
			}
		}
	}
	for(int i=1;i<=n;++i){
		cout<<l[i]<<' '<<r[i]<<' '<<del[i]<<'\n';
	}
	cout<<'\n';
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--)Solve();
	return 0;
}