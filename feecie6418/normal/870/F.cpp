#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int mn[10000005],vst[10000005],mu[10000005],n,id[10000005],tot;
vector<int> tmp[10005];
ll S=0,T=0;
void Make(int x,int id){
	tmp[id].resize(x+1);
	for(int i=2;i<=x;i++)tmp[id][mn[i]]++;
	for(int i=1;i<=x;i++)tmp[id][i]+=tmp[id][i-1];
}
int main(){
	cin>>n,mu[1]=1,mn[1]=1e9;
	for(int i=2;i<=n;i++){
		if(vst[i])continue;
		mn[i]=i;
		for(ll j=1ll*i*i;j<=n;j+=i)if(!vst[j])vst[j]=1,mn[j]=i;
	}
	for(int i=2;i<=n;i++){
		if(mu[i/mn[i]]==0||(i/mn[i])%mn[i]==0)mu[i]=0;
		else mu[i]=-mu[i/mn[i]];
	}
	for(int i=1;i<=n;i++){
		S+=1ll*(n/i)*(n/i)*mu[i];
		if(!id[n/i])id[n/i]=++tot,Make(n/i,tot);
	}
	for(int j=2;j<=n;j++){
		if(mn[j]*2>n)continue;
		T+=tmp[id[n]][n/2]*3;
		T-=tmp[id[n]][n/mn[j]];
	}
	for(int i=2;i<=n;i++){
		if(!mu[i]||mn[i]>n/2)continue;
		T+=3ll*mu[i]*(n/i)*(n/i);
		for(int j=i;j<=n;j+=i){
			if(mn[i]<=n/mn[j])T-=mu[i]*(n/i);
			else T-=mu[i]*tmp[id[n/i]][min(n/i,n/mn[j])];
		}
	}
	cout<<(1ll*n*n-S-n+1+T)/2;
}