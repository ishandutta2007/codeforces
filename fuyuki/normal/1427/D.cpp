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
const int N=2e5+1,mod=998244353,INF=0x3f3f3f3f;
V check(int&x){x-=mod,x+=x>>31&mod;}
V cmax(int&x,int y){if(x-y>>31)x=y;}
V cmin(int&x,int y){if(y-x>>31)x=y;}
int n,cnt,flag,a[N],b[N];
vector<int>tmp[N],out[N];
V input(){
	n=getint();
	FOR(i,1,n)b[i]=a[i]=getint();
}
V rev(int l,int r){
	if(l==1&&r==n)return;
//	if(l==r)flag^=1;
	flag^=1,out[++cnt].clear();
	FOR(i,1,n)tmp[i].clear();
	int tot=0;
//	cout<<n-r+l<<' ';
	FOR(i,1,n){
		if(i<=l||i>r)tot++,out[cnt].push_back(0);
		tmp[tot].push_back(a[i]),out[cnt].back()++;
	}
	reverse(tmp+1,tmp+1+tot),tot=0;
	FOR(i,1,n)for(int x:tmp[i])a[++tot]=x;
//	cout<<'\n';
}
V init(){
	if(n==1)return void(cout<<0);
	begin:
	if(n&1){
		FOR(j,1,n)if(a[j]==1){
			rev(j,n);
			break;
		}
	}
	else{
		FOR(j,1,n)if(a[j]==1){
			rev(1,j);
			break;
		}
	}
	flag=n&1;
	FOR(i,2,n){
		if(flag){
			FOR(j,1,n)if(a[j]==i){
				rev(i,j);
				break;
			}
		}
		else{
			FOR(j,1,n)if(a[j]==i){
				rev(j,n-i+1);
				break;
			}
		}
	}
//	FOR(i,1,n)assert(a[i]==i);
	cout<<cnt<<'\n';
	FOR(i,1,cnt){
		cout<<out[i].size()<<' ';
		for(int x:out[i])cout<<x<<' ';
		cout<<'\n';
	}
//	FOR(i,1,n)if(a[i]!=i){
//		flag=n&1^1,cnt=0;
//		FOR(j,1,n)a[j]=b[j];
//		goto begin;
//	}
}
V work(){
	
}
int main(){
//	freopen("test.in","r",stdin);
//	freopen(".out","w",stdout);
//	for(scanf("%d",&T);T--;){
		input();
		init();
		work();
//	}
	return 0;
}