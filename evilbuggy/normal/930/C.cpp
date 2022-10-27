#include <bits/stdc++.h>
using namespace std;

const int N = 100005;
int f[N], fw[N], bk[N];

void longestIncreasingSubsequence(int n, int f[], int a[]){
	vector<int> vec;
	for(int i = 1; i <= n; i++){
		if(vec.empty() || f[i] >= vec.back()){
			vec.push_back(f[i]);
			a[i] = (int)vec.size();
		}else{
			int lo = 0, hi = (int)vec.size() - 1;
			while(lo < hi){
				int mi = (lo + hi)/2;
				if(f[i] < vec[mi])hi = mi;
				else lo = mi + 1;
			}
			a[i] = lo + 1;
			vec[lo] = f[i];
		}
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;
	memset(f, 0, sizeof(f));
	for(int i = 1; i <= n; i++){
		int l, r;
		cin >> l >> r;
		f[l]++; f[r + 1]--;
	}
	for(int i = 1; i <= m; i++){
		f[i] += f[i - 1];
	}
	longestIncreasingSubsequence(m, f, fw);
	reverse(f + 1, f + m + 1);
	longestIncreasingSubsequence(m, f, bk);
	reverse(bk + 1, bk + m + 1);
	int answer = 1;
	for(int i = 1; i <= m; i++){
		answer = max(answer, fw[i] + bk[i] - 1);
	}
	cout << answer << '\n';

	return 0;
}