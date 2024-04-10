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
int L,R,s,n;
vector<tuple<int,int,int> > ans;
int main(){
	L=read(),R=read();
	n=30;
	for(int i=0;i<=21;++i){
		int x=n-i;
		for(int j=i+1;j<=21;++j){
			int y=n-j;
			ans.emplace_back(y,x,1<<(max(0,i-1)));
		}
	}
	if(L==1)s=1,ans.emplace_back(1,n,1);
	else s=2,ans.emplace_back(1,2,L-1),ans.emplace_back(1,n,L);
	R-=L;
	int now=R;
	for(int i=20;i>=0;--i){
		if(R>>i&1)now-=1<<i,ans.emplace_back(s,n-i-1,now+1);
	}
	printf("YES\n");
	printf("%d %d\n",n,(int)ans.size());
	for(auto [x,y,w]:ans){
		printf("%d %d %d\n",x,y,w);
	}
	return 0;
}