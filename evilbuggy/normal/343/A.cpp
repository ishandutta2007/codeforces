#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	long long a, b;
	cin >> a >> b;
	long long answer = 0;
	while(a > 0 && b > 0){
		if(a > b){
			answer += (a/b);
			a %= b;
		}else{
			answer += (b/a);
			b %= a;
		}
	}
	cout << answer << '\n';


	return 0;
}