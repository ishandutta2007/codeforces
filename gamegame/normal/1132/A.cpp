#include<iostream>
using namespace std;
typedef long long ll;
ll a[4];
int main(){
	ios::sync_with_stdio(false);
	ll w,x,y,z;
	cin >> w >> x >> y >> z;
	ll cur=0;
	cur+=2*w;
	if(y>0 && cur==0) return cout << 0 << endl,0;
	cur-=2*z;
	if(cur!=0) cout << 0 << endl;
	else cout << 1 << endl;
}