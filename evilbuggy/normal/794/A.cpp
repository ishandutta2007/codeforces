#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int a, b, c, n, answer = 0;
	cin >> a >> b >> c >> n;
	for(int i = 0; i < n; i++){
		int x;
		cin >> x;
		if(b < x && x < c)answer++;
	}
	cout << answer << '\n';


	return 0;
}