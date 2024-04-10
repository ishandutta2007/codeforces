#include <bits/stdc++.h>
using namespace std;

const int maxN = 200005;

int pos[maxN];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int q;
	cin >> q;
	int cnt = 0, l = -1, r = -1;
	while(q--){
		int x;
		char ch;
		cin >> ch >> x;
		if(cnt == 0){
			l = r = pos[x] = 0;
			cnt++;
		}else if(ch == 'L'){
			l--; cnt++;
			pos[x] = l;
		}else if(ch == 'R'){
			r++; cnt++;
			pos[x] = r;
		}else{
			int p = pos[x] - l + 1;
			cout << min(p - 1, cnt - p) << '\n';
		}
	}


	return 0;
}