#include<bits/stdc++.h>
using namespace std;
#define N 1000010
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
int T,n;
char s[N];
ll Solve(){
	n=read();
	scanf("%s",s+1);
	static vector<int> a;
	a.clear();
	for(int i=1,j=0;i<=n;++i){
		if(s[i]=='*')a.push_back(i-j),++j;
	}
	if(a.empty())return 0;
	sort(a.begin(),a.end());
	int mid=(int)a.size()/2;
	ll ans=0;
	for(auto x:a){
		ans+=abs(x-a[mid]);
	}
	return ans;
}
int main(){
	T=read();
	while(T--){
		printf("%lld\n",Solve());
	}
	return 0;
}