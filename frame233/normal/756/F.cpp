#include<bits/stdc++.h>
#define DEBUG fprintf(stderr,"Running on Line %d in Function %s\n",__LINE__,__FUNCTION__)
template <typename _Tp>void read(_Tp &x){
	char ch(getchar());bool f(false);while(!isdigit(ch))f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch))x=x*10+(ch&15),ch=getchar();
	if(f)x=-x;
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
const int N=100005,mod=1000000007,MOD=mod-1;typedef long long ll;
template<typename _Tp1,typename _Tp2>inline void add(_Tp1 &a,_Tp2 b){a=a+b>=mod?a+b-mod:a+b;}
template<typename _Tp1,typename _Tp2>inline void sub(_Tp1 &a,_Tp2 b){a=a<b?a+mod-b:a-b;}
ll ksm(ll a,ll b=mod-2){ll res=1;while(b){if(b&1)res=res*a%mod;a=a*a%mod,b>>=1;}return res;}
ll KSM(ll a,ll b){ll res=1;while(b){if(b&1)res=res*a%MOD;a=a*a%MOD,b>>=1;}return res;}
char s[N];int g[N],st[N],top,pw1[N],pw2[N];
struct node{int ans,val;}f[N],H[N][10];
inline node operator + (const node &a,const node &b){
	return (node){(int)((1LL*a.ans*b.val+b.ans)%mod),(int)(1LL*a.val*b.val%mod)};
}
inline int calc(int x){
	if(x==0)return 10;
	int ans=1;while(x)ans=10LL*ans%mod,x/=10;
	return ans;
}
node power(const node &a,int b,int c){
	if(a.val==1)return (node){(int)(1LL*c*a.ans%mod),1};
	int tmp=ksm(a.val,b),inv=ksm(a.val+mod-1),x=1LL*a.ans*(tmp+mod-1)%mod*inv%mod,y=tmp;
	return (node){x,y};
}
inline int getsum(int q,int l,int r){
	return ksm(q,l)*(ksm(q,r-l+1)+mod-1)%mod*ksm(q+mod-1)%mod;
}
node calc(int k,int l,int r,int L,int R){
	int q=pw1[k],ans=(getsum(q,1,(r-l+mod-1)%MOD)+ksm(q,(r-l+1+mod-1)%MOD)*L%mod+mod-R)%mod*ksm(q+mod-1)%mod,val=ksm(10,1LL*k*(r-l+1+mod-1)%MOD);
	return {ans,val};
}
node get(int l,int r){
	if(l==r&&s[l]=='0')return {0,1};
	node ans={0,1};
	for(int i=r-1;i>=l;--i)for(int j=1;j<10;++j)ans=ans+H[r-i][j];
	for(int i=l,a=0,b=0;i<=r;++i){
		a=10LL*a%mod,b=10LL*b%MOD;
		for(int j=i==l?1:0,ed=i==r?s[i]-'0':s[i]-'0'-1;j<=ed;++j){
			ans=ans+calc(r-l+1,1LL*(b+j)*pw2[r-i]%MOD,1LL*(b+j+1)*pw2[r-i]%MOD-1,1LL*(a+j)*pw1[r-i]%mod,1LL*(a+j+1)*pw1[r-i]%mod-1);
		}
		a=(a+s[i]-'0')%mod,b=(b+s[i]-'0')%MOD;
	}
	return ans;
}
int main(){
	pw1[0]=1;for(int i=1;i<N;++i)pw1[i]=10LL*pw1[i-1]%mod;
	pw2[0]=1;for(int i=1;i<N;++i)pw2[i]=10LL*pw2[i-1]%MOD;
	for(int k=1;k<N;++k){
		int x=pw2[k-1],y=pw1[k-1];
		for(int j=1;j<10;++j)H[k][j]=calc(k,1LL*j*x%MOD,(1LL*(j+1)*x-1)%MOD,1LL*j*y%mod,(1LL*(j+1)*y-1)%mod);
	}
	scanf("%s",s+1);int n=strlen(s+1),nc=0;
	for(int i=1;i<=n;++i){
		if(isdigit(s[i])){
			int j=i;while(j<n&&isdigit(s[j+1]))++j;
			if(j<n&&s[j+1]=='-'){
				int k=j+2;while(k<n&&isdigit(s[k+1]))++k;
				node A=get(i,j),B=get(j+2,k),C;C.val=1LL*B.val*ksm(A.val)%mod;C.ans=(B.ans+1LL*(mod-A.ans)*C.val)%mod;
				node D={0,1};for(int p=i;p<=j;++p)D=D+(node){s[p]-48,10};
				++nc,f[nc]=D+C,st[++top]=nc,i=k;
			}
			else{
				int a=0,b=1,c=0;
				for(int p=i;p<=j;++p)a=(10LL*a+s[p]-'0')%mod,c=(10LL*c+s[p]-'0')%MOD,b=10LL*b%mod;
				++nc,f[nc]={a,b},g[nc]=c,st[++top]=nc,i=j;
			}
		}
		else if(s[i]=='(')st[++top]=-1;
		else if(s[i]==')'){
			while(st[top-1]!=-1){int cur=++nc;f[cur]=f[st[top-2]]+f[st[top]],st[top-2]=cur,top-=2;}
			int cur=++nc;f[cur]=power(f[st[top]],g[st[top-2]],f[st[top-2]].ans),st[top-2]=cur,top-=2;
		}
		else st[++top]=-2;
	}
	node cur={0,1};for(int i=1;i<=top;i+=2)cur=cur+f[st[i]];
	printf("%d\n",cur.ans);
	return 0;
}