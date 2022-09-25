#include<bits/stdc++.h>
using namespace std;
#define N 200010
typedef long long ll;
int n,m,a[N],b[N];
typedef unsigned long long ull;
const ull base=1145141;
ull pw[N];
void init(int n){
	pw[0]=1;
	for(int i=1;i<=n;++i){
		pw[i]=pw[i-1]*base;
	}
}
class Hash{
	ull h[N];
public:
	void init(int *a,int n){
		for(int i=1;i<=n;++i){
			h[i]=h[i-1]*base+a[i]+1;	
		}
	}	
	inline ull Query(int l,int r){
		return h[r]-h[l-1]*pw[r-l+1];
	}
}H1,H2;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>a[i];	
	}
	for(int i=1;i<n;++i){
		b[i]=a[i+1]-a[i];
	}
	b[n]=a[1]+m-a[n];
	init(n);
	H1.init(b,n);
	reverse(b+1,b+n+1);
	H2.init(b,n);
	vector<int> ans;
	for(int i=1;i<=n;++i){
		if(H1.Query(1,i-1)==H2.Query(n-i+2,n)&&H1.Query(i,n)==H2.Query(1,n-i+1)){
			ans.push_back((a[1]+a[i])%m);
		}	
	}
	sort(ans.begin(),ans.end());
	cout<<ans.size()<<'\n';
	for(auto x:ans){
		cout<<x<<' ';
	}
	return 0;
}