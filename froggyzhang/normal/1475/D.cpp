#include<bits/stdc++.h>
using namespace std;
#define N 200020
typedef long long ll;
int T,n,m,a[N],b[N];
vector<int> t1,t2;
vector<ll> s;
void Solve(){
	cin>>n>>m;
	ll sum=0;
	for(int i=1;i<=n;++i)cin>>a[i];
	for(int i=1;i<=n;++i)cin>>b[i];
	t1.clear(),t2.clear();
	for(int i=1;i<=n;++i){
		sum+=a[i];
		(b[i]==1?t1:t2).push_back(a[i]);
	}
	if(sum<m){
		cout<<-1<<'\n';return;
	}
	sort(t1.begin(),t1.end(),greater<int>());
	sort(t2.begin(),t2.end(),greater<int>());
	s.resize(t2.size());
	if(!s.empty()){
		s[0]=t2[0];
		for(int i=1;i<(int)t2.size();++i)s[i]=s[i-1]+t2[i];
	}
	int j=(int)t2.size()-1;
	while(j>0&&s[j-1]>=m)--j;
	int ans=2e9;
	if(j>=0&&s[j]>=m)ans=(j+1)*2;
	for(int i=0;i<(int)t1.size();++i){
		m-=t1[i];
		if(m<=0){
			ans=min(ans,i+1);break;
		}
		while(j>0&&s[j-1]>=m)--j;
		if(j>=0&&s[j]>=m){
			ans=min(ans,(j+1)*2+i+1);
		}
	}
	cout<<ans<<'\n';
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>T;
	while(T--)Solve();
	return 0;
}