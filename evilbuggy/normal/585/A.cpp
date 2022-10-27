#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	deque<array<int, 4> > child(n);
	for(int i = 0; i < n; i++){
		cin >> child[i][0];
		cin >> child[i][1];
		cin >> child[i][2];
		child[i][3] = i;
	}
	vector<int> ans;
	while(!child.empty()){
		array<int, 4> cur = child.front(); child.pop_front();
		deque<array<int, 4> > nchild;
		long long vol1 = cur[0], vol2 = 0;
		for(auto x : child){
			if(x[2] < vol1 + vol2){
				vol2 += x[1];
			}else{
				nchild.push_back({x[0], x[1], x[2] - vol1 - vol2, x[3]});
			}
			vol1 -= 1; if(vol1 < 0)vol1 = 0;
		}
		ans.push_back(cur[3]);
		child = nchild;
	}
	cout << (int)ans.size() << '\n';
	for(auto x : ans){
		cout << x + 1 << " ";
	}
	cout << '\n';

	return 0;
}