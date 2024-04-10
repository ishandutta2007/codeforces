#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
#define rnt re int
#define re register
#define I inline int
#define V inline void
#define ll long long int
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
const int N=1e3+1;
int n,k,a[N],s[N],b[N];
int p,x,val[N];
int A[N],tmp[N],m,tot;
V input(){cin>>n>>k;}
V test(){
	cin>>m;
	FOR(i,1,n)cin>>A[i];
}
bool cmp(rnt x,rnt y){return A[x]<A[y];}
V ask(const int*t){
	cout<<"? ";
	FOR(i,1,k)cout<<t[i]<<" \n"[i==k];
	cout.flush();
}
V getval(const int*t,int&np,int&nx){
	ask(t);
	cin>>np>>nx;
//	tot++;
//	FOR(i,1,k)tmp[i]=t[i];
//	sort(tmp+1,tmp+1+k,cmp);
//	np=tmp[m],nx=A[np];
}
V init(){
	FOR(i,1,k)a[i]=i;
	FOR(i,1,n)val[i]=-1;
	getval(a,p,x);
	rnt np,nx;
	FOR(i,k+1,n){
		FOR(j,1,k)
			if(a[j]==p)
				b[j]=i;
			else b[j]=a[j];
		getval(b,np,nx);
		if(nx>=x)
			val[i]=1;
		else{
			val[p]=1,p=np,x=nx;
			FOR(j,1,k)a[j]=b[j];
		}
	}
}
I Np(){
	static int np=1;
	while(!~val[np])
		np++;
	return np++;
}
V work(){
	rnt cnt=1,np,nx,nq;
	nq=Np();
	FOR(i,1,k)if(a[i]!=p){
		FOR(j,1,k)
			if(j==i)
				b[j]=nq;
			else b[j]=a[j];
		getval(b,np,nx);
		if(nx>x)cnt++;
	}
	cout<<"! "<<cnt,cout.flush();
//	cerr<<'\n'<<tot;
}
int main(){
//	freopen("test.in","r",stdin);
	input();
//	test();
	init();
	work();
	return 0;
}