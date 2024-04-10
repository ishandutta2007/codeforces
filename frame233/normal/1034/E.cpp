#include<bits/stdc++.h>
template <typename _Tp>void read(_Tp &x){
	char ch(getchar());bool f(false);while(!isdigit(ch))f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch))x=x*10+(ch&15),ch=getchar();
	if(f)x=-x;
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
typedef long long ll;const ll mod=17592186044416LL;
template<typename _Tp1,typename _Tp2>inline void add(_Tp1 &a,_Tp2 b){a=a+b>=mod?a+b-mod:a+b;}
template<typename _Tp1,typename _Tp2>inline void sub(_Tp1 &a,_Tp2 b){a=a-b<0?a-b+mod:a-b;}
ll v[1<<21],a[1<<21],b[1<<21];char s[(1<<21)+5];
void fwt(ll *a,int limit){
	for(int len=1;len<limit;len<<=1){
		for(int i=0;i<limit;i+=len*2){
			for(int j=0;j<len;++j)add(a[i+j+len],a[i+j]);
		}
	}
}
void ifwt(ll *a,int limit){
	for(int len=1;len<limit;len<<=1){
		for(int i=0;i<limit;i+=len*2){
			for(int j=0;j<len;++j)sub(a[i+j+len],a[i+j]);
		}
	}
}
int main(){
	int n;read(n);
	v[0]=1;for(int i=1;i<1<<n;++i)v[i]=v[i>>1]*(i&1?4:1);
	scanf("%s",s);for(int i=0;i<1<<n;++i)a[i]=s[i]-'0',a[i]*=v[i];
	scanf("%s",s);for(int i=0;i<1<<n;++i)b[i]=s[i]-'0',b[i]*=v[i];
	fwt(a,1<<n),fwt(b,1<<n);for(int i=0;i<1<<n;++i)a[i]=(__int128)a[i]*b[i]%mod;
	ifwt(a,1<<n);for(int i=0;i<1<<n;++i)putchar(a[i]/v[i]%4+'0');
	return 0;
}