#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
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
}f[705][705],ans=1;
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
int n,cnt,h[705],size[705];
struct Edge{
	int to,next;
}e[1405];
void Add_Edge(int x,int y){
	e[++cnt]={y,h[x]},h[x]=cnt;
}
void DP(int x,int fa){
	f[x][0]=1;
	for(int i=h[x];i;i=e[i].next){
		int y=e[i].to;
		if(y==fa)continue;
		DP(y,x),size[x]+=size[y];
		Wint t=1,t2;
		for(int k=size[y];k>0;k--)t=max(t,f[y][k]*k);
		for(int j=size[x];j>=0;j--){
			t2=t*f[x][j];
			for(int k=min(j,size[y]);k>0&&j-k<=size[x]-size[y];k--)f[x][j]=max(f[x][j],f[x][j-k]*f[y][k]);
			f[x][j]=max(f[x][j],t2);
		}
	}
	for(int i=n;i>=1;i--)f[x][i]=f[x][i-1],ans=max(ans,f[x][i]*i);
	size[x]++;
}
int main(){
	scanf("%d",&n);
	for(int i=1,x,y;i<n;i++)scanf("%d%d",&x,&y),Add_Edge(x,y),Add_Edge(y,x);
	DP(1,0),writeX(ans);
	return 0;
}