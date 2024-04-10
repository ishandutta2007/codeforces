#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll sum=0;
int n;
ll m;
ll fr[101];
int g[101];
int pans=0;
int main(){
	ios::sync_with_stdio(false);
	int ans=0;cin >> n >> m;
	for(int i=1; i<=n ;i++){
		ll t;cin >> t;
		ans=0;
		for(int j=100; j>=1 ;j--){
			while(sum>m && fr[j]){
				sum-=j;
				pans++;
				fr[j]--;
			}
			while(sum+t>m && fr[j]){
				sum-=j;ans++;g[j]++;
				fr[j]--;
			}
		}
		cout << pans+ans << ' ';
		sum+=t;
		fr[t]++;
		for(int j=1; j<=100 ;j++){
			fr[j]+=g[j];
			sum+=g[j]*j;g[j]=0;
		}
	}
}