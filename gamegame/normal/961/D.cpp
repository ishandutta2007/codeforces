#include<iostream>
using namespace std;
typedef long long ll;
int n;
ll x[100001],y[100001];
bool z[100001];
bool collinear(int p,int q,int r){
	return (y[q]-y[p])*(x[r]-x[p])==(y[r]-y[p])*(x[q]-x[p]);
}
bool solve(int u,int v){
	for(int i=1; i<=n ;i++){
		if(collinear(u,v,i)) z[i]=true;
		else z[i]=false;
	}
	int f1=-1,f2=-1;
	for(int i=1; i<=n ;i++){
		if(z[i]) continue;
		if(f1==-1){
			f1=i;
			continue;
		}
		if(f2==-1){
			f2=i;
			continue;
		}
		if(!collinear(f1,f2,i)) return false;
	}
	return true;
}
int main(){
	ios::sync_with_stdio(false);
	cin >> n;
	if(n<=2){
		cout << "YES\n";
		return 0;
	}
	for(int i=1; i<=n ;i++){
		cin >> x[i] >> y[i];
	}
	if(solve(1,2) || solve(1,3) || solve(2,3)) cout << "YES\n";
	else cout << "NO\n";
}