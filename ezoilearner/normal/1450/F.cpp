#include<bits/stdc++.h>
using namespace std;
int n;
#define Maxn 100010
#define cout cerr
#define FR first
#define SE second
int a[Maxn];
int val[Maxn];

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
		rd(n);
		int L=0;
		memset(val,0,sizeof(int)*(n+1));
		for(register int i=1;i<=n;++i)rd(a[i]);
		val[a[1]]++;val[a[n]]++;
		for(int i=1;i<n;++i)
			if(a[i]==a[i+1]){
				L++;
				val[a[i]]+=2;
			}
		int mx=0,pos;
		for(int i=1;i<=n;++i)
			if(val[i]>mx){
				mx=val[i];
				pos=i;
			}
		if(mx<=L+2)printf("%d\n",L);
		else{
			int res=0;
			for(int i=1;i<n;++i)
				if(a[i]!=a[i+1]&&a[i]!=pos&&a[i+1]!=pos)res++;
			mx-=L+2;
			if(res<mx){
				puts("-1");
			}else{
				L+=mx;
				printf("%d\n",L);
			}
		}
	}
	return 0;
}