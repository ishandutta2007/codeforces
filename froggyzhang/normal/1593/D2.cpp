#include<bits/stdc++.h>
using namespace std;
#define N 44
#define M 2000400
typedef long long ll;
int n,a[N],s[N],t[M];
map<int,int> mp;
vector<int> fac[M];
void Split(vector<int> &A,int x){
	for(int i=1;i*i<=x;++i){
		if(x%i==0){
			A.push_back(i);
			if(i*i!=x)A.push_back(x/i);
		}	
	}
}
void Solve(){
	cin>>n;
	mp.clear();
	for(int i=1;i<=n;++i){
		cin>>a[i];
		++mp[a[i]];
	}
	for(auto [x,w]:mp){
		if(w>=n/2){
			cout<<-1<<'\n';
			return;
		}
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;++i){
		s[i]=s[i-1]+a[i]-a[i-1];
	}
	vector<int> A;
	for(int i=0;i<n;++i){
		for(int j=i+1;j<=n;++j){
			Split(A,abs(s[j]-s[i]));
		}
	}
	sort(A.begin(),A.end(),greater<int>());
	A.erase(unique(A.begin(),A.end()),A.end());
	for(auto i:A){
		bool ok=false;
		static int c[N];
		for(int j=1;j<=n;++j){
			c[j]=(s[j]%i+i)%i;
			if((++t[c[j]])>=(n>>1)){
				ok=true;
				break;
			}
		}
		for(int j=1;j<=n;++j){
			t[c[j]]=0;
		}
		if(ok){
			cout<<i<<'\n';
			return;
		}
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