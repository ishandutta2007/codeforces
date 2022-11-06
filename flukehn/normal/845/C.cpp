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
const int N=2e5+5;
typedef pair<int,int> pi;
pi a[N];
#define x first
#define y second
int main(){
	int n=rd();
	rep(i,1,n){
		a[i].x=rd(),a[i].y=rd();
	}
	sort(a+1,a+n+1);
	int t1=-1,t2=-1;
	rep(i,1,n){
		if(a[i].x>t1)t1=a[i].y;
		else if(a[i].x>t2)t2=a[i].y;
		else return puts("NO"),0;
	}
	puts("YES");
}