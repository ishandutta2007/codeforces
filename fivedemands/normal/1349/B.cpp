#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
const int N=2e5+1;
int n,k;
int a[100001];
void solve(){
	cin >> n >> k;
	int c0=0,c1=0,c2=0;
	for(int i=1; i<=n ;i++){
		cin >> a[i];
		if(a[i]==k) a[i]=1;
		else if(a[i]<k) a[i]=0;
		else a[i]=2;
		if(a[i]==0) c0++;
		if(a[i]==1) c1++;
		if(a[i]==2) c2++;
	}
	if(c1==0){
		cout << "no\n";return;
	}
	if(n==1){
		cout << "yes\n";return;
	}
	if(c0==0){
		cout << "yes\n";return;
	}
	for(int i=1; i<n ;i++){
		if(i!=1 && a[i]==0 && a[i-1]!=0 && a[i+1]!=0){
			
			cout << "yes\n";return;
		}
		if(a[i]!=0 && a[i+1]!=0){
			cout << "yes\n";return;
		}
	}
	cout << "no\n";
}
int main(){
	ios::sync_with_stdio(false);
	int t;cin >> t;while(t--) solve();
}