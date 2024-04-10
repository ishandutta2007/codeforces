#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
#define FR first
#define SE second

#define cout cerr
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)

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

int n,q;
#define Maxn 100010
int a[Maxn],b[2];

int main(){
	rd(n);rd(q);
	rep(i,1,n)rd(a[i]),b[a[i]]++;
	rep(i,1,q){
		int opt,x;
		rd(opt);rd(x);
		if(opt==1){
			b[a[x]]--;a[x]^=1;b[a[x]]++;
		}else{
			if(b[1]>=x)puts("1");
			else puts("0");
		}
	}
	return 0;
}