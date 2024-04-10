#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=998244353;
int n,a[1000005],cnt[1000005],jc[1000005],ny[1000005],inv[1000005];
int ans[1000005],ans2[1000005];
vector<int> has;
int Power(int x,int y){
	int r=1;
	while(y){
		if(y&1)r=1ll*r*x%mod;
		x=1ll*x*x%mod,y>>=1;
	}
	return r;
}
int Calc(int w){
	if(ans[w])return ans[w];
	ans[w]=jc[n/w];
	for(int i:has)ans[w]=1ll*ans[w]*ny[cnt[i]/w]%mod;
	return ans[w];
}
int Calc2(int w){
	if(ans2[w])return ans2[w];
	int fm=1ll*(n/w)*(n/w-1)%mod,fz=0;
	for(int i:has)fz=(fz+1ll*(cnt[i]/w)*(cnt[i]/w-1))%mod;
	ans2[w]=1ll*fz*Power(fm,mod-2)%mod;
	ans2[w]=1ll*ans2[w]*n%mod;
	return ans2[w];
}
void Solve(){
	scanf("%d",&n),has.clear();
	for(int i=1;i<=n;i++)scanf("%d",&a[i]),cnt[a[i]]++;
	if(cnt[a[1]]==n){
		cnt[a[1]]=0,cout<<"1\n";
		return ;
	}
	int g=n,cou=0,all=0;
	for(int i=1;i<=n;i++)if(cnt[i])g=__gcd(g,cnt[i]),has.push_back(i);
	for(int i=1;i<=n;i++){
		int w=n/__gcd(i,n);
		if(g%w)continue;
		cou=(cou+Calc(w))%mod;
		all=(all+1ll*Calc(w)*Calc2(w))%mod;
	}
	cout<<(n-1ll*all*Power(cou,mod-2)%mod+mod)%mod<<'\n';
	for(int i=1;i<=n;i++)cnt[i]=ans[i]=ans2[i]=0;
}
int main(){
	jc[0]=ny[0]=inv[1]=1;
	for(int i=2;i<=1000000;i++)inv[i]=1ll*inv[mod%i]*(mod-mod/i)%mod;
	for(int i=1;i<=1000000;i++)ny[i]=1ll*ny[i-1]*inv[i]%mod,jc[i]=1ll*jc[i-1]*i%mod;
	int t;
	scanf("%d",&t);
	while(t--)Solve();
}