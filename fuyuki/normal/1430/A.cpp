#include<bits/stdc++.h>
using namespace std;
#define I inline int
#define V inline void
#define B inline bool
#define ll long long int
#define isnum(ch) ('0'<=ch&&ch<='9')
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define ROF(i,a,b) for(int i=a;i>=b;i--)
#define gc (_op==_ed&&(_ed=(_op=_buf)+fread(_buf,1,100000,stdin),_op==_ed)?EOF:*_op++)
char _buf[100000],*_op(_buf),*_ed(_buf);
I getint(){
	int _s=0,_f=1;char _ch=gc;
	while(!isnum(_ch))(_ch=='-')&&(_f=-1),_ch=gc;
	while(isnum(_ch))_s=_s*10+_ch-48,_ch=gc;
	return _s*_f;
}
const int N=2e3+1;
int n,tag[N],f[N][3];
V input(){
	tag[0]=1,n=N-1;
	FOR(i,1,n){
		if(i>=3&&tag[i-3]){
			FOR(j,0,2)f[i][j]=f[i-3][j];
			tag[i]=1,f[i][0]++;
		}
		if(i>=5&&tag[i-5]){
			FOR(j,0,2)f[i][j]=f[i-5][j];
			tag[i]=1,f[i][1]++;
		}
		if(i>=7&&tag[i-7]){
			FOR(j,0,2)f[i][j]=f[i-7][j];
			tag[i]=1,f[i][2]++;
		}
	}
}
V init(){
	for(int T=getint();T--;){
		n=getint();
		if(tag[n])cout<<f[n][0]<<' '<<f[n][1]<<' '<<f[n][2]<<'\n';
		else cout<<"-1\n";
	}
}
V work(){
	
}
int main(){
//	freopen("test.in","r",stdin);
	input();
	init();
	work();
	return 0;
}