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

const int Mod=998244353;
int mul(int a,int b){return 1ll*a*b%Mod;}
const int N=1e5;
int n;
#define Maxn 100010
char s[Maxn];
int fact[Maxn],inv[Maxn],ifac[Maxn];
void init(){
	fact[0]=1;rep(i,1,N)fact[i]=mul(fact[i-1],i);
	inv[0]=inv[1]=1;rep(i,2,N)inv[i]=mul(Mod-Mod/i,inv[Mod%i]);
	ifac[0]=1;rep(i,1,N)ifac[i]=mul(ifac[i-1],inv[i]);
}

int main(){
	init();
	int T;rd(T);
	while(T--){
		rd(n);
		scanf("%s",s+1);
		int m=0;rep(i,1,n)if(s[i]=='0')m++;
		int cnt=0;
		for(int i=1;i<n;++i)
			if(s[i]=='1'&&s[i+1]=='1'){
				cnt++;++i;
			}
		printf("%d\n",mul(fact[cnt+m],mul(ifac[m],ifac[cnt])));
	}
	return 0;
}