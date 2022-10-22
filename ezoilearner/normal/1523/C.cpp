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

int n;
#define Maxn 1005
int a[Maxn],stk[Maxn],tp=0;

void output(){
	rep(i,1,tp-1)printf("%d.",stk[i]);printf("%d\n",stk[tp]);
}

int main(){
	int T;
	rd(T);
	while(T--){
		rd(n);
		int x;tp=0;
		rep(i,1,n)rd(a[i]);
		rep(i,1,n){
			x=a[i];
			if(x==1)stk[++tp]=1;
			else{
				while(tp&&stk[tp]!=x-1)tp--;
				stk[tp]++;
			}
			output();
	}
	}
	return 0;
}