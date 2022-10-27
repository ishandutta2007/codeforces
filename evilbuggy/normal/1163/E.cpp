#include <bits/stdc++.h>
using namespace std;

const int K = 20;

vector<int> gen(int b){
	if(b == 0)return vector<int>({0});
	vector<int> ret = gen(b - 1);
	int n = (int)ret.size();
	for(int i = n - 1; i >= 0; i--){
		ret.emplace_back(ret[i]^(1 << (b - 1)));
	}
	return ret;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	vector<vector<int> > s(K);
	for(int i = 0; i < n; i++){
		int x;
		cin >> x;
		for(int j = K - 1; j >= 0; j--){
			if((x >> j) & 1){
				s[j].emplace_back(x);
				break;
			}
		}
	}
	for(int b = K; b >= 1; b--){
		int basissize = 0;
		vector<int> basis(b);
		vector<int> basisred(b);
		for(int i = 0; i < b; i++){
			for(auto x : s[i]){
				int y = x;
				for(int j = 0; j < b; j++){
					if((y >> j) & 1){
						if(basisred[j]){
							y ^= basisred[j];
						}else{
							basisred[j] = y;
							basis[j] = x;
							basissize++;
							break;
						}
					}
				}
			}
		}
		if(basissize < b)continue;
		cout << b << '\n';
		vector<int> seq = gen(b);
		for(int i = 0; i < (int)seq.size(); i++){
			int val = 0;
			for(int j = 0; j < b; j++){
				if((seq[i] >> j) & 1){
					val ^= basis[j];
				}
			}
			cout << val << ' ';
		}
		cout << '\n';
		exit(0);
	}
	cout << 0 << '\n' << 0 << '\n';

	return 0;
}