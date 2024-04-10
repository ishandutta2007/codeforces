#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout<<setprecision(32);

	string s;
	cin>>s;
	int cnt = 0;
	for(auto ch : s){
		cnt += (ch == 'a');
	}
	int n = s.size();
	while(cnt <= (n/2)){
		n--;
	}
	cout<<n<<endl;

	return 0;
}