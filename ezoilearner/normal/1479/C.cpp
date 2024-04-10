#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
int n=22,L,R;
#define Maxn 405
#define cout cerr
#define FR first
#define SE second

int a[Maxn],b[Maxn],c[Maxn],cnt;
void add(int s,int e,int t){
	cnt++;
	a[cnt]=s;b[cnt]=e;c[cnt]=t;
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
	rd(L);rd(R);
	puts("YES");
	printf("%d ",n);
	rep(i,2,n-1){
		int at=1;
		add(1,i,1);
		at++;
		rep(j,2,i-1){
			add(j,i,at-1);
			at+=(1<<(j-2));
		}
	}
	add(1,n,L);int at=L+1;
	rep(i,0,19)
		if((R-L)&(1<<i))add(i+2,n,at-1),at+=(1<<i);	
	printf("%d\n",cnt);
	rep(i,1,cnt)printf("%d %d %d\n",a[i],b[i],c[i]);
	return 0;
}