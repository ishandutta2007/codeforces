#include<bits/stdc++.h>
using namespace std;
#define N 100010
typedef long long ll;
const int mod=1e9+7;
typedef pair<int,int> pii;
int n,m,a[N],pw2[N],ans[N];
vector<pii> q[N];
class Basis{
	int d[20];
public:
	int siz;
	void Insert(int x){
		for(int i=19;i>=0;--i){
			if(x>>i&1){
				if(!d[i]){
					d[i]=x,++siz;
					return;
				}
				else{
					x^=d[i];
				}	
			}	
		}	
	}
	int Ask(int x){
		for(int i=19;i>=0;--i){
			if(x>>i&1)x^=d[i];
		}
		return !x;	
	}
}B;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	pw2[0]=1;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		pw2[i]=(pw2[i-1]<<1)%mod;
	}
	for(int i=1;i<=m;++i){
		int u,x;
		cin>>u>>x;
		q[u].emplace_back(x,i);
	}
	for(int i=1;i<=n;++i){
		B.Insert(a[i]);
		for(auto [x,id]:q[i]){
			if(!B.Ask(x))ans[id]=0;
			else ans[id]=pw2[i-B.siz];	
		}
	}
	for(int i=1;i<=m;++i){
		cout<<ans[i]<<'\n';
	}
	return 0;
}