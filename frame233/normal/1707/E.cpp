#include<bits/stdc++.h>
template <typename _Tp>void read(_Tp &x){
	char ch(getchar());bool f(false);while(!isdigit(ch))f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch))x=x*10+(ch&15),ch=getchar();
	if(f)x=-x;
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
const int N=100005;typedef std::pair<int,int> pi;
int a[N],L[35][18][N],R[35][18][N],Log2[N];
inline pi ask(int l,int r,int len){int k=Log2[r-l+1];return {std::min(L[len][k][l],L[len][k][r-(1<<k)+1]),std::max(R[len][k][l],R[len][k][r-(1<<k)+1])};}
int main(){
	for(int i=2;i<N;++i)Log2[i]=Log2[i>>1]+1;
	int n,q;read(n,q);
	for(int i=1;i<=n;++i)read(a[i]),L[0][0][i]=a[i],R[0][0][i]=a[i];
	for(int j=1;j<18;++j){
		for(int i=1;i+(1<<j)-1<=n;++i){
			L[0][j][i]=std::min(L[0][j-1][i],L[0][j-1][i+(1<<(j-1))]);
			R[0][j][i]=std::max(R[0][j-1][i],R[0][j-1][i+(1<<(j-1))]);
		}
	}
	for(int k=1;k<35;++k){
		for(int j=0;j<18;++j){
			for(int i=1;i+(1<<j)-1<=n;++i){
				std::tie(L[k][j][i],R[k][j][i])=ask(L[k-1][j][i],R[k-1][j][i],k-1);
			}
		}
	}
	while(q--){
		long long ans=0;int l,r;read(l,r);if(l==1&&r==n){puts("0");continue;}
		for(int i=34;i>=0;--i){
			int L,R;std::tie(L,R)=ask(l,r,i);
			if(L!=1||R!=n)l=L,r=R,ans+=1LL<<i;
		}
		if(ask(l,r,0)!=pi{1,n})puts("-1");else printf("%lld\n",ans+1);
	}
	return 0;
}