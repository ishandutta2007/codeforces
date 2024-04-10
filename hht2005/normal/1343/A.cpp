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
	int x=0;
	char ch=gc();
	for(;ch<'0'||ch>'9';ch=gc());
	for(;ch>='0'&&ch<='9';ch=gc())
		x=(x<<1)+(x<<3)+(ch^48);
	return x;
}
int main() {
	int T=read();
	while(T--) {
		int n=read(),ans=-1;
		for(int v=3;v<=n;v=v<<1|1)
			if(n%v==0) {
				ans=n/v;
				break;
			}
		printf("%d\n",ans);
	}
	return 0;
}