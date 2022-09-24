#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,mx[105][105],f[105][105],a[105];
void Solve(){
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		map<int,int> mp;
		int cur=0;
		for(int j=i;j<=n;j++){
			mp[a[j]]=1;
			while(mp[cur])cur++;
			mx[i][j]=cur+1;
		}
	}
	int s=0;
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			f[i][j]=0;
			for(int k=i;k<=j;k++){
				f[i][j]=max(f[i][j],f[i][k-1]+mx[k][j]);
			}
			s+=f[i][j];
		}
	}
	cout<<s<<'\n';
}
int main(){
	int t;
	cin>>t;
	while(t--){
		Solve();
	}
}