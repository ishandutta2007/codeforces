#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
#define Maxn 200010
#define cout cerr
#define FR first
#define SE second
ll sum[Maxn];
int a[Maxn];

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
	rd(n);
	for(int i=1;i<=n;++i){
		rd(a[i]);
		sum[i]=sum[i-1]+a[i];
	}
	int Ans=0;
	for(int i=1;i<=n-2;++i)
		for(int j=i+1;j<n&&sum[j]-sum[i]<=2ll*a[i];++j)
			if((a[i]^a[j+1])==sum[j]-sum[i])Ans++;
	for(int j=3;j<=n;++j)
		for(int i=j-1;i>1&&sum[j-1]-sum[i-1]<=2ll*a[j];--i)
			if((a[j]^a[i-1])==sum[j-1]-sum[i-1]){
				Ans++;
				if(sum[j-1]-sum[i-1]<=2ll*a[i-1])Ans--;
			}
	printf("%d\n",Ans);
	return 0;
}