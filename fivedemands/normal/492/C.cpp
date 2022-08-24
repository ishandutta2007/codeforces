#include<iostream>
#include<algorithm>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	long long int r,avg,t;
	int n;
	cin >> n >> r >> avg;
	t=n*avg;
	long long ans=0;
	pair<long long int,long long int>a[n+1];
	for(int i=1; i<=n ;i++){
		cin >> a[i].second >> a[i].first;
		t-=a[i].second;
		a[i].second=r-a[i].second;
	}
	if(t<=0){
		cout << 0 << endl;
		return 0;
	}
	sort(a+1,a+n+1);
	for(int i=1; i<=n ;i++){
		if(t>a[i].second){
			ans+=a[i].first*a[i].second;
			t-=a[i].second;
		}
		else{
			ans+=a[i].first*t;
			cout << ans << endl;
			return 0;
		}
	}
}