#include<bits/stdc++.h>
template <typename _Tp>void read(_Tp &x){
	char ch(getchar());bool f(false);while(!isdigit(ch))f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch))x=x*10+(ch&15),ch=getchar();
	if(f)x=-x;
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
template <typename _Tp>inline _Tp abs(const _Tp &a){return a>=0?a:-a;}
const int N=800005,inf=0x3f3f3f3f;
typedef long long ll;
struct node{
	int x,y;
	inline bool operator < (const node &o)const{return x<o.x;}
}a[N];
int main(){
	int n;read(n);
	for(int i=1;i<=n;++i)read(a[i].x,a[i].y),a[i].x+=a[i].y;
	std::sort(a+1,a+n+1);
	std::multiset<ll> A={0},B={(ll)1e18};
	ll val=0,tag=0;
	for(int i=1;i<=n;++i){
		int x=a[i].x,y=a[i].y,d=x-a[i-1].x;
		tag+=d;
		ll l=*A.rbegin(),r=*B.begin()+tag;
		if(y<=l)A.erase(--A.end()),A.insert(y),A.insert(y),B.insert(l-tag),val+=l-y;
		else if(y>=r)B.erase(B.begin()),B.insert(y-tag),B.insert(y-tag),A.insert(r),val+=y-r;
		else A.insert(y),B.insert(y-tag);
	}
	printf("%lld\n",val);
	return 0;
}