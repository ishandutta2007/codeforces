#include<bits/stdc++.h>
using namespace std;
#define N 200020
typedef long long ll;
int n,a[N],r[N];
vector<pair<int,int> > A;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		r[a[i]]=max(r[a[i]],i);
	}
	int ans=n;
	for(int p=1,jb=1;p<=n;){
		int mx=jb;
		for(int i=p;i<=jb;++i){
			mx=max(mx,r[a[i]]);
		}
		--ans;
		if(mx==jb){
			p=++jb;
		}
		else{
			p=jb,jb=mx;
		}
	}
	cout<<ans<<'\n';
	return 0;
}