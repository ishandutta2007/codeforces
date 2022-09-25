#include<bits/stdc++.h>
using namespace std;
#define N 200020
typedef long long ll;
int n,a[N];
int g;
void Solve(){
	g=0;
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	for(int i=0;i<30;++i){
		int cnt=0;
		for(int j=1;j<=n;++j){
			cnt+=a[j]>>i&1;	
		}
		if(cnt)g=__gcd(g,cnt);
	}
	if(!g){
		for(int i=1;i<=n;++i){
			cout<<i<<' ';
		}
	}
	else{
		vector<int> fac;
		for(int i=1;i*i<=g;++i){
			if(g%i==0){
				fac.push_back(i);
					if(i*i!=g)fac.push_back(g/i);
			}
		}
		sort(fac.begin(),fac.end());
		for(auto x:fac){
			cout<<x<<' ';
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