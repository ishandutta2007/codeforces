#include<bits/stdc++.h>
template <typename _Tp>void read(_Tp &x){
	char ch(getchar());bool f(false);while(!isdigit(ch))f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch))x=x*10+(ch&15),ch=getchar();
	if(f)x=-x;
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
const int N=100005;
typedef long long ll;
int a[N],b[N],n,s[N];
bool check(int mid){
	int lim=(n+mid)-(n+mid)/4;
	int rest=lim,A=std::min(mid,rest),X=0;
	rest-=A,X+=A*100;for(int i=1;i<=rest;++i)X+=a[i];
	rest=lim;int Y=0;for(int i=1;i<=rest&&i<=n;++i)Y+=b[i];
	return X>=Y;
}
int main(){
	int _;read(_);
	while(_--){
		read(n);
		for(int i=1;i<=n;++i)read(a[i]);
		for(int i=1;i<=n;++i)read(b[i]);
		std::sort(a+1,a+n+1,std::greater<int>());
		std::sort(b+1,b+n+1,std::greater<int>());
		int l=0,r=1e6,mid;
		while(r-l>10)mid=(l+r)>>1,check(mid)?r=mid:l=mid+1;
		for(int i=l;i<=r;++i)if(check(i)){printf("%d\n",i);break;}
	}
	return 0;
}