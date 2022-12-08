#include<bits/stdc++.h>
using namespace std;
#define Fl fwrite(o_str,1,o_t,stdout),o_t=0
const int MAXL=1<<22;
char i_str[MAXL],o_str[MAXL],*i_s,*i_t;
int o_t;
inline void pc(char x) {
	o_str[o_t++]=x;
	if(o_t==MAXL)Fl;
}
inline char gc() {
	if(i_s==i_t) {
		i_s=i_str;
		i_t=i_s+fread(i_str,1,MAXL,stdin);
		return i_s==i_t?EOF:*i_s++;
	} else return *i_s++;
}
inline int read() {
	int x=0;
	char ch=gc();
	for(;ch<'0'||ch>'9';ch=gc());
	for(;ch>='0'&&ch<='9';ch=gc())
		x=(x<<1)+(x<<3)+(ch^48);
	return x;
}
inline void write(int x) {
	if(x>9)write(x/10);
	pc(x%10^48);
}
const int maxn=1e6+10;
int f[maxn],fa[maxn],c[maxn];
int main() {
//	freopen("tree.in","r",stdin);
//	freopen("tree.out","w",stdout);
	int n=read()+1;
	for(int i=2;i<=n;i++) {
		fa[i]=read();
		int x=fa[i],y=i,fl=1;
		while(x) {
			int t=max(f[y]+c[y],1),tf=1;
			if(fa[x]&&max(f[x]+c[x],1)==f[fa[x]])tf=0;
			if(t<f[x]||(t==f[x]&&c[x]))break;
			else if(t==f[x]&&fl)c[x]=1;
			else if(t>f[x])f[x]=t,c[x]=0;
			else break;
			y=x,x=fa[x];
			fl=tf;
		}
		write(f[1]),pc(' ');
	}
	return Fl;
}