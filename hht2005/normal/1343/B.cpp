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
		int n=read();
		if(!((n/2)&1)) {
			puts("YES");
			int cnt=2;
			for(int i=1;i<=n/4;i++) {
				printf("%d ",cnt);
				cnt+=2;
				printf("%d ",cnt);
				cnt+=4;
			}
			cnt=1;
			for(int i=1;i<=n/4;i++) {
				printf("%d ",cnt);
				cnt+=4;
				printf("%d ",cnt);
				cnt+=2;
			}
			puts("");
		}
		else puts("NO");
	}
	return 0;
}