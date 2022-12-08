#include <iostream>
#include <vector>
using namespace std;

long long cal(long long n) {
	if(n<10) return n;
	vector<int> sn;
	while(n) sn.push_back(n%10), n/=10;
	long long ans=9;
	for(int i=2; i<sn.size(); ++i) {
		long long tmp=9;
		for(int j=2; j<=i-1; ++j) tmp*=10;
		ans+=tmp;
	}
	//cout<<"cal n: ans1="<<ans<<endl;
	long long tmp=1; for(int j=1; j<=(int)sn.size()-2; ++j) tmp*=10;
	ans+=(sn.back()-1)*tmp;
	//cout<<"cal n: ans2="<<ans<<endl;
	tmp=0;
	for(int j=(int)sn.size()-2; j>=1; --j) tmp=tmp*10+sn[j];
	++tmp;
	if(sn.back()>sn[0]) --tmp;
	ans+=tmp;
	return ans;
}

int main() {
	long long l, r; cin>>l>>r;
	cout<<(cal(r)-cal(l-1))<<endl;
	return 0;
}