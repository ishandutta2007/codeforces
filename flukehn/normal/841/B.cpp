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
const int N=1e6+5;
int a[N],flag;
int main(){
	int n=rd();
	rep(i,1,n){
		a[i]=rd();
		if(a[i]&1)flag++;		
	}
	if((flag&1)||flag){
		puts("First");
	}
	else puts("Second");
}