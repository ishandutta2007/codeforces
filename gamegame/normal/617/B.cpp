#include<iostream>
#include<vector>
using namespace std;
int main(){
	int n;
	cin >> n;
	vector<int>v;
	int t;
	for(int i=1; i<=n ;i++){
		cin >> t;
		if(t==1){
			v.push_back(i);
		}
	}
	if(v.size()==1){
		cout << 1 << endl;
		return 0;
	}
	else if(v.size()==0){
		cout << 0 << endl;
		return 0;
	}
	long long int ans=1;
	for(int i=1; i<v.size() ;i++){
		ans=ans*(v[i]-v[i-1]);
	}
	cout << ans << endl;
}