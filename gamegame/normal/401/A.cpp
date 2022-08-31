#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,c;
multiset<int>s;
int a[100001];
ll dp[100001];
ll pf[100001];
int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	int n,x;
	cin >> n >> x;
	int sum=0;
	for(int i=1; i<=n ;i++){
		int y;
		cin >> y;
		sum+=y;
		
	}
	sum=abs(sum);
	cout << (sum+x-1)/x << endl;
}