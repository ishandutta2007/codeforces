#include<bits/stdc++.h>
using namespace std;
int n;
#define Maxn 205
#define cout cerr
#define FR first
#define SE second
char ch[Maxn];

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
		rd(n);scanf("%s",ch+1);
		sort(ch+1,ch+n+1);
		for(int i=1;i<=n;++i)putchar(ch[i]);puts("");
	}
	return 0;
}