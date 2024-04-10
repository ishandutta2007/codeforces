#include<iostream>
using namespace std;
typedef long long ll;
ll gcd(ll x,ll y){
	if(y==0) return x;
	return gcd(y,x%y);
}
int main(){
	ios::sync_with_stdio(false);
	ll la,ra,ta,lb,rb,tb;
	cin >> la >> ra >> ta >> lb >> rb >> tb;
	ra-=la;
	rb-=lb;
	ll num=gcd(ta,tb);
	la%=num;
	lb%=num;
	ra+=la;
	rb+=lb;
	ll ans=max(min(ra,rb)-max(la,lb)+1,max(min(ra+num,rb)-max(la+num,lb)+1,min(ra,rb+num)-max(la,lb+num)+1));
	ans=max(ans,0LL);
	cout << ans << endl;
}