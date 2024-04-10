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
int T,a[100],b[100],an,bn;
void Split(ll x,int *a,int &an){
	an=0;
	while(x)a[++an]=x%10,x/=10;	
}
void Solve(){
	Split(read(),a,an);
	int ans=2333333;
	for(int i=0;i<=62;++i){
		Split(1LL<<i,b,bn);
		int cnt=an+bn;
		for(int j=bn,k=an;j>=1;--j,--k){
			while(k&&a[k]^b[j])--k;
			if(!k)break;
			cnt-=2;
		}
		ans=min(ans,cnt);
	}
	printf("%d\n",ans);
}
int main(){
	T=read();
	while(T--){
		Solve();
	}
	return 0;
}