#include<bits/stdc++.h>
#define pb push_back
#define SZ(x) ((int)x.size())
template <typename _Tp>void read(_Tp &x){
	char ch(getchar());bool f(false);while(!isdigit(ch))f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch))x=x*10+(ch&15),ch=getchar();
	if(f)x=-x;
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
const int N=1005,mod1=1000000007,mod2=1000000009;
typedef long long ll;
ll ksm1(ll a,ll b=mod1-2){ll res=1;while(b){if(b&1)res=res*a%mod1;a=a*a%mod1,b>>=1;}return res;}
ll ksm2(ll a,ll b=mod2-2){ll res=1;while(b){if(b&1)res=res*a%mod2;a=a*a%mod2,b>>=1;}return res;}
struct hash{
	ll b,c;
	inline hash(ll x):b((x+mod1)%mod1),c((x+mod2)%mod2){}
	inline hash(ll x,ll y):b(x),c(y){}
	inline hash operator += (const hash &o){
		(b+=o.b)>=mod1&&(b-=mod1),(c+=o.c)>=mod2&&(c-=mod2);
		return *this;
	}
	inline hash operator + (const hash &o)const{
		hash a(*this);
		return a+=o;
	}
	inline hash operator -= (const hash &o){
		(b-=o.b)<0&&(b+=mod1),(c-=o.c)<0&&(c+=mod2);
		return *this;
	}
	inline hash operator - (const hash &o)const{
		hash a(*this);
		return a-=o;
	}
	inline hash operator * (const hash &o)const{return hash(b*o.b%mod1,c*o.c%mod2);}
	inline hash operator / (const hash &o)const{return hash(b*ksm1(o.b)%mod1,c*ksm2(o.c)%mod2);}
	inline bool operator == (const hash &o)const{return b==o.b&&c==o.c;}
	inline bool operator < (const hash &o)const{return b==o.b?c<o.c:b<o.b;}
};
int a[N][N],sum[N],d[N];
hash calc(const std::vector<hash> &X,const std::vector<hash> &Y,hash o){
	hash ans=0;
	for(int i=0;i<SZ(X);++i){
		hash A=hash(1),B=hash(1);for(int j=0;j<SZ(X);++j)if(i!=j)A=A*(o-X[j]),B=B*(X[i]-X[j]);
		ans+=Y[i]*A/B;
	}
	return ans;
}
int main(){
	int m,k;read(m,k);
	for(int i=0;i<k;++i)for(int j=1;j<=m;++j)read(a[i][j]),sum[i]+=a[i][j];
	for(int i=1;i<k;++i)d[i]=sum[i]-sum[i-1];
	int val=d[1],cnt=1;
	for(int i=2;i<k;++i)if(val==d[i])++cnt;else if(!--cnt)val=d[i],cnt=1;
	for(int i=1;i<k;++i)if(d[i]!=val){
		std::vector<hash> X,Y;
		for(int j=0;j<k&&SZ(X)<=3;++j)if(i!=j){
			X.pb(hash(j));hash qwq=hash(0);
			for(int k=1;k<=m;++k)qwq+=(hash)(a[j][k])*(hash)(a[j][k]);
			Y.pb(qwq);
		}
		hash tar=calc(X,Y,i),cur=0;for(int j=1;j<=m;++j)cur+=(hash)(a[i][j])*(hash)(a[i][j]);
		hash delta=hash(val-d[i]);
		for(int j=1;j<=m;++j){
			hash o=cur-hash(a[i][j])*hash(a[i][j])+(hash(a[i][j])+delta)*(hash(a[i][j])+delta);
			if(o==tar){
				printf("%d %d\n",i,a[i][j]+val-d[i]),fflush(stdout);
				return 0;
			}
		}
		assert(0);
	}
	assert(0);
	return 0;
}