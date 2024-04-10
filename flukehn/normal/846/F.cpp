#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a),i##_end=(b);i<=i##_end;i++)
#define per(i,b,a) for(int i=(b),i##_st=(a);i>=i##_st;i--)
typedef long long ll;
inline int rd() {
	int x=0,c=0,f=1;
	for(; c<'0'||c>'9'; c=getchar())f=c!='-';
	for(; c>='0'&&c<='9'; c=getchar())x=x*10+c-'0';
	return f?x:-x;
}
#define pb push_back
const int N=1e6+11,M=1e6;
vector<int> v[N];
int n;
ll ans;
ll sqr(int x){
	return 1LL*x*x;
}
int main(){
	rep(i,1,M)v[i].pb(0);
	int n=rd();
	rep(i,1,n){
		int x=rd();
		v[x].pb(i);
	}
	//cout<<"ok"<<endl;
	rep(i,1,M){
		//cout<<i<<endl;
		v[i].pb(n+1);
		ans+=sqr(n);
		rep(j,1,v[i].size()-1){
			ans-=sqr(v[i][j]-v[i][j-1]-1);
		}
	}
	printf("%.6lf\n",1.0*ans/n/n);
}