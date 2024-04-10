#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
const int N=2e6+1;
ll n,m,k;
int f[201];
vector<int>g[101];
vector<int>v;
ll z1=0,z2=0;
int ans[201];
int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	cin >> n;
	for(int i=1; i<=2*n ;i++){
		int x;cin >> x;f[x]++;
		g[x].push_back(i);
	}
	int one=0,two=0,zero=0;
	for(int i=10; i<=99 ;i++){
		if(f[i]==0) continue;
		if(f[i]%2==0){
			for(int j=0; j<f[i] ;j++) ans[g[i][j]]=1;
			for(int j=0; j<f[i]/2 ;j++) ans[g[i][j]]=2;
			zero++;
			continue;	
		}
		if(f[i]==1){
			one++;
			if(one%2==1){
				for(int j=0; j<f[i] ;j++) ans[g[i][j]]=1;
				for(int j=0; j<f[i]/2 ;j++) ans[g[i][j]]=2;
			}
			else{
				for(int j=0; j<f[i] ;j++) ans[g[i][j]]=2;
				for(int j=0; j<f[i]/2 ;j++) ans[g[i][j]]=1;
			}
		}
		else{
			two++;
			if(two%2==0){
				for(int j=0; j<f[i] ;j++) ans[g[i][j]]=1;
				for(int j=0; j<f[i]/2 ;j++) ans[g[i][j]]=2;
			}
			else{
				for(int j=0; j<f[i] ;j++) ans[g[i][j]]=2;
				for(int j=0; j<f[i]/2 ;j++) ans[g[i][j]]=1;
			}
		}
	}
	zero+=two;
	cout << (zero+one/2)*(zero+(one+1)/2) << '\n';
	for(int i=1; i<=2*n ;i++) cout << ans[i] << ' ';
	cout << '\n';
}