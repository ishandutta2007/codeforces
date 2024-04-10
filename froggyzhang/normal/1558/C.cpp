#include<bits/stdc++.h>
using namespace std;
#define N 3003
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
int T,a[N],n;
vector<int> ans;
void Rev(int p){
	ans.push_back(p);
	reverse(a+1,a+p+1);	
}
void Solve(){
	n=read();
	for(int i=1;i<=n;++i){
		a[i]=read();
	}
	for(int i=1;i<=n;++i){
		if((i&1)^(a[i]&1)){
			puts("-1");
			return;
		}
	}
	ans.clear();
	for(int i=n;i>=3;i-=2){
		for(int j=1;;++j){
			if(a[j]==i){
				Rev(j);break;
			}
		}
		for(int j=1;;++j){
			if(a[j+1]==i-1){
				Rev(j);Rev(j+2);break;
			}
		}
		Rev(3);
		Rev(i);
	}
	printf("%d\n",(int)ans.size());
	for(auto x:ans){
		printf("%d ",x);
	}
	printf("\n");
}
int main(){
	T=read();
	while(T--){
		Solve();
	}
	return 0;
}