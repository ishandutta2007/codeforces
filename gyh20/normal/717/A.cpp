#include<cstdio>
#define re register
using namespace std;
inline long long read(){
	re long long t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
const int M=1e9+7;
inline int ksm(re int x,re int y){
	re int s=1;
	while(y){
		if(y&1)s=1ll*s*x%M;
		x=1ll*x*x%M,y>>=1;
	}
	return s;
}
int t,O,inv[502],S[502][502],fac[502],n,C[502][502],m;
long long W;
inline void add(re int &x,re int y){(x+=y)>=M?x-=M:x;}
inline int Mod(re int x){return x>=M?x-M:x;}
struct node{
	int x,y;
	node operator +(const node A)const{return (node){Mod(x+A.x),Mod(y+A.y)};}
	node operator -(const node A)const{return (node){Mod(x-A.x+M),Mod(y-A.y+M)};}
	node operator *(const node A)const{return (node){(1ll*x*A.y+1ll*y*A.x)%M,(W*x*A.x+1ll*y*A.y)%M};}
	node operator -(const int A)const{return (node){x,Mod(y-A+M)};}
	node operator *(const int A)const{return (node){1ll*x*A%M,1ll*y*A%M};}
	node Inv(){
		re int iv=ksm((W*x*x+1ll*y*(M-y))%M,M-2);
		return (node){1ll*x*iv%M,1ll*y*(M-iv)%M};
	}
	node operator /(node A)const{node B=A.Inv();return (*this)*B;}
}A,B,X,Y;
inline node ksm(node x,re long long y){
	re node s=(node){0,1};
	while(y){
		if(y&1)s=s*x;
		x=x*x,y>>=1;
	}
	return s;
}
inline node Get(node X,node Y,re long long n){
	if(Y.x==0&&Y.y==1)return X*(n%M);
	node tmp=X*((ksm(Y,n)-1)/(Y-1));
	return X*((ksm(Y,n)-1)/(Y-1));
}
inline int calc(re long long l,re long long r,re int k){
	re node s=(node){0,0};
	for(re int i=0;i<=k;++i){
		re node w=(node){0,0};
		for(re int j=0;j<=i;++j)w=(w+Get(ksm(ksm(X,j)*ksm(Y,i-j),l),ksm(X,j)*ksm(Y,i-j),r-l+1)*C[i][j]*ksm(A,j)*ksm(B,i-j));
		if(k-i&1)s=(s+w*(M-S[k][i]));
		else s=(s+w*S[k][i]);
	}
	return 1ll*s.y*inv[k]%M;
}
signed main(){
	t=1,m=2,n=501;
	if(m==2)W=5,A=(node){ksm(10,M-2),M+1>>1},B=(node){M-ksm(10,M-2),M+1>>1},X=(node){M+1>>1,M+1>>1},Y=(node){M>>1,M+1>>1};
	else W=3,A=(node){ksm(6,M-2),M+1>>1},B=(node){M-ksm(6,M-2),M+1>>1},X=(node){1,2},Y=(node){M-1,2};
	for(re int i=fac[0]=1;i<=n;++i)fac[i]=1ll*fac[i-1]*i%M;
	inv[n]=ksm(fac[n],M-2);
	for(re int i=n-1;~i;--i)inv[i]=1ll*inv[i+1]*(i+1)%M;
	for(re int i=C[0][0]=S[0][0]=1;i<=n;++i)for(re int j=C[i][0]=1;j<=i;++j)C[i][j]=Mod(C[i-1][j-1]+C[i-1][j]),S[i][j]=(1ll*S[i-1][j]*(i-1)+S[i-1][j-1])%M;
	while(t--){
		re long long k=read(),L=read()+1,R=read()+1;
		if(m==3)L=L+1>>1,R>>=1;
		printf("%lld\n",1ll*calc(L,R,k)%M);
	}
}