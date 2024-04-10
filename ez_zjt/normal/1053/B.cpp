#include <bits/stdc++.h>
#define MAXN 300010
#define LL long long
using namespace std;

int n;
int a[MAXN];
int s[MAXN];

LL read(){
	char c;
	while((c=getchar())<'0' || c>'9');
	LL res=c-'0';
	while((c=getchar())>='0' && c<='9') res=res*10+c-'0';
	return res;
}

int bitcnt(LL x){
	int res=0;
	while(x){
		res++;
		x^=x&(-x);
	}
	return res;
}

int main(){
#ifdef DEBUG
	freopen("B.in","r",stdin);
#endif
	scanf("%d",&n);
	int c0=1,c1=0,cs=0;
	LL ans=0;
	for(int i=1;i<=n;i++){
		a[i]=bitcnt(read());
		(cs+=a[i])&=1;
		if(cs) ans+=c1,c1++;
		else ans+=c0,c0++;
		s[i]=s[i-1]+a[i];
	}
	for(int i=1;i<=n;i++){
		int maxv=a[i];
		for(int j=i;j<=i+70 && j<=n;j++){
			if(a[j]>maxv) maxv=a[j];
			int ts=s[j]-s[i-1];
			if(ts%2==0 && maxv>ts-maxv) ans--;
		}
	}
	cout<<ans<<endl;
}