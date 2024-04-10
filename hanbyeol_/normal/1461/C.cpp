#include<bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int T; cin >> T;
	while(T--)
	{
		int N, M; cin >> N >> M; vector<int> V(N); for(int &i: V) cin >> i;
		int lst = 0;
		for(int i=0; i<N; ++i) if(V[i] != i+1) lst = i+1;

		double p = lst == 0 ? 0: 1;
		for(int i=0; i<M; ++i)
		{
			int r; double pi; cin >> r >> pi;
			if(r >= lst) p *= 1-pi;
		}
		cout << fixed << setprecision(12) << 1-p << endl;
	}
	return 0;

}