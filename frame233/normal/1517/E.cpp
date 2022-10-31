#include<bits/stdc++.h>
template <typename _Tp>void read(_Tp &x){
	char ch(getchar());bool f(false);while(!isdigit(ch))f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch))x=x*10+(ch&15),ch=getchar();
	if(f)x=-x;
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
typedef long long ll;
const int N=200005;
int _a[N],a[N];
ll ans,s[N];
void solve(const std::vector<int> &a_,ll C,int A,int B){
	int n=a_.size();
	s[0]=s[n+1]=0;
	ll all=C;
	for(int i=1;i<=n;++i)a[i]=a_[i-1],s[i]=a[i]*2,all+=a[i];
	for(int i=2;i<=n;++i)s[i]+=s[i-2];
	for(int i=A?1:2;i<=(B?n+1:n);++i){
		int l=0,r=(i-2+A)/2+1;
		while(l<r){
			int mid=(l+r)>>1;
			if(all-s[i-1]-(i-mid*2-2>=0?s[i-mid*2-2]:0)>0)r=mid;
			else l=mid+1;
		}
		ans+=(i-2+A)/2-l+1;
	}
	if(!A)if(all>0)++ans;
	if(!B){
		for(int i=1;i<=n;++i)all-=2*a[i];
		if(all>0)++ans;
	}
}
void MAIN(){
	ans=0;
	int n;read(n);
	for(int i=0;i<n;++i)read(_a[i]);
	if(n==1)return puts("1"),void();
	if(n==2)return printf("%d\n",_a[0]==_a[1]?1:2),void();
	solve({_a+1,_a+n-1},-_a[0]+_a[n-1],1,1);	// CP
	solve({_a+1,_a+n-1},_a[0]+_a[n-1],0,1);		// PP
	solve({_a+1,_a+n-1},-_a[0]-_a[n-1],1,0);	// CC
	solve({_a+1,_a+n-1},_a[0]-_a[n-1],0,0);		// PC
	ll all=0;for(int i=1;i<=n;++i)all+=_a[i-1];
	for(int i=n;i>=1;--i){
		all-=_a[i-1]*2;
		if(i<n&&i>2&&all>0)++ans;
	}
	printf("%lld\n",ans%998244353);
}
int main(){
	int _;read(_);
	while(_--)MAIN();
	return 0;
}