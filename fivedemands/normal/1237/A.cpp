#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int ans[1000001];
int n;
int main(){
	ios::sync_with_stdio(false);
	cin >> n;
	int cur=false;
	for(int i=1; i<=n ;i++){
		int x;cin >> x;
		if(x%2==1 || x%2==-1){
			x--;
			cur^=1;
			cout << x/2+cur << '\n';
		}
		else cout << x/2 << '\n';
	}
}