#include<iostream>
#include<queue>
#include<algorithm>
#include<cmath>
using namespace std;
int n,l,r;
int a[100001],p[100001];
pair<int,int>q[100001];
int ans[100001];
int main(){
	ios::sync_with_stdio(false);
	cin >> n >> l >> r;
	for(int i=1; i<=n ;i++){
		cin >> a[i];
	}
	for(int i=1; i<=n ;i++){
		cin >> p[i];
		q[i]=make_pair(p[i],a[i]);
	}
	sort(q+1,q+n+1);
	int prev=-2e9;
	for(int i=1; i<=n ;i++){
		ans[i]=max(l,prev+q[i].second+1);
		prev=ans[i]-q[i].second;
		if(ans[i]>r){
			cout << -1 << endl;
			return 0;
		}
	}
	for(int i=1; i<=n ;i++){
		cout << ans[p[i]] << ' ';
	}
	cout << endl;
}