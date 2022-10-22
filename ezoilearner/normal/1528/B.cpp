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
#define Maxn 1000010
const int Mod=998244353;
int h[Maxn],sum[Maxn];
	int add(int a,int b){return a+b>=Mod?a+b-Mod:a+b;}
	int mul(int a,int b){return 1ll*a*b%Mod;}

int main(){
	h[0]=sum[0]=1;
	rd(n);
	rep(i,1,n)
		for(int j=2*i;j<=n;j+=i)h[j]=add(h[j],1);
	rep(i,1,n){
		h[i]=add(h[i],sum[i-1]);
		sum[i]=add(sum[i-1],h[i]);
	}
	printf("%d\n",h[n]);
	return 0;
}