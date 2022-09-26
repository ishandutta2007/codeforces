#include<bits/stdc++.h>
using namespace std;
#define N 1005
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
unordered_map<bitset<N>,int> mp;
int n,m,Q;
bitset<N> a[N];
int main(){
	n=read(),m=read(),Q=read();
	for(int i=0;i<m;++i){
		int z=read();
		while(z--)a[i][read()]=1;
	}
	int k=min(20,m);
	for(int i=0;i<(1<<k);++i){
		bitset<N> B;
		for(int j=0;j<k;++j){
			if(i>>j&1){
				B^=a[j];
			}	
		}
		if(mp.count(B))mp[B]=min(mp[B],__builtin_popcount(i));
		else mp[B]=__builtin_popcount(i);
	}
	while(Q--){
		int ans=m+1;
		bitset<N> A;
		int z=read();
		while(z--)A[read()]=1;
		for(int i=0;i<(1<<(m-k));++i){
			bitset<N> B;
			for(int j=0;j<m-k;++j){
				if(i>>j&1)B^=a[k+j];	
			}
			if(mp.count(A^B)){
				ans=min(ans,__builtin_popcount(i)+mp[A^B]);
			}
		}
		printf("%d\n",ans>m?-1:ans);
	}
	return 0;
}