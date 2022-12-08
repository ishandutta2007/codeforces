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
inline long long read() {
	long long x=0;
	char ch=gc();
	for(;ch<'0'||ch>'9';ch=gc());
	for(;ch>='0'&&ch<='9';ch=gc())
		x=(x<<1)+(x<<3)+(ch^48);
	return x;
}
int s[40010];
long long calc(long long x,int c) {
	return x/c*s[c]+s[x%c];
}
int main() {
	int T=read();
	while(T--) {
		int a=read(),b=read(),q=read(),c;
		for(c=1;c%a||c%b;c++)
			s[c]=s[c-1]+(c%a%b!=c%b%a);
		s[c]=s[c-1];
		while(q--) {
			long long l=read(),r=read();
			printf("%lld ",calc(r,c)-calc(l-1,c));
		}
		puts("");
	}
	return 0;
}