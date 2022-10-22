#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define db double
#define ull unsigned long long
#define ldb long double
#define pb push_back
#define fir first
#define sec second
#define pii pair<int,int>
#define pil pair<int,ll>
#define pli pair<ll,int>
#define pll pair<ll,ll>
#define mp make_pair
#define inl inline
#define min(a,b) (a)<(b)?(a):(b)
#define max(a,b) (a)>(b)?(a):(b)
inl int read(){
	int x=0,f=1;char c=getchar();
	while(c<'0' || c>'9') {if(c=='-')f=-1;c=getchar();}
	while(c>='0' && c<='9') {x=x*10+c-'0';c=getchar();}
	return x*f;
}
int n,q,a[210],Pos;
int main(){
	q=read();while(q--){
		n=read();
		for(int i=1;i<=n;i++) a[i]=read();
		for(int i=1;i<=n;i++) if(a[i]==1) Pos=i;
		int flag=1;
		for(int i=Pos+1;i<=n && flag;i++) if(a[i]!=a[i-1]+1) flag=0;
		if(Pos!=1 && a[1]!=a[n]+1) flag=0;
		for(int i=2;i<Pos;i++) if(a[i]!=a[i-1]+1) flag=0;
		if(flag) {puts("YES");continue;}
		flag=1;
		for(int i=Pos-1;i>=1 && flag;i--) if(a[i]!=a[i+1]+1) flag=0;
		if(Pos!=n && a[n]!=a[1]+1) flag=0;
		for(int i=n-1;i>Pos;i--) if(a[i]!=a[i+1]+1) flag=0;
		if(flag) puts("YES");
		else puts("NO");
	}
	return 0;
}