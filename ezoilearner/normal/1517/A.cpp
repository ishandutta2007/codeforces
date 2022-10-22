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

int T;ll n;
#define Maxn

int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%lld",&n);
		if(n%2050!=0)puts("-1");
		else{
			n/=2050;
			int cnt=0;
			while(n>0){
				cnt+=n%10;
				n/=10;
			}
			printf("%d\n",cnt);
		}
	}
	return 0;
}