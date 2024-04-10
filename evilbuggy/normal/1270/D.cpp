#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

const int N = 505;
int arr[N];

void getElem(int k, int n){
	cout<<"?";
	for(int i = 1; i <= n; i++){
		if(k == 0)break;
		if(arr[i] == -1){
			cout<<" "<<i; k--;
		}
	}
	cout<<endl;
	int ind, val;
	cin>>ind>>val;
	arr[ind] = val;
}

int print(vector<int> &arr){
	cout<<"?";
	for(auto x : arr){
		cout<<" "<<x;
	}
	cout<<endl;
	int ind, val;
	cin>>ind>>val;
	return ind;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout<<setprecision(32);

	int n, k;
	cin>>n>>k;
	memset(arr, -1, sizeof(arr));
	for(int i = 1; i <= n-k+1; i++){
		getElem(k, n);
	}
	vector<int> unknown, known;
	for(int i = 1; i <= n; i++){
		if(arr[i] == -1)unknown.push_back(i);
		else known.push_back(i);
	}
	int a = known[0];
	int b = known[1];
	if(arr[a] > arr[b])swap(a, b);
	int ans = 1;
	for(int i = 0; i < unknown.size(); i++){
		vector<int> tmp;
		tmp.push_back(a);
		tmp.push_back(b);
		for(int j = 0; j < unknown.size(); j++){
			if(i == j)continue;
			tmp.push_back(unknown[j]);
		}
		if(print(tmp) == b)ans++;
	}
	cout<<"! "<<ans<<endl;

	return 0;
}