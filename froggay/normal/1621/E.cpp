#include<bits/stdc++.h>
using namespace std;
#define N 100010
typedef long long ll;
int n,m,a[N],rk[N],s[N],need[N];
vector<int> b[N];
ll tot[N];
int Get(ll tot,int sz){
	int l=1,r=n+1,ans=0;
	while(l<r){
		int mid=(l+r)>>1;
		if(1LL*a[mid]*sz>=tot){
			ans=mid,l=mid+1;
		}
		else{
			r=mid;
		}
	}
	return ans;
}
void Solve(){
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		s[i]=0;
	}
	for(int i=0;i<=n;++i)need[i]=n+233;
	sort(a+1,a+n+1,greater<int>());
	n=m;
	for(int i=1;i<=m;++i){
		b[i].clear();
		int k,x;
		cin>>k;
		tot[i]=0;
		while(k--){
			cin>>x;
			b[i].push_back(x);
			tot[i]+=x;
		}
		rk[i]=Get(tot[i],b[i].size());
		++s[rk[i]];
	}
	s[m+1]=0;
	for(int i=m;i>=0;--i){
		s[i]+=s[i+1];
	}
	int now=0;
	bool ok=true;
	for(int i=1;i<=m;++i){
		if(s[i]<(n-i+1)-1){
			ok=false;break;
		}
	}
	if(ok){
		for(int i=m;i>=1;--i){
			if(s[i]<n-i+1){now=i;break;}
		}
		for(int i=0;i<=m;++i){
			if(i&&s[i]<n-i+1)break;
			if(s[i]==n-i+1)now=max(now,i);
			need[i]=now;
		}
	}
	for(int i=1;i<=m;++i){
		for(auto x:b[i]){
			int nw=Get(tot[i]-x,(int)b[i].size()-1);
			cout<<(nw>=need[rk[i]]);
		}
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