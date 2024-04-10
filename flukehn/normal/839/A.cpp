#include<bits/stdc++.h>
using namespace std;
#define debug(x) std::cerr << #x << " = " << x << std::endl
#define FOR(i,s,t) for(int i=s;i<=t;i++)
#define FEO(x) {freopen(#x".in","r",stdin),freopen(#x".out","w",stdout);}
inline int rd() {
	int x=0,c=0,f=1;
	for(; c<'0'||c>'9'; c=getchar())f=c!='-';
	for(; c>='0'&&c<='9'; c=getchar())x=x*10+c-'0';
	return f?x:-x;
}
int a[111],n,K,tmp;
int main(){
	n=rd(),K=rd();
	FOR(i,1,n)a[i]=rd();
	int now=0;
	FOR(i,1,n){
		if(tmp+a[i]>=8){
			now+=8;
			tmp+=a[i]-8;
		}else {
			now+=a[i]+tmp;
			tmp=0;
		}
		if(now>=K){
			cout << i << endl;
			return 0;
		}
	}
	puts("-1");
}