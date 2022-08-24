#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int p[100001];
int a[100001];
int n;
int main(){
	ios::sync_with_stdio(false);
	cin >> n;
	for(int i=1; i<=n ;i++){
		int x;cin >> x;p[x]=i;
	}
	vector<int>v;
	for(int j=1; j<=n ;j++){
		int y;cin >> y;
		while(!v.empty() && p[y]<v.back()){
			v.pop_back();
		}
		v.push_back(p[y]);
	}
	cout << n-v.size() << '\n';
}