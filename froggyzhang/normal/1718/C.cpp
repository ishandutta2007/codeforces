#include<bits/stdc++.h>
using namespace std;
#define N 200020
typedef long long ll;
int n,Q,a[N];
bool ntp[N];
void init(int n){
	ntp[1]=1;
	for(int i=2;i<=n;++i){
		if(!ntp[i]){
			for(int j=i+i;j<=n;j+=i){
				ntp[j]=1;
			}
		}
	}
}
void Solve(){
	cin>>n>>Q;
	for(int i=0;i<n;++i){
		cin>>a[i];
	}
	vector<int> V;
	vector<vector<ll> > g;
	for(int i=2;i<=n;++i){
		if(n%i==0&&!ntp[i]){
			V.push_back(n/i);
		}
	}
	multiset<ll> S;
	for(auto len:V){
		g.push_back(vector<ll>(len));
		for(int s=0;s<len;++s){
			for(int i=s;i<n;i+=len){
				g.back()[s]+=a[i];
			}
			S.insert(1LL*g.back()[s]*len);
		}
	}
	auto get_ans=[&](){
		return *S.rbegin();
	};
	cout<<get_ans()<<'\n';
	while(Q--){
		int u,x;
		cin>>u>>x;
		--u;
		for(int i=0;i<(int)V.size();++i){
			int z=u%V[i];
			S.erase(S.find(1LL*g[i][z]*V[i]));
			g[i][z]-=a[u];
			g[i][z]+=x;
			S.insert(1LL*g[i][z]*V[i]);
		}
		a[u]=x;
		cout<<get_ans()<<'\n';
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	init(200000);
	int T;
	cin>>T;
	while(T--)Solve();
	return 0;
}