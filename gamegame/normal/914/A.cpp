#include<iostream>
#include<cmath>
using namespace std;
int n,m,k;
int a[200001],b[200001];
int main(){
	ios::sync_with_stdio(false);
	cin >> n;
	int ans=-1e6-1;
	for(int i=1; i<=n ;i++){
		cin >> a[i];
		if(a[i]>=0){
			int b=sqrt(a[i]);
			if(b*b==a[i]) continue; 
		}
		ans=max(ans,a[i]);
	}
	cout << ans << endl;
}