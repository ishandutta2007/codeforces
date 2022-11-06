#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a),i##_end=(b);i<=i##_end;i++)
#define per(i,b,a) for(int i=(b),i##_st=(a);i>=i##_st;i--)
#define x first
#define y second
typedef long long ll;
inline int rd() {
	int x=0,c=0,f=1;
	for(; c<'0'||c>'9'; c=getchar())f=c!='-';
	for(; c>='0'&&c<='9'; c=getchar())x=x*10+c-'0';
	return f?x:-x;
}
const int N=5011;
ll a[N];
int n;
typedef pair<ll,int> pli;
#define mp make_pair
pli calc(int l,int r){
	ll ret=0;
	int pos=0;
	rep(i,l-1,r){
		ll k=(a[i]-a[l-1])-(a[r]-a[i]);
		if(k>ret)ret=k,pos=i;
	}
	return mp(ret,pos);
}
int main(){
	n=rd();
	rep(i,1,n){
		a[i]=rd()+a[i-1];
	}
	ll mx=0;
	int a=0,b=0,c=0;
	rep(i,0,n){
		pli x=calc(1,i),y=calc(i+1,n);
		if(x.x+y.x>mx){
			mx=x.x+y.x;
			a=x.y,b=i,c=y.y;
		}
	}
	cout<<a<<" "<<b<<" "<<c<<endl;
}