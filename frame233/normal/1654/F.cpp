#include<bits/stdc++.h>
template <typename _Tp>void read(_Tp &x){
	char ch(getchar());bool f(false);while(!isdigit(ch))f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch))x=x*10+(ch&15),ch=getchar();
	if(f)x=-x;
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
const int N=(1<<18)+5,mod1=1000000271,mod2=1000000433,mod3=1000001351;typedef long long ll;
struct hash{
	ll a,b,c;
	inline hash(){a=b=c=0;}
	inline hash(ll x){a=x,b=x,c=x;}
	inline hash(ll x,ll y,ll z){a=x,b=y,c=z;}
	inline hash operator += (const hash &o){a=a+o.a>=mod1?a+o.a-mod1:a+o.a,b=b+o.b>=mod1?b+o.b-mod1:b+o.b,c=c+o.c>=mod3?c+o.c-mod3:c+o.c;return *this;}
	inline hash operator + (const hash &o)const{hash x(*this);return x+=o;}
	inline hash operator * (const hash &o)const{return hash(a*o.a%mod1,b*o.b%mod2,c*o.c%mod3);}
	inline bool operator != (const hash &o)const{return a!=o.a||b!=o.b||c!=o.c;}
}f[1<<9][1<<9];
const hash base=hash(2333);
char s[N];
bool cmp(int x,int y){
	int hx=x>>9,hy=y>>9;
	for(int i=0;i<1<<9;++i){
		if(f[x&511][i^hx]!=f[y&511][i^hy]){
			int cur=i<<9;for(int j=0;j<1<<9;++j,++cur)if(s[cur^x]!=s[cur^y])return s[cur^x]<s[cur^y];
			assert(0);
		}
	}
	return 0;
}
int main(){
	memset(s,127,sizeof(s));
	int n;read(n);scanf("%s",s);
	for(int i=0;i<1<<9;++i){
		for(int j=0;j<1<<9;++j){
			for(int k=0;k<1<<9;++k){
				f[i][j]=f[i][j]*base+hash(s[(j<<9)|(i^k)]);
			}
		}
	}
	int mn=0;for(int i=1;i<1<<n;++i)if(cmp(i,mn))mn=i;
	for(int i=0;i<1<<n;++i)putchar(s[mn^i]);
	putchar('\n');
	return 0;
}