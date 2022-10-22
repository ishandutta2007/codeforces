#include<bits/stdc++.h>
using namespace std;
int n,m,a;
#define Maxn 105
#define cout cerr
#define FR first
#define SE second
int val[Maxn<<1];

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
		rd(n);rd(m);
		for(int i=2;i<=n+m;++i)val[i]=0;
		for(int i=1;i<=n;++i)
			for(int j=1;j<=m;++j){
				rd(a);
				val[i+j]^=a;
			}
		bool flag=true;
		for(int i=2;i<=n+m;++i)
			if(val[i]>0){
				puts("Ashish");
				flag=false;
				break;
			}
		if(flag){
			puts("Jeel");
			continue;
		}
	}
	return 0;
}