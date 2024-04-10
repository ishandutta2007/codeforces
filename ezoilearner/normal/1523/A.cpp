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
#define Maxn 1005
char S[Maxn],T[Maxn];

int main(){
	int P;
	rd(P);
	while(P--){
		rd(n);rd(m);
		scanf("%s",S+1);
		while(m){
			bool fl=true;
			rep(i,1,n)
				if(S[i]=='1')T[i]='1';
				else{
					int c=0;
					if(i-1>=1&&S[i-1]=='1')c++;
					if(i+1<=n&&S[i+1]=='1')c++;
					c&=1;T[i]=c+'0';
					if(c)fl=false;
				}
			rep(i,1,n)S[i]=T[i];
			m--;
			if(fl)break;
		}
		printf("%s\n",S+1);
	}
	return 0;
}