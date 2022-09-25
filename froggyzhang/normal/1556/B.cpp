#include<bits/stdc++.h>
using namespace std;
#define N 100010
typedef long long ll;
int a[N],n;
class BIT{
public:
	int b[N];
	inline int lowbit(int x){return x&(-x);}
	void clear(int n){
		for(int i=1;i<=n;++i)b[i]=0;
	}
	inline void Add(int x,int d){
		while(x<=n)b[x]+=d,x+=lowbit(x);
	}
	inline int Ask(int x){
		int ans=0;
		while(x)ans+=b[x],x-=lowbit(x);
		return ans;
	}
}B;
ll calc(int X,int Y){
	static int c[N];
	for(int i=1;i<=n;++i){
		if(!a[i]){c[i]=X;X+=2;}
		else{c[i]=Y;Y+=2;}	
	}
	B.clear(n);
	ll ans=0;
	for(int i=n;i>=1;--i){
		ans+=B.Ask(c[i]);
		B.Add(c[i],1);
	}
	return ans;
}
void Solve(){
	cin>>n;
	int cnt[2]={0,0};
	for(int i=1;i<=n;++i){
		cin>>a[i];
		a[i]%=2;
		++cnt[a[i]];
	}
	if(abs(cnt[0]-cnt[1])>1){
		cout<<-1<<'\n';return;
	}
	if(n&1){
		cout<<(cnt[0]>cnt[1]?calc(1,2):calc(2,1))<<'\n';
	}
	else{
		cout<<min(calc(1,2),calc(2,1))<<'\n';
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