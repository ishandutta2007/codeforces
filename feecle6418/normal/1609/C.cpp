#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,a[200005],b[200005],N,vst[1000005],c1[200005];
void Solve(){
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++)scanf("%d",&a[i]);
	ll ans=0;
	for(int i=0;i<m;i++){
		N=0;
		for(int j=i;j<n;j+=m)b[++N]=a[j];
		for(int j=N;j>=1;j--){
			if(b[j]==1)c1[j]=c1[j+1]+1;
			else c1[j]=0;
		}
		for(int j=1;j<=N;j++){
			if(vst[b[j]])continue;
			if(b[j]==1){
				int k=j+c1[j]-1;
				if(k==N){
					j=k;
					continue;
				}
				if(vst[b[k+1]]){
					j=k;
					continue;
				}
				ans+=c1[j];
				if(k+1==N){
					j=k;
					continue;
				}
				if(b[k+2]!=1){
					j=k;
					continue;
				}
				ans+=1ll*c1[j]*c1[k+2];
				j=k;
				continue;
			}
			if(j==N)continue;
			if(b[j+1]!=1)continue;
			ans+=c1[j+1];
		}
		for(int j=N;j>=1;j--)c1[j]=b[j]=0;
	}
	cout<<ans<<'\n';
}
int main(){
//	freopen("1.in","r",stdin);
//	freopen("2.out","w",stdout);
	vst[0]=1;
	for(int i=2;i<=1000000;i++){
		for(int j=i+i;j<=1000000;j+=i)vst[j]=1;
	}
	int t;
	cin>>t;
	while(t--){
		Solve();
	}
}