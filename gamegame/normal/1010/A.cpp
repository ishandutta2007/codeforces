#include<iostream>
#include<iomanip>
using namespace std;
typedef long double ld;
int n;
ld m;
ld a[1001],b[1001];
bool check(ld mid){
	for(int i=1; i<=n ;i++){
		mid-=(m+mid)/a[i];
		if(mid<-1e-9) return false;
		mid-=(m+mid)/b[i];
		if(mid<-1e-9) return false;
	}
	return true;
}
int main(){
	ios::sync_with_stdio(false);
	cin >> n >> m;
	for(int i=1; i<=n ;i++){
		cin >> a[i];
	}
	for(int i=1; i<=n ;i++){
		cin >> b[i];
		if(i!=1) swap(b[i-1],b[i]);
	}
	ld l=0,r=3e9,mid;
	for(int i=1; i<=100 ;i++){
		mid=(l+r)/2;
		if(check(mid)) r=mid;
		else l=mid;
	}
	if(l>1e9){
		cout << "-1\n";
		return 0;
	}
	cout << fixed << setprecision(20) << l << endl;
}