#include<bits/stdc++.h>
using namespace std;

#define cout cerr
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)

typedef long long ll;
typedef pair<int,int> pii;
#define FR first
#define SE second

inline void rd(int &x){
	x=0;char ch=getchar();int f=1;
	while(ch<'0'||ch>'9'){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+ch-'0';
		ch=getchar();
	}
	x*=f;
}

const int Mod=998244353;
const int I2=499122177;
const int I6=166374059;
namespace modular{
	int dec(int a,int b){return a-b<0?a-b+Mod:a-b;}
	int add(int a,int b){return a+b>=Mod?a+b-Mod:a+b;}
	int mul(int a,int b){return 1ll*a*b%Mod;}
}using namespace modular;

int n;
#define Maxn 1000010
int h[Maxn];
int calc(int t){return mul(mul(mul(t,t+1),t+2),I6);}
int bin(int t){return mul(mul(t,t+1),I2);}
int sum(int n){
	if(n==0)return 1;
	
	int res=add(mul(2,h[n-1]),1);
	
	res=add(res,mul(bin(h[n-1]),2));
	res=add(res,mul(calc(h[n-1]),2));
	if(n>=2){
		rep(i,0,n-2){
			int t=h[i];if(i>0)t=dec(h[i],h[i-1]);
			res=add(res,mul(mul(bin(h[n-2-i]),t),2));
			res=add(res,mul(t,h[n-2-i]));
		}
	}
	rep(i,0,n-1){
		int t1=h[i];if(i>0)t1=dec(t1,h[i-1]);
		res=dec(res,mul(t1,h[n-1-i]));
	}
	return res;
}

int main(){
	rd(n);
	h[0]=1;
	rep(i,1,n){
		h[i]=add(h[i-1],bin(h[i-1]));		
		h[i]=add(h[i],1);
	}
	printf("%d\n",dec(sum(n),sum(n-1)));
	return 0;
}