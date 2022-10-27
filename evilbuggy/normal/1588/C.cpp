#include <bits/stdc++.h>
using namespace std;

const int maxN = 300005;

long long A[maxN], S[maxN];

long long count(int l, int r){
	if(l == r)return (A[l] == 0);

	int m = (l + r)/2;
	long long ret = count(l, m) + count(m + 1, r);
	
	map<long long, int> cnt;
	{
		vector<long long> minima(2, LLONG_MAX);
		for(int i = m; i >= l; i--){
			int par = i&1;
			int nar = par^1;
			minima[par] = min(minima[par], S[i]);
			if(-minima[par] <= S[i - 1] && S[i - 1] <= +minima[nar]){
				if((m - i + 1)&1){
					cnt[S[m] + S[i - 1]]++;
				}else{
					cnt[S[m] - S[i - 1]]++;
				}
			}
		}
	}
	{
		vector<long long> minima(2, LLONG_MAX);
		minima[m&1] = min(minima[m&1], S[m]);
		for(int i = m + 1; i <= r; i++){
			int par = i&1;
			int nar = par^1;
			if(-minima[nar] <= S[i] && S[i] <= +minima[par]){
				if((i - m)&1){
					ret += cnt[S[i] + S[m]];
				}else{
					ret += cnt[S[m] - S[i]];
				}
			}
			minima[par] = min(minima[par], S[i]);
		}
	}
	return ret;
}

void solve(){
	int N;
	cin >> N;
	S[0] = 0;
	for(int i = 1; i <= N; i++){
		cin >> A[i];
		S[i] = A[i] - S[i - 1];
	}
	cout << count(1, N) << '\n';
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;
	while(T--)solve();

	return 0;
}