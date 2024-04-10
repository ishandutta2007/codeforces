#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

inline bool check(int x1, int y1, int x2, int y2){
	cout<<"? "<<x1<<" "<<y1<<" "<<x2<<" "<<y2<<endl;
	string s;
	cin>>s;
	return s[0] == 'Y';
}


int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout<<setprecision(32);

	int n;
	cin>>n;
	string a = "";
	string b = "";
	int x = 1, y = 1;
	for(int i = 1; i < n; i++){
		if(x + 1 <= n && check(x + 1, y, n, n)){
			a += 'D';
			x += 1;
		}else{
			a += 'R';
			y += 1;
		}
	}
	x = y = n;
	for(int i = 1; i < n; i++){
		if(y - 1 > 0 && check(1, 1, x, y - 1)){
			b += 'R';
			y -= 1;
		}else{
			b += 'D';
			x -= 1;
		}
	}
	reverse(b.begin(), b.end());
	cout<<"! "<<a<<b<<endl;

	return 0;
}