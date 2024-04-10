#include<cstdio>
#include<iostream>
#include<algorithm>
#define rnt re int
#define re register
#define I inline int
#define V inline void
#define ll long long int
#define isnum(ch) ('0'<=ch&&ch<='9')
#define FOR(i,A,B) for(re int i=A;i<=B;i++)
#define ROF(i,A,B) for(re int i=A;i>=B;i--)
using namespace std;
#define gc (_op==_ed&&(_ed=(_op=_buf)+fread(_buf,1,100000,stdin),_op==_ed)?EOF:*_op++)
char _buf[100000],*_op(_buf),*_ed(_buf);
I getint(){
	const int flag[2]={1,-1};
	rnt _s=0,_f=1;char _ch=gc;
	while(!isnum(_ch))_f=flag[_ch=='-'],_ch=gc;
	while(isnum(_ch))_s=_s*10+_ch-48,_ch=gc;
	return _s;
}
int main(){
	int T,x,y,z,w;
	cin>>T;
	while(T--){
		cin>>x>>y>>z;
		if(x+z<=y){
			cout<<"0\n";
			continue;
		}
		if(x>y+z){
			cout<<z+1<<'\n';
			continue;
		}
		w=(z+y-x)>>1;
		cout<<z-w<<'\n';
	}
	return 0;
}