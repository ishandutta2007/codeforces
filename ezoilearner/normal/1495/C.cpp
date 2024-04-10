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

int n,m;
#define Maxn 505
char a[Maxn][Maxn];

int main(){
	int T;rd(T);
	while(T--){
		rd(n);rd(m);
		rep(i,1,n)scanf("%s",a[i]+1);
		int st;st=2;
		if(m<=2){
			rep(i,1,n)a[i][1]='X';
		}else{
		if(m%3==1){
			for(int j=1;j<=m;j+=3)
				rep(i,1,n)a[i][j]='X';
			st=1;
		}else{
			for(int j=2;j<=m;j+=3)
				rep(i,1,n)a[i][j]='X';
		}
		while(st+3<=m){
			int at=1;
			rep(i,1,n)
				if(a[i][st+1]=='X'||a[i][st+2]=='X'){
					at=i;
					break;
				}
			a[at][st+1]=a[at][st+2]='X';
			st+=3;
		}
	}
		rep(i,1,n){
			rep(j,1,m)putchar(a[i][j]);
			puts("");
		}
	}
	return 0;
}