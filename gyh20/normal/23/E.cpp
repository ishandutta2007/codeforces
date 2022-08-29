#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>
#define re register
using namespace std;
inline int read(){
	re int t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
#define ll long long
struct Wint:vector<ll> {
	const static ll BIT=1e8;
	Wint(ll n=0) {
		push_back(n);
		check();
	}
	Wint& operator=(const char* num) {
		int Len=strlen(num)-1;
		clear();
		for(int i=Len; i>=0; i-=9) {
			push_back(0);
			ll w=1;
			for(int j=i; j>i-9&&j>=0; --j)
				back()+=(num[j]^48)*w,w*=10;
		}
		return *this;
	}
	Wint& check() {
		while(!empty()&&!back()) pop_back();
		if(empty()) return *this;
		for(int i=1; i<size(); ++i)
			(*this)[i]+=(*this)[i-1]/BIT,
			            (*this)[i-1]%=BIT;
		while(back()>=BIT) {
			push_back(back()/BIT);
			(*this)[size()-2]%=BIT;
		}
		return *this;
	}
};
bool operator<(Wint a,Wint b) {
	if(a.size()!=b.size()) return a.size()<b.size();
	for(int i=a.size()-1; i>=0; --i)
		if(a[i]!=b[i]) return a[i]<b[i];
	return 0;
}
bool operator>(Wint a,Wint b) {
	return b<a;
}
bool operator<=(Wint a,Wint b) {
	return !(a>b);
}
bool operator>=(Wint a,Wint b) {
	return !(a<b);
}
bool operator!=(Wint a,Wint b) {
	return a<b||b<a;
}
bool operator==(Wint a,Wint b) {
	return !(a<b)&&!(b<a);
}
Wint& operator+=(Wint &a,Wint b) {
	if(a.size()<b.size()) a.resize(b.size());
	for(int i=0; i<b.size(); ++i) a[i]+=b[i];
	return a.check();
}
Wint operator+(Wint a,Wint b) {
	return a+=b;
}
Wint& operator-=(Wint &a,Wint b) {
	for(int i=0; i<b.size(); a[i]-=b[i],++i)
		if(a[i]<b[i]) {
			int j=i+1;
			while(!a[j]) ++j;
			while(j>i) --a[j],a[--j]+=Wint::BIT;
		}
	return a.check();
}
Wint operator-(Wint a,Wint b) {
	return a-=b;
}
Wint operator*(Wint a,Wint b) {
	Wint n;
	n.assign(a.size()+b.size()-1,0);
	for(int i=0; i<a.size(); ++i)
		for(int j=0; j<b.size(); ++j)
			n[i+j]+=a[i]*b[j];
	return n.check();
}
Wint& operator*=(Wint &a,Wint b) {
	return a=a*b;
}
Wint operator/(Wint a,int b) {
	Wint n;
	bool wp=0;
	ll t=0;
	for(int i=a.size()-1; i>=0; --i) {
		t=t*Wint::BIT+a[i];
		if(wp||t/b) wp=1,n.push_back(t/b);
		t%=b;
	}
	reverse(n.begin(),n.end());
	return n;
}
Wint& operator/=(Wint &a,int b) {
	return a=a/b;
}
void writeX(Wint n) {
	if(n.empty()) return putchar('0'),void();
	int Len=n.size()-1;
	printf("%lld",n[Len]);
	for(int i=Len-1; i>=0; --i) printf("%08lld",n[i]);
}
int n,head[702],cnt,siz[702];
Wint f[702][702],mx[702];
struct edge{
	int to,next;
}e[1402];
inline void add(re int x,re int y){
	e[++cnt]=(edge){y,head[x]};
	head[x]=cnt;
}
inline void dfs(re int x,re int y){
	f[x][0]=1;
	for(re int i=head[x];i;i=e[i].next)
		if(e[i].to^y){
			dfs(e[i].to,x);siz[x]+=siz[e[i].to];
			for(re int j=siz[x];~j;--j){
				re Wint tt=f[x][j]*mx[e[i].to];
				for(re int k=min(j,siz[e[i].to]);k>0&&j-k<=siz[x]-siz[e[i].to];--k)f[x][j]=max(f[x][j-k]*f[e[i].to][k],f[x][j]);
				f[x][j]=max(f[x][j],tt);
			}
		}++siz[x];
	for(re int i=siz[x];i;--i)f[x][i]=f[x][i-1],mx[x]=max(mx[x],i*f[x][i]);
}
int main(){
	n=read();
	for(re int i=1,x,y;i<n;++i)x=read(),y=read(),add(x,y),add(y,x);
	dfs(1,1);
	writeX(mx[1]);
}