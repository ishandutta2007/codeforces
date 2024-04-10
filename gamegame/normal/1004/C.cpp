#include<iostream>
#include<cstdlib>
#include<unordered_map>
using namespace std;
typedef long long ll;
int n;
int bit[100001];
int a[100001];
bool hv[100001];
int f[100001];
int cnt=0;
ll ans=0;
int main(){
	ios::sync_with_stdio(false);
	cin >> n;
	for(int i=1; i<=n ;i++){
		cin >> a[i];
		if(f[a[i]]==0) f[a[i]]=i;
	}
	for(int i=n; i>=1 ;i--){
		if(f[a[i]]==i) ans+=cnt;
		if(!hv[a[i]]){
			hv[a[i]]=true;
			cnt++;
		}
	}
	cout << ans << endl;
}