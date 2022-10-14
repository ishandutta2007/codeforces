#include<bits/stdc++.h>
using namespace std;
#define I inline int
#define V inline void
#define ll long long int
#define isnum(ch) ('0'<=ch&&ch<='9')
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define ROF(i,a,b) for(int i=a;i>=b;i--)
#define gc (_op==_ed&&(_ed=(_op=_buf)+fread(_buf,1,100000,stdin),_op==_ed)?EOF:*_op++)
char _buf[100000],*_op(_buf),*_ed(_buf);
I getint(){
	static const int flag[2]={1,-1};
	int _s=0,_f=1;char _ch=gc;
	while(!isnum(_ch))_f=flag[_ch=='-'],_ch=gc;
	while(isnum(_ch))_s=_s*10+_ch-48,_ch=gc;
	return _s*_f;
}
const int N=1e3+1;
int n,m,top,cnt;
int a[N],b[N],c[N],out[N][N];
//int n;
char st[N];
V input(){
	scanf("%s",st+1),n=strlen(st+1);
}
V init(){
}
V work(){
	int l=1,r=n;
	
	while(l<r){
		while(l<=n&&st[l]==')')l++;
		while(r>=1&&st[r]=='(')r--;
		if(l>r)break;
		a[l++]=a[r--]=1,m+=2;
	}
	if(!m)return void(cout<<0);
	cout<<1<<'\n'<<m<<'\n';
	FOR(i,1,n)if(a[i])cout<<i<<' ';
}
int main(){
//	for(int T=getint();T--;){
		input();
		init();
		work();
//	}
	return 0;
}