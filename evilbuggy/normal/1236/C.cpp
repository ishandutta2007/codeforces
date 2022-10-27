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

	int n;
	cin>>n;
	vector<int> a[n];
	for(int i = 0; i < n; i++){
		if(i%2 == 0){
			for(int j = 0; j < n; j++){
				a[j].push_back(i*n + j + 1);
			}
		}else{
			for(int j = n-1; j >= 0; j--){
				a[n-j-1].push_back(i*n + j + 1);
			}
		}
	}
	for(int i = 0; i < n; i++){
		for(auto x : a[i]){
			cout<<x<<" ";
		}
		cout<<endl;
	}

	return 0;
}