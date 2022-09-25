#include<bits/stdc++.h>
using namespace std;
#define N 200020
typedef long long ll;
inline ll read(){
	ll x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=(x<<1)+(x<<3)+c-'0';
		c=getchar();
	}
	return x*f;
}
int T,n,a[N],p[N];
ll s[N];
void Solve(){
	n=read();
	for(int i=1;i<=n;++i){
		a[i]=read();
		p[i]=i;
	}
	sort(p+1,p+n+1,[&](int i,int j){return a[i]<a[j];});
	vector<int> ans;
	for(int i=1;i<=n;++i){
		s[i]=s[i-1]+a[p[i]];
	}
	for(int i=n-1;i>=0;--i){
		if(!i||s[i]<a[p[i+1]]){
			for(int j=i+1;j<=n;++j){
				ans.push_back(p[j]);
			}
			break;
		}
	}
	sort(ans.begin(),ans.end());
	printf("%d\n",(int)ans.size());
	for(auto x:ans)printf("%d ",x);
	printf("\n");
}
int main(){
	T=read();
	while(T--){
		Solve();
	}
	return 0;	
}