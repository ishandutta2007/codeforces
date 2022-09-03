#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define x first
#define y second
#define N 131072
#define pi acos(-1)
#define sqr(x) ((x)*(x))
int mod=1e9+7;
LL f_pow(LL a,LL b){
	LL res=1,temp=a;
	while(b){
		if(b&1)res=res*temp%mod;
		temp=temp*temp%mod;
		b>>=1;
	}
	return res;
}
int main(){
	LL n,m;
	scanf("%lld %lld",&n,&m);
	int a[100005];
	int b[100005];
	LL now=1;
	LL ans=0;
	for(int i =0;i<n;i++)
		scanf("%d",&a[i]);
	for(int i = 0;i<n;i++)
		scanf("%d",&b[i]);
	for(int i = 0;i<n;i++){
		if(a[i]==b[i]&&a[i]==0){
			ans += now*(m*(m-1)/2%mod)%mod*f_pow(m*m%mod,mod-2)%mod;
			ans %=mod;
			now=now*f_pow(m,mod-2)%mod;
		}
		else if(a[i]==0){
			ans += now*(m-b[i])%mod*f_pow(m,mod-2)%mod;
			ans %=mod;
			now = now*f_pow(m,mod-2)%mod;
		}
		else if(b[i]==0){
			ans+= now*(a[i]-1)%mod*f_pow(m,mod-2)%mod;
			ans %=mod;
			now = now*f_pow(m,mod-2)%mod;
		}
		else{
			if(a[i]==b[i]);
			else if(a[i]<b[i])now=0;
			else{
				ans = (ans+now)%mod;
				now=0;
			}
		}
	//	printf("%lld\n",ans);
	}
	printf("%lld\n",ans);
}