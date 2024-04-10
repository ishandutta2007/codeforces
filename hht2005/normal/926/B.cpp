#include<bits/stdc++.h>
using namespace std;
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
inline int read() {
	int x=0,f=0;
	char ch=gc();
	for(;ch<'0'||ch>'9';ch=gc())
		if(ch=='-')f=1;
	for(;ch>='0'&&ch<='9';ch=gc())
		x=(x<<1)+(x<<3)+(ch^48);
	return f?-x:x;
}
int p[100010];
int gcd(int x,int y) {
	if(!x||!y)return x+y;
	while(y^=x^=y^=x%=y);
	return x;
}
int main() {
	int n=read(),d=0,ans=0;
	for(int i=1;i<=n;i++)
		p[i]=read();
	sort(p+1,p+n+1);
	for(int i=2;i<=n;i++)
		d=gcd(d,p[i]-p[i-1]);
	for(int i=2;i<=n;i++)
		ans+=(p[i]-p[i-1])/d-1;
	printf("%d\n",ans);
	return 0;
}