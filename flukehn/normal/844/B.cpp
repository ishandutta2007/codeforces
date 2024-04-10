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
int A[55][55];
typedef long long ll;
int main(){
	int n=rd(),m=rd();
	rep(i,1,n)rep(j,1,m)A[i][j]=rd();
	ll ans=0;
	rep(i,1,n){
		int tot=0;
		rep(j,1,m){
			tot+=A[i][j];
		}
		ans+=1LL<<tot;
		ans+=1LL<<m-tot;
		ans-=2;
	}
	rep(j,1,m){
		int tot=0;
		rep(i,1,n){
			tot+=A[i][j];
		}
		ans+=1LL<<tot;
		ans+=1LL<<n-tot;
		ans-=n+2;
	}
	cout<<ans<<endl;
}