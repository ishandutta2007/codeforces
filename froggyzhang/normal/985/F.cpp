#include<bits/stdc++.h>
using namespace std;
#define N 200020
const int mod=998244353;
const int base=233;
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
int n,Q,h[26][N],pw[N];
char s[N];
inline int Hash(int *h,int l,int r){
	return (h[r]-1LL*h[l-1]*pw[r-l+1]%mod+mod)%mod;	
}
int main(){
	n=read(),Q=read();
	scanf("%s",s+1);
	pw[0]=1;
	for(int i=1;i<=n;++i){
		pw[i]=1LL*pw[i-1]*base%mod;
	}
	for(int i=1;i<=n;++i){
		for(int j=0;j<26;++j){
			h[j][i]=(1LL*h[j][i-1]*base+1)%mod;	
		}
		++h[s[i]-'a'][i];
	}
	while(Q--){
		int l1=read(),l2=read(),len=read();
		int r1=l1+len-1,r2=l2+len-1;
		vector<int> A,B;
		for(int i=0;i<26;++i)A.push_back(Hash(h[i],l1,r1));
		for(int i=0;i<26;++i)B.push_back(Hash(h[i],l2,r2));
		sort(A.begin(),A.end()),sort(B.begin(),B.end());
		printf(A==B?"YES\n":"NO\n");
	}
	return 0;
}