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
int main(){
	int l=rd(),r=rd(),x=rd(),y=rd(),k=rd();
	rep(i,x,y){
		long long z=1LL*i*k;
		if(z<=r&&z>=l){
			puts("YES");
			return 0;
		}
	}
	puts("NO");
}