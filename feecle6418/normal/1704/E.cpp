#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pr;
typedef long long ll;
const int mod=998244353;
int n,m,pl[1005],ind[1005],f[1005];
ll a[1005],b[1005];
vector<int> g[1005];
void Cl(){
	for(int i=0;i<=n;i++){
		pl[i]=ind[i]=f[i]=a[i]=b[i]=0;
		g[i].clear();
	}
}
void Solve(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
	for(int i=1;i<=m;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		g[x].push_back(y);
	}
	if(*max_element(a+1,a+n+1)==0){
		puts("0"),Cl();
		return ;
	}
	for(int t=1;t<=n;t++){
		for(int i=1;i<=n;i++){
			if(a[i]>0){
				b[i]--;
				for(int j:g[i])b[j]++;
			}
		}
		for(int i=1;i<=n;i++)a[i]+=b[i],b[i]=0;
		if(*max_element(a+1,a+n+1)==0){
			cout<<t<<'\n',Cl();
			return ;
		}
	}
	for(int i=1;i<=n;i++)for(int j:g[i])ind[j]++;
	queue<int> q;
	for(int i=1;i<=n;i++)if(!ind[i])q.push(i);
	while(!q.empty()){
		int x=q.front();
		q.pop();
		pl[++pl[0]]=x;
		for(int y:g[x]){
			if(!(--ind[y]))q.push(y);
		}
	}
	f[pl[n]]=1;
	int sum=0;
	for(int i=n;i>=1;i--){
		int x=pl[i];
		for(int y:g[x]){
			f[x]=(f[x]+f[y])%mod;
		}
		sum=(sum+1ll*f[x]*(a[x]%mod))%mod;
	}
	cout<<(sum+n)%mod<<'\n';
	Cl();
}
int main(){
	int t;
	cin>>t;
	while(t--)Solve();
}