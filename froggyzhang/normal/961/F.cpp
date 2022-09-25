#include<bits/stdc++.h>
using namespace std;
#define N 1000100
typedef long long ll;
template<int mod,int base>
class Hasher{
	int h[N],n,pw[N];
public:
	void init(char *s,int _n){
		n=_n;
		pw[0]=1;
		for(int i=1;i<=n;++i){
			pw[i]=1LL*pw[i-1]*base%mod;
			h[i]=(1LL*h[i-1]*base+s[i])%mod;
		}		
	}
	int Query(int l,int r){
		return (h[r]+1LL*(mod-h[l-1])*pw[r-l+1])%mod;
	}
};
using Hash=Hasher<998244353,233>;
Hash h;
int n,ans[N];
char s[N];
set<int> S;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=(n+1)/2;++i){
		ans[i]=-1;
		S.insert(i);
	}
	cin>>(s+1);
	h.init(s,n);
	for(int i=n/2;i>=1;--i){
		if(s[i]!=s[n-i+1])continue;
		int l=1,r=i+1,len=-1;
		while(l<r){
			int mid=(l+r)>>1;
			if(h.Query(i-mid+1,i+mid-1)==h.Query((n-i+1)-mid+1,(n-i+1)+mid-1)){
				len=mid,l=mid+1;
			}
			else{
				r=mid;
			}
		}
		while(true){
			auto it=S.lower_bound(i-len+1);
			if(it==S.end()||(*it)>i)break;
			ans[*it]=2*(i-(*it))+1;	
			S.erase(it);
		}
	}
	for(int i=1;i<=(n+1)/2;++i){
		cout<<ans[i]<<' ';
	}
	return 0;
}