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
int main() {
	int T=read();
	while(T--) {
		int x=read(),ans=0;
		while(x>=10) {
			ans+=x/10*10;
			x=x/10+x%10;
		}
		printf("%d\n",ans+x);
	}
	return 0;
}