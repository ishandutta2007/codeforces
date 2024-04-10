#include<iostream>
using namespace std;
typedef long long ll;
int n;
ll a[300001];
int bc[300001];
int p[300001];
int c[2];
ll ans=0;
int main(){
	ios::sync_with_stdio(false);
	cin >> n;
	c[0]++;
	for(int i=1; i<=n ;i++){
		cin >> a[i];
		for(int j=0; j<63 ;j++){
			if(a[i]&(1LL<<j)) bc[i]++;
		}
		p[i]=p[i-1]+bc[i];
		ans+=c[p[i]%2];
		c[p[i]%2]++;
	}
	for(int i=1; i<=n ;i++){
		int sum=0;
		int maxi=0;
		for(int j=i; j>=max(1,i-64) ;j--){
			maxi=max(maxi,bc[j]);
			sum+=bc[j];
			if(sum-maxi<maxi && sum%2==0) ans--;
		}
	}
	cout << ans << endl;
}