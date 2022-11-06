#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a),i##_end=(b);i<=i##_end;i++)
#define per(i,b,a) for(int i=(b),i##_st=(a);i>=i##_st;i--)
inline int rd() {
	int x=0,c=0,f=1;
	for(; c<'0'||c>'9'; c=getchar())f=c!='-';
	for(; c>='0'&&c<='9'; c=getchar())x=x*10+c-'0';
	return f?x:-x;
}
int c[465],cnt,tot;
void p(int x,int f=0) {
	c[++cnt]=x;
	if(f)tot+=9-x;
	else tot-=x;
}
int main() {
	int x=rd();
	int a=x/1000,b=x%1000;
	p(9-a%10,1),p(9-a/10%10,1),p(9-a/100,1);
	p(b%10),p(b/10%10),p(b/100);
	sort(c+1,c+cnt+1);
	int now=0;
	if(!tot) {
		puts("0");
		return 0;
	}
	else if(tot<0) {
		per(i,cnt,1) {
			now+=c[i];
			if(now>=-tot) {
				printf("%d\n",cnt-i+1);
				return 0;
			}
		}
	} else {
		rep(i,1,cnt) {
			now+=9-c[i];
			if(now>=tot) {
				printf("%d\n",i);
				return 0;
			}
		}
	}
}