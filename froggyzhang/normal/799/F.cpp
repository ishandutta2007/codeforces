#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<ctime>
#include<algorithm>
#include<map>
using namespace std;
#define N 300020
typedef unsigned long long ull;
typedef long long ll;
inline int read(){
	int x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=(x<<1)+(x<<3)+c-'0';
		c=getchar();
	}
	return x*f;
}
int n,m;
int p[N];
ull tot,s[N];
ll ans;
map<ull,ll> mp,all;
struct Seg{
	int l,r;
	ull x;
}a[N],b[N];
bool cmp1(Seg a,Seg b){
	return a.l==b.l?a.r<b.r:a.l<b.l;
}
bool cmp2(Seg a,Seg b){
	return a.r==b.r?a.l<b.l:a.r<b.r;
}
inline ull Get(){
	return ((ull)rand()*rand()*rand()*rand()+(ull)rand()*rand()*rand()+rand());
}
int main(){
	srand(1145141);
	n=read(),m=read();
	for(int i=1;i<=n;++i){
		a[i].l=read(),a[i].r=read(),a[i].x=Get();
		tot^=a[i].x;
		s[a[i].l]^=a[i].x,s[a[i].r+1]^=a[i].x;
		++p[a[i].l],--p[a[i].r+1];
	}
	for(int i=1;i<=m;++i)s[i]^=s[i-1];
	for(int i=1;i<=m;++i)s[i]^=s[i-1];
	for(int i=1;i<=m;++i)p[i]+=p[i-1];
	for(int i=1,len=0;i<=m;++i){
		if(p[i])len=0;
		else ++len;
		ans-=(1LL*len*(len+1)/2);
	}
	memcpy(b,a,sizeof(a));
	sort(a+1,a+n+1,cmp1);
	sort(b+1,b+n+1,cmp2);
	all[0]=1;
	int l=1,r=1;
	ull now=0,qwq=0;
	for(int i=1;i<=m;++i){
		while(r<=n&&a[r].l<=i){
			qwq^=a[r].x;++r;
		}
		ans+=all[qwq^s[i]]*i;
		ans-=mp[qwq^s[i]];
		while(l<=n&&b[l].r<=i){
			now^=b[l].x;++l;
		}
		mp[now^s[i]]+=i;
		++all[now^s[i]];
	}
	cout<<ans<<endl;
	return 0;
}