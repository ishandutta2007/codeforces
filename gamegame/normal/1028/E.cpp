#include<iostream>
using namespace std;
typedef long long ll;
bool as=true;
int n;
ll b[600001],a[600001];
ll c[600001];
int main(){
	ios::sync_with_stdio(false);
	cin >> n;
	cin >> b[1];
	b[2*n+1]=b[n+1]=b[1];
	for(int i=2; i<=n ;i++){
		cin >> b[i];
		b[i+n]=b[i];
		if(b[i]!=b[1]) as=false;
	}
	if(as && b[1]==0){
		cout << "YES\n";
		for(int i=1; i<=n ;i++){
			cout << "1 ";
		}
		return 0;
	}
	if(as){
		cout << "NO\n";
		return 0;
	}
	cout << "YES\n";
	for(int i=n+1; i<=2*n ;i++){
		if(b[i]>b[i-1]){
			a[i]=b[i];
			a[i-1]=1000000LL*b[i]+b[i-1];
			for(int j=i-2; j>i-n ;j--){
				a[j]=a[j+1]+b[j];
			}
			break;
		}
	}
	for(int i=1; i<=n ;i++){
		cout << a[i]+a[i+n] << ' ';
	}
	cout << endl;
}