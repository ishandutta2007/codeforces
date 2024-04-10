#include<bits/stdc++.h>
using namespace std;
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
int T,n,k;
vector<int> ans;
int main(){
	T=read();
	while(T--){
		n=read(),k=read();
		ans.clear();
		for(int i=k+1;i<=n;++i)ans.push_back(i);
		for(int i=(k+1)/2;i<k;++i)ans.push_back(i);
		printf("%d\n",(int)ans.size());
		for(auto x:ans)printf("%d ",x);
		printf("\n");
	}
	return 0;
}