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
int r,d;
#define eps 1e-7
int main(){
	r=rd(),d=rd();
	d=r-d;
	int n=rd(),tot=0;
	rep(i,1,n){
		int x=rd(),y=rd(),R=rd();
		double t=sqrt(x*x+y*y);
		tot+=(t-R>=d&&t+R<=r);
	}
	cout<<tot<<endl;
}