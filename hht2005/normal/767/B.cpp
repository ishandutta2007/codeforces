#include<bits/stdc++.h>
using namespace std;
#define int long long
#define fl fwrite(o_str,1,top,stdout),top=0
const int MAXL=1<<22;
char i_str[MAXL],*i_s,*i_t;
inline char gc() {
	if(i_s==i_t) {
		i_s=i_str;
		i_t=i_s+fread(i_str,1,MAXL,stdin);
		return i_s==i_t?EOF:*i_s++;
	} else return *i_s++;
}
inline long long read() {
	long long x=0,f=0;
	char ch=gc();
	for(;ch<'0'||ch>'9';ch=gc())
		if(ch=='-')f=1;
	for(;ch>='0'&&ch<='9';ch=gc())
		x=(x<<1)+(x<<3)+(ch^48);
	return f?-x:x;
}
int p[100010];
signed main() {
	int S=read(),T=read(),c=read(),n=read(),e=S,ans=0,Min=1e17;
	for(int i=1;i<=n;i++)p[i]=read();
	for(int i=1;i<=n;i++) {
		if(T-c<e)break;
		if(p[i]>e)return printf("%lld\n",e),0;
		if(e-p[i]+1<Min)Min=e-p[i]+1,ans=p[i]-1;
		e+=c;
	}
	if(e<=T-c)return printf("%lld\n",e),0;
	printf("%lld\n",ans);
	return 0;
}