#include<bits/stdc++.h>
using namespace std;
#define N 2020
typedef long long ll;
class Union_Set{
public:
	int f[N];
	void init(int n){
		for(int i=1;i<=n;++i){
			f[i]=i;
		}
	}
	inline int getf(int x){
		return f[x]==x?x:f[x]=getf(f[x]);
	}
	bool Merge(int x,int y){
		int fx=getf(x),fy=getf(y);
		if(fx==fy)return false;
		f[fy]=fx;
		return true;
	}
}S;
int n,a[N];
bool check(){
	S.init(n);
	int rem=n;
	for(int j=0;j<30;++j){
		int o=0;
		for(int i=1;i<=n;++i){
			if(a[i]>>j&1){
				if(!o)o=i;
				else rem-=S.Merge(o,i);
			}
		}
	}
	return rem==1;
}
void Solve(){
	cin>>n;
	int cnt=0,ans=0;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		if(!a[i])++a[i],++cnt;
	}
	if(check()){
		ans=0;
	}
	else{
		for(int i=1;i<=n;++i){
			--a[i];
			if(check()){
				ans=1;
				break;
			}
			++a[i];
			++a[i];
			if(check()){
				ans=1;
				break;
			}
			--a[i];
		}
		if(!ans){
			ans=2;
			int mx=0;
			for(int i=0;i<=n;++i){
				mx=max(mx,a[i]&(-a[i]));
			}
			for(int i=1;i<=n;++i){
				if((a[i]&(-a[i]))==mx){
					--a[i];
					break;
				}
			}
			for(int i=1;i<=n;++i){
				if((a[i]&(-a[i]))==mx){
					++a[i];
					break;
				}
			}
		}
	}
	cout<<cnt+ans<<'\n';
	for(int i=1;i<=n;++i){
		cout<<a[i]<<' ';
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