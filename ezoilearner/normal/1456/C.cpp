#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,K;
#define Maxn 500010
int a[Maxn];
ll sum[Maxn];

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

ll h1[Maxn],h2[Maxn];

int main(){
	rd(n);rd(K);K++;
	for(int i=1;i<=n;++i)rd(a[i]); 
	sort(a+1,a+n+1);
	for(int i=1;i<=n;++i)h1[i]=h1[i-1]+a[i],h2[i]=h2[i-1]+1ll*i*a[i];
	int len=0;
	while(len+1<=n&&a[len+1]<0)len++;
	sum[0]=0;ll all=0;
	for(int i=len+1;i<=n;++i){
		sum[0]+=1ll*(i-len-1)*a[i];
		all+=a[i];
	}		
	for(int i=1;i<=n;++i)sum[i]=sum[i-1]+all;
	if(!len){
		cout<<sum[0]<<endl;
		return 0;
	}
	ll Ans=-1000000000000000000ll;
	int at=0,c=1;ll pre=0;
	for(int i=1;i<=len;++i){
		pre+=1ll*at*a[i];
		//(pos-i+at)*a_pos
		Ans=max(Ans,pre+sum[len+1-i+at]+1ll*(h1[len]-h1[i])*(at-i)+h2[len]-h2[i]);
		c++;
		if(c==K+1){
			c=1;
			at++;
		}
	}
	printf("%lld\n",Ans);
	return 0;
}