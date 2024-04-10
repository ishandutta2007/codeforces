#include<iostream>
#include<unordered_map>
using namespace std;
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	long long n;
	cin >> n;
	long long a[n+1];
	unordered_map<long long,long long>m;
	double z=m.max_load_factor();
	m.max_load_factor(z/6);
	long long sum=0;
	long long ans=n;
	for(long long i=1; i<=n ;i++){
		cin >> a[i];
		sum+=a[i];
		ans=min(ans,n-1-m[sum]++);
	}
	cout << ans << endl;
}