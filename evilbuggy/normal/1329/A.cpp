#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout<<setprecision(32);

	int n, m;
	cin>>n>>m;
	vector<int> l(m);
	ll sum = 0;
	for(int i = 0; i < m; i++){
		cin>>l[i];
		if(i > n - l[i]){
			cout<<-1<<endl;
			exit(0);
		}
		sum += l[i];
	}
	if(sum < n){
		cout<<-1<<endl;
		exit(0);
	}
	vector<int> pos(m);
	pos[m - 1] = n - l[m - 1] + 1;
	for(int i = m - 2; i >= 0; i--){
		pos[i] = max(i + 1, pos[i + 1] - l[i]);
	}
	for(auto x : pos){
		cout<<x<<" ";
	}

	return 0;
}