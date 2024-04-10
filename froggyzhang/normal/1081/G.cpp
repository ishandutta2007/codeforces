#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
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
const int n=read(),m=read(),mod=read();
const int inv2=(mod+1)/2;
int ans,inv[N],s[N];
vector<pair<int,int> > vec;
void Solve(int l,int r,int h){
	if(h==1||l==r){
		int len=(r-l+1);
		ans=(ans+1LL*len*(len-1)/2%mod*inv2%mod)%mod;
		for(int i=0;i<(int)vec.size();++i){
			if(vec[i].first==len){
				++vec[i].second;return;
			}
		}
		vec.push_back(make_pair(len,1));
		return;
	}
	int mid=(l+r)>>1;
	Solve(l,mid,h-1);
	Solve(mid+1,r,h-1);
}
int main(){
	inv[1]=s[1]=1;
	for(int i=2;i<=n<<1;++i){
		inv[i]=1LL*(mod-mod/i)*inv[mod%i]%mod;
		s[i]=(s[i-1]+inv[i])%mod;
	}
	Solve(1,n,m);
	for(int x=0;x<(int)vec.size();++x){
		for(int y=x;y<(int)vec.size();++y){
			int A=vec[x].first,B=vec[y].first,cA=vec[x].second,cB=vec[y].second;
			int sum=0;
			for(int i=1;i<=A;++i){
				sum=(sum+(s[i+B]-s[i]+mod)%mod)%mod;
			}
			int tot=(x==y?1LL*cA*(cA-1)/2%mod:1LL*cA*cB%mod);
			ans=(ans+1LL*tot*(1LL*A*B%mod*inv2%mod-sum))%mod;
		}
	}
	printf("%d\n",(ans+mod)%mod);
	return 0;
}