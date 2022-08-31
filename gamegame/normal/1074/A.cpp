#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
int n,m;
int x[100002];
int cnt[100003];
int main(){
	ios::sync_with_stdio(false);
	cin >> n >> m;
	for(int i=1; i<=n ;i++) cin >> x[i];
	sort(x+1,x+n+1);
	x[n+1]=1e9;
	for(int i=1; i<=m ;i++){
		int l,r,y;
		cin >> l >> r >> y;
		if(l!=1) continue;
		int p1=lower_bound(x,x+n+2,l-1)-x;
		int p2=upper_bound(x,x+n+2,r)-x;
		cnt[p1]++;
		cnt[p2]--;
	}
	int ans=1e9;
	int cur=0;
	for(int i=0; i<=n+1 ;i++){
		cur+=cnt[i];
		if(i!=0) ans=min(ans,cur+i-1);
	}
	cout << ans << endl;
}