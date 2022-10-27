#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

int q[200005], r[200005];

int main(){
	int n;
	cin>>n;
	for(int i = 1; i < n; i++){
		cin>>q[i];
	}
	r[0] = 0;
	for(int i = 1; i < n; i++){
		r[i] = q[i] + r[i - 1];
	}
	set<int> arr;
	for(int i = 0; i < n; i++){
		arr.insert(r[i]);
	}
	if(arr.size() != n){
		cout<<-1<<endl;
	}else{
		int mx = *arr.rbegin();
		int mn = *arr.begin();
		if(mx - mn != n - 1){
			cout<<-1<<endl;
		}else{
			for(int i = 0; i < n; i++){
				cout<<r[i] - mn + 1<<" ";
			}
			cout<<endl;
		}
	}
}