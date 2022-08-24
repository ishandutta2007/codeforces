#include<iostream>
#include<iomanip>
using namespace std;
typedef double dd;
int n,q;
dd sum;
dd val[262144];
void upd(int pos,dd v){
	sum+=v-val[pos];
	val[pos]=v;
}
int main(){
	ios::sync_with_stdio(false);
	cin >> n >> q;
	n=(1<<n);
	for(int i=0; i<n ;i++){
		dd x;
		cin >> x;
		upd(i,x);
	}
	cout << fixed << setprecision(10) << sum/n << '\n';
	for(int i=1; i<=q ;i++){
		int p;
		dd x;
		cin >> p >> x;
		upd(p,x);
		cout << fixed << setprecision(10) << sum/n << '\n';
	}
}