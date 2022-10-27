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

	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		vector<int> a(n);
		for(int i = 0; i < n; i++){
			cin>>a[i];
		}
		int ind = -1;
		for(int i = 1; i < n; i++){
			if(abs(a[i] - a[i-1]) >= 2)ind = i;
		}
		if(ind == -1){
			cout<<"NO"<<endl;
		}else{
			cout<<"YES"<<endl;
			cout<<ind<<" "<<ind+1<<endl;
		}
	}

	return 0;
}