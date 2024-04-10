#include<queue>
#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
#define rnt re int
#define re register
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
const int N=3e3+1;
int n,k,m;
int L[N],R[N];
char a[N];
V input(){scanf("%d%d%s",&n,&k,a+1);}
const char need[3]=")(";
V init(){
	m=0;
	FOR(i,1,n)if(a[i]!=need[i&1]){
		FOR(j,i,j+1)
			if((i&1)!=(j&1)&&a[j]!=need[j&1]){
				m++,L[m]=i,R[m]=j;
				reverse(a+i,a+j+1);
				break;
			}
	}
}
V work(){
	k=n/2-k;
	for(rnt p=2;k--;p+=2)
		m++,L[m]=p,R[m]=p+1;
	cout<<m<<'\n';
	FOR(i,1,m)cout<<L[i]<<' '<<R[i]<<'\n';
}
int main(){
//	freopen("test.in","r",stdin);
	int T;scanf("%d",&T);
	while(T--){
		input();
		init();
		work();
	}
	return 0;
}