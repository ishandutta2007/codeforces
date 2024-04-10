#include<iostream>
#include<queue>
#include<cmath>
#include<algorithm>
using namespace std;
typedef long long ll;
int n,m,k;
int a[200001];
queue<int>q;
int main(){
	ios::sync_with_stdio(false);
	cin >> n >> m >> k;
	for(int i=1; i<=n ;i++){
		cin >> a[i];
	}
	sort(a+1,a+n+1);
	int ans=0;
	for(int i=1; i<=n ;i++){
		while(!q.empty() && a[i]-q.front()>=m) q.pop();
		if(q.size()==k-1) ans++;
		else q.push(a[i]);
	}
	cout << ans << endl;
}