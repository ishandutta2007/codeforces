#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXL=1<<22,dx[4]={1,-1,0,0},dy[4]={0,0,1,-1};
char i_str[MAXL],*i_s,*i_t;
char gc() {
	if(i_s==i_t) {
		i_s=i_str;
		i_t=i_s+fread(i_str,1,MAXL,stdin);
		return i_s==i_t?EOF:*i_s++;
	} else return *i_s++;
}
int read() {
	int x=0,f=0;
	char ch=gc();
	for(;ch<'0'||ch>'9';ch=gc())
		if(ch=='-')f=1;
	for(;ch>='0'&&ch<='9';ch=gc())
		x=x*10+(ch^48);
	return f?-x:x;
}
const int maxn=1e5+10;
int a[maxn],X[maxn],Y[maxn],Z[maxn],cnt;
void opt(int x,int y,int z) {
	X[++cnt]=x;
	Y[cnt]=y;
	Z[cnt]=z;
	a[x]=a[y]=a[z]=a[x]^a[y]^a[z];
}
signed main() {
	int n=read(),sum=0;
	for(int i=1;i<=n;i++)sum^=(a[i]=read());
	if(n&1) {
		A:for(int i=n;i>=3;i-=2)opt(i,i-1,i-2);
		for(int i=4;i+1<=n;i+=2)opt(1,i,i+1);
	} else if(!sum) {
		n--;
		goto A;
	} else {
		puts("NO");
		return 0;
	}
	puts("YES");
	printf("%d\n",cnt);
	for(int i=1;i<=cnt;i++)
		printf("%d %d %d\n",X[i],Y[i],Z[i]);
	return 0;
}