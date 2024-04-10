#include<iostream>
using namespace std;
int n;
int l[1001],r[1001];
int a[1001];
int main(){
	ios::sync_with_stdio(false);
	cin >> n;
	for(int i=1; i<=n ;i++) cin >> l[i];
	for(int i=1; i<=n ;i++){
		cin >> r[i];
		a[i]=n-l[i]-r[i];
	}
	for(int i=1; i<=n ;i++){
		int cl=0,cr=0;
		for(int j=1; j<i ;j++) if(a[j]>a[i]) cl++;
		for(int j=i+1; j<=n ;j++) if(a[j]>a[i]) cr++;
		if(cl!=l[i] || cr!=r[i]){
			cout << "NO\n";
			return 0;
		}
	}
	cout << "YES\n";
	for(int i=1; i<=n ;i++) cout << a[i] << ' ';
	cout << endl;
}