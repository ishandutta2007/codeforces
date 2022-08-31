#include<iostream>
#include<algorithm>
using namespace std;
int a[100000];
int b[100001];
int n,m,k;
int main(){
	ios::sync_with_stdio(false);
	cin >> n >> m >> k;
	for(int i=1; i<=n ;i++){
		cin >> b[i];
		if(i!=1) a[i-1]=b[i]-b[i-1];
	}
	sort(a+1,a+n);
	int ans=k;
	for(int i=1; i<=n-k ;i++) ans+=a[i];
	cout << ans << endl;
}