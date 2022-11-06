#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a),i##_end=(b);i<=i##_end;i++)
#define per(i,b,a) for(int i=(b),i##_st=(a);i>=i##_st;i--)
inline int rd() {
	int x=0,c=0,f=1;
	for(; c<'0'||c>'9'; c=getchar())f=c!='-';
	for(; c>='0'&&c<='9'; c=getchar())x=x*10+c-'0';
	return f?x:-x;
}
const int N=40,M=3e5+11;
const int inf=0x7fffffff;
int f[2][N],now,last;
int a[M];
int n;
void solve(){
	now=1;
	memset(f[1],0x7f,sizeof f[1]);
	f[1][0]=0;
	rep(i,1,n){
		swap(now,last);
		memset(f[now],0x7f,sizeof f[now]);
		int b=a[i]/10;
		rep(j,0,30-a[i]){
			f[now][j]=f[last][j+a[i]];
		}
		rep(j,0,a[i]-1){
			f[now][0]=min(f[now][0],f[last][j]+a[i]-j);
		}
		rep(j,b,30){
			f[now][j]=min(f[now][j],f[last][j-b]+a[i]);
		}
	}
}
int main(){
	n=rd();
	rep(i,1,n){
		a[i]=rd()/100;
	}
	solve();
	int mx=inf;
	rep(i,0,30){
		mx=min(mx,f[now][i]);
	}
	cout<<1LL*mx*100<<endl;
	return 0;
}