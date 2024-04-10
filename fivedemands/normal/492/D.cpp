#include<iostream>
#include<algorithm>
using namespace std;
vector<pair<long long,bool> >v;
int main(){
	ios::sync_with_stdio(false);
	int n;
	long long x,y;
	long long a;
	cin >> n >> x >> y;
	long long lcm=x*y/__gcd(x,y);
	long long times=lcm/x+lcm/y;
	for(long long int i=0; i<lcm ;i+=x){
		v.push_back(make_pair(i,0));
	}
	for(long long int i=y; i<lcm ;i+=y){
		v.push_back(make_pair(i,1));
	}
	sort(v.begin(),v.end());
	for(int i=1; i<=n ;i++){
		cin >> a;
		a=a%times;
		if(a==0 || a==times-1) cout << "Both\n";
		else if(v[a].second) cout << "Vanya\n";
		else cout << "Vova\n";
	}
}//