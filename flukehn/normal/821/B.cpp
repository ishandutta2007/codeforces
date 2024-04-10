#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
inline int rd(void) {
	int x = 0, c = 0, f = 1;
	for(;c<'0'||c>'9';c=getchar())f=c!='-';
	for(;c>='0'&&c<='9';c=getchar())x=x*10+c-'0';
	return f ? x : -x;
}
int m,b;
LL a[10010000];
int now,last;
LL ans;
LL cal(int n,int m){
	return 1LL*(n+1)*(m+1)*(n+m)/2;
}
int main(){
	m=rd(),b=rd();
	for(int i=0;i<=b;i++) {
		ans=max(ans,cal(i,(b-i)*m));
	}
	cout<<ans<<endl;
}