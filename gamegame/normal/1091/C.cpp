#include<iostream>
#include<set>
using namespace std;
typedef long long ll;
int n;
set<ll>s;
void test(int num){
	ll cnt=n/num;
	ll st=1,en=(cnt-1)*num+1;
	s.insert((en+st)*cnt/2);
}
int main(){
	ios::sync_with_stdio(false);
	cin >> n;
	for(int i=1; i<=40000 ;i++){
		if(n%i!=0) continue;
		test(i);
		test(n/i);
	}
	for(auto num:s) cout << num << ' ';
}