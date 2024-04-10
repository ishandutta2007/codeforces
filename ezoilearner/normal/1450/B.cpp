#include<bits/stdc++.h>
using namespace std;
int n,K;
#define Maxn 205
#define cout cerr
#define FR first
#define SE second
int x[Maxn],y[Maxn];
bool Judge(int id){
	for(int i=1;i<=n;++i)
		if(abs(x[i]-x[id])+abs(y[i]-y[id])>K)return false;
	return true;
}

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

int main(){
	int T;rd(T);
	while(T--){
		rd(n);rd(K);
		for(int i=1;i<=n;++i){
			rd(x[i]);rd(y[i]);
		}
		bool flag=false;
		for(int i=1;i<=n;++i)
		if(Judge(i)){
			flag=true;
			puts("1");
			break;
		}
		if(!flag)puts("-1");
	}
	return 0;
}