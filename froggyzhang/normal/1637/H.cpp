#include<bits/stdc++.h>
using namespace std;
#define N 500050
typedef long long ll;
int n,a[N];
class BIT{
	int Len;
	vector<int> b;
	inline int lowbit(int x){return x&(-x);}
public:
	BIT(int _n){b.resize(_n+1);Len=_n;}
	inline void Add(int x,int d){
		while(x<=Len)b[x]+=d,x+=lowbit(x);
	}
	inline int Ask(int x){
		int ans=0;
		while(x)ans+=b[x],x-=lowbit(x);
		return ans;
	}
};
void Solve(){
	cin>>n;
	BIT B(n);
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	ll invs=0;
	vector<int> A;
	for(int i=1;i<=n;++i){
		invs+=i-1-B.Ask(a[i]);
		A.push_back(i-2*a[i]+1);
		B.Add(a[i],1);
	}
	sort(A.begin(),A.end(),greater<int>());
	cout<<invs<<' ';
	ll jb=0;
	for(int i=0;i<n;++i){
		jb+=A[i];
		cout<<invs-jb-1LL*i*(i+1)/2<<' ';
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