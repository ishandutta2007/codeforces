#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
#define rnt re int
#define re //register
#define I inline int
#define V inline void
#define isnum(ch) ('0'<=ch&&ch<='9')
#define FOR(i,a,b) for(rnt i=a;i<=b;i++)
#define ROF(i,a,b) for(rnt i=a;i>=b;i--)
#define gc (_op==_ed&&(_ed=(_op=_buf)+fread(_buf,1,100000,stdin),_op==_ed)?EOF:*_op++)
char _buf[100000],*_op(_buf),*_ed(_buf);
I getint(){
	static const int flag[2]={1,-1};
	rnt _s=0,_f=1;re char _ch=gc;
	while(!isnum(_ch))_f=flag[_ch=='-'],_ch=gc;
	while(isnum(_ch))_s=_s*10+_ch-48,_ch=gc;
	return _s*_f;
}
I max(const int&x,const int&y){return x>y?x:y;}
I min(const int&x,const int&y){return x<y?x:y;}
int x,y,z,ans;
V input(){
	x=getint(),y=getint(),z=getint();
}
V init(){
	if(x<y)swap(x,y);
	if(x<z)swap(x,z);
	if(y<z)swap(y,z);
}
V work(){
	while(!!x+!!y+!!z>=2){
		rnt d;
		if(x==z){
			ans+=x/2*3,x&=1,y&=1,z&=1;
			if(x==1){
				ans++;
				break;
			}
		}
		if(y==z)
			d=min(x-y,y),x-=2*d,y-=d,z-=d,ans+=d*2,init();
		d=y-z,ans+=d,x-=d,y-=d,init();
	}
	cout<<ans<<'\n';
}
int main(){
//	freopen("test.in","r",stdin);
	int T;T=getint();
	while(T--){
		ans=0;
		input();
		init();
		work();
	}	
	return 0;
}