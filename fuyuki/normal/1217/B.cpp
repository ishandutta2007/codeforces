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
I max(const int&x,const int&y){return x>y?x:y;}
int main(){
//	freopen("test.in","r",stdin);
	int T,sum,dis,maxn,x,y,n;
	cin>>T;
	while(T--){
		n=getint(),sum=getint();
		dis=-1,maxn=-1;
		while(n--){
			x=getint(),y=getint();
			dis=max(dis,x-y);
			maxn=max(maxn,x);
		}
		if(maxn>=sum){
			cout<<"1\n";
			continue;
		}
		if(dis<=0){
			cout<<"-1\n";
			continue;
		}
		sum-=maxn,x=sum/dis;
		x+=sum%dis>0;
		cout<<x+1<<'\n';
	}
	return 0;
}