#include<bits/stdc++.h>
template <typename _Tp>void read(_Tp &x){
	char ch(getchar());bool f(false);while(!isdigit(ch))f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch))x=x*10+(ch&15),ch=getchar();
	if(f)x=-x;
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
const int N=300005;
int a[N],Log2[N],b[N];
struct rmq{
	int f[N][20];
	inline int ask(int l,int r){int k=Log2[r-l+1];return std::max(f[l][k],f[r-(1<<k)+1][k]);}
	void init(const std::vector<int> &a){
		int n=a.size();
		for(int i=n;i>=1;--i){f[i][0]=a[i-1];for(int j=1;j<20&&i+(1<<(j-1))<=n;++j)f[i][j]=std::max(f[i][j-1],f[i+(1<<(j-1))][j-1]);}
	}
}A,B;
int main(){
	for(int i=2;i<N;++i)Log2[i]=Log2[i>>1]+1;
	int n;read(n);
	for(int i=1;i<=n;++i)read(a[i]);
	for(int i=2;i<n;++i)b[i]=std::min(a[i],std::max(a[i-1],a[i+1]));
	A.init({a+1,a+n+1}),B.init({b+1,b+n+1});
	for(int k=0;k<n;++k){
		if((n-k)%2==0||k+1==n){
			int l=(1+n-k)/2,r=(1+k+n+1)/2;
			printf("%d%c",A.ask(l,r)," \n"[k+1==n]);
		}
		else{
			int l=(1+n-k)/2,r=(1+k+n)/2;
			printf("%d%c",B.ask(l,r)," \n"[k+1==n]);
		}
	}
	return 0;
}