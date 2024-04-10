#include<bits/stdc++.h>
using namespace std;
#define I inline int
#define V inline void
#define ll long long int
#define isnum(ch) ('0'<=ch&&ch<='9')
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define ROF(i,a,b) for(int i=a;i>=b;i--)
#define REP(u) for(int i=h[u],v;v=e[i].t,i;i=e[i].n)
#define gc (_op==_ed&&(_ed=(_op=_buf)+fread(_buf,1,100000,stdin),_op==_ed)?EOF:*_op++)
char _buf[100000],*_op(_buf),*_ed(_buf);
I getint(){
	int _s=0,_f=1;char _ch=gc;
	while(!isnum(_ch))(_ch=='-')&&(_f=-1),_ch=gc;
	while(isnum(_ch))_s=_s*10+_ch-48,_ch=gc;
	return _s*_f;
}
const int N=2e5+10;
int T,n,k,tot,a[N],h[N],tag[N],b[N];
struct edge{int t,n;}e[N<<1];
V add_edge(int x,int y){
	e[++tot]=(edge){y,h[x]},h[x]=tot;
	e[++tot]=(edge){x,h[y]},h[y]=tot;
}
V input(){
	n=getint();
	FOR(i,1,n)a[i]=getint();
}
V init(){
	tot=0;
	FOR(i,1,n)tot+=!tag[a[i]]++;
}
int f[N][4];
V work(){
	a[n+1]=a[1];
	if(tot==1){
		cout<<1<<'\n';
		FOR(i,1,n)cout<<"1 ";
		cout<<'\n';
	}
	else if(tot==2){
		cout<<2<<'\n';
		tag[a[1]]=0;
		FOR(i,1,n)
			if(tag[a[i]])cout<<1<<' ';
			else cout<<2<<' ';
		cout<<'\n';
	}
	else{
		if(n%2==0){
			cout<<2<<'\n';
			FOR(i,1,n)cout<<i%2+1<<' ';
			cout<<'\n';
		}
		else{
			int flag=0,p=1;
			FOR(i,1,n)if(a[i]==a[i+1])flag=1;
			if(flag){
				cout<<2<<'\n',flag=0; 
				if(a[1]==a[n]){
					cout<<1<<' ';
					FOR(i,2,n-1)cout<<p+1<<' ',p^=1;
					cout<<1<<'\n'; 
				}
				else{
					FOR(i,1,n)if(a[i]==a[i+1]){
						b[i]=b[i+1]=1;
						ROF(j,i-1,1)b[j]=p+1,p^=1;
						p=1;
						FOR(j,i+2,n)b[j]=p+1,p^=1;
						break;
					}
					FOR(i,1,n)cout<<b[i]<<' ';
					cout<<'\n';
				}
			}
			else{
				cout<<3<<'\n';
				FOR(i,1,n-1)cout<<i%2+1<<' ';
				cout<<3<<'\n';
			}
		}
	}
	FOR(i,1,n)tag[a[i]]=0;
}
int main(){
	T=getint();
	while(T--){
		input();
		init();
		work();
	}
	return 0;
}