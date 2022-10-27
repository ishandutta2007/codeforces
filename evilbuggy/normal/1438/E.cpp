#include <bits/stdc++.h>
using namespace std;

const int K = 30;

inline int compute(vector<long long> &a){
	int n = (int)a.size();
	vector<long long> sum = a;
	for(int i = 1; i < n; i++){
		sum[i] += sum[i - 1];
	}
	vector<int> ind0(K, -1);
	vector<int> ind1(K, -1);
	int ret = 0;

	auto check = [&](int l, int r)->bool{
		if(l == -1)return false;
		return l != -1 && r - l >= 2 && a[l] > a[r] && (a[l]^a[r]) == sum[r - 1] - sum[l];
	};

	for(int i = 0; i < n; i++){
		int b = -1;
		for(int j = K - 1; j >= 0; j--){
			if((a[i] >> j) & 1){
				b = j;
				break;
			}
		}
		assert(b != -1);
		for(int j = b; j < K; j++){
			if(check(ind0[j], i))ret++;
			if(check(ind1[j], i))ret++;
		}
		ind1[b] = ind0[b]; ind0[b] = i;
	}
	return ret;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	vector<long long> a(n);
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	int answer = compute(a);
	reverse(a.begin(), a.end());
	answer += compute(a);
	cout << answer << '\n';

	return 0;
}