#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

const int N = 300005;
vector<int> pfac[N];
bool prime[N];
int f[N], fmul[N], len[N];

void pre(){
	memset(f, 0, sizeof(f));
	for(int i = 2; i < N; i++){
		prime[i] = true;
	}
	for(int i = 2; i < N; i++){
		if(prime[i]){
			pfac[i].push_back(i);
			for(int j = 2*i; j < N; j += i){
				prime[j] = false;
				pfac[j].push_back(i);
			}
		}
	}
}

inline bool compute(int k, int g){
	int sz = pfac[k].size();
	int ret = 0;
	for(int mask = 0; mask < (1<<sz); mask++){
		int cnt = 0;
		int prd = g;
		for(int i = 0; i < sz; i++){
			if(mask&(1<<i)){
				cnt++;
				prd *= pfac[k][i];
			}
		}
		if(cnt&1)ret -= fmul[prd];
		else ret += fmul[prd];
	}
	return ret > 0;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout<<setprecision(32);

	pre();
	int x, n;
	cin>>n;
	for(int i = 1; i <= n; i++){
		cin>>x;
		f[x]++;
	}
	for(int i = 1; i < N; i++){
		fmul[i] = 0;
		for(int j = i; j < N; j += i){
			fmul[i] += f[j];
		}
	}
	for(int g = N - 1; g > 0; g--){
		if(f[g]){
			len[g] = 1;
			continue;
		}
		len[g] = N;
		for(int h = 2*g; h < N; h += g){
			if(compute(h/g, g) && len[g] > 1 + len[h]){
				len[g] = 1 + len[h];
			}
		}
	}
	if(len[1] <= n)cout<<len[1]<<endl;
	else cout<<-1<<endl;

	return 0;
}