#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=998244353;
int n,jc[1000005],ny[1000005];
int C(int x,int y){
	if(x<y||y<0||x<0)return 0;
	return 1ll*jc[x]*ny[y]%mod*ny[x-y]%mod;
}
int Power(int x,int y){
	int r=1;
	while(y){
		if(y&1)r=1ll*r*x%mod;
		x=1ll*x*x%mod,y>>=1;
	}
	return r;
}
ll s[100005],b[100005];
int a[100005],m,cnt[100005];
void Solve(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]),s[i]=s[i-1]+a[i];
	if(s[n]==0){
		cout<<Power(2,n-1)<<'\n';
		return ;
	}
	m=0;
	int ans=1;
	map<ll,int> mp;
	for(int i=0,j;i<=n;i=j+1){
		j=i;
		while(j<n&&s[j+1]==s[i])j++;
		b[++m]=s[i];
		cnt[m]=j-i+1;
		mp[s[i]]=m;
		//cout<<"B:"<<s[i]<<' '<<j-i+1<<'\n';
	}
	ll all=s[n];
	int pref=1;
	for(int i=1;i<=m;i++){
		if(b[i]*2>all)break;
		if(b[i]*2<all){
			int val=mp[all-b[i]];
			if(!val)continue;
			int A=cnt[i],B=cnt[val],num=0;//i,val
			if(b[i]==0)A--,B--;
			for(int j=1;j<=min(A,B);j++){
				num=(num+1ll*C(A,j)*C(B,j))%mod;
			}
			ans=(ans+1ll*pref*num)%mod;
			pref=1ll*pref*(num+1)%mod;
		}
		else {
			int num=(Power(2,cnt[i])-1+mod)%mod;
			ans=(ans+1ll*pref*num)%mod;
		}
	}
	cout<<ans<<'\n';
	for(int i=0;i<=n;i++){
		a[i]=s[i]=b[i]=cnt[i]=0;
	}
}
int main(){
	jc[0]=ny[0]=1;
	for(int i=1;i<=1000000;i++)jc[i]=1ll*jc[i-1]*i%mod;
	ny[1000000]=Power(jc[1000000],mod-2);
	for(int i=1000000-1;i;i--)ny[i]=1ll*ny[i+1]*(i+1)%mod;
	int t;
	scanf("%d",&t);
	while(t--)Solve();
}