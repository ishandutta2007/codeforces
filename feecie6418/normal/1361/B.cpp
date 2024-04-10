#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=1e9+7;
int n,p,a[1000005],cnt[1000005],cc[1000005],ans=0;
int Power(int x,int y){
	int r=1;
	while(y){
		if(y&1)r=1ll*r*x%mod;
		x=1ll*x*x%mod,y>>=1;
	}
	return r;
}
int main() {
	int T;
	cin>>T;
	while(T--){
		scanf("%d%d",&n,&p),ans=0;
		for(int i=1;i<=n;i++)scanf("%d",&a[i]),cnt[a[i]]++,cc[a[i]]++;
		if(p==1){
			cout<<n%2<<'\n';
			for(int i=1;i<=n;i++)cnt[a[i]]=cc[a[i]]=0;
			continue;
		}
		sort(a+1,a+n+1);
		int F=0;
		for(int q=n;q>=1;q--){
			if(a[q]==a[q+1]&&q!=n)continue;
			int i=a[q],flag=0;
			if(cnt[i]%2==0)continue;
			ll o=p;
			for(int k=i-1;k>=0;k--,o*=p){
				if(o>=2e12)break;
				if(cnt[k]>=o){
					cnt[k]-=o,flag=1;
					break;
				}
				o-=cnt[k],cnt[k]=0;
			}
			if(!flag){
				ans=Power(p,i),F=1;
				for(int j=1;a[j]<i;j++)ans=(ans-1ll*Power(p,a[j])+mod)%mod;
				cout<<ans<<'\n';
				break;
			}
		}
		if(!F)puts("0");
		for(int i=1;i<=n;i++)cnt[a[i]]=cc[a[i]]=0;
	}
}