#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
int n;
int a[200001];
vector<int>qr[200001];
int bit[200001];
void update(int id,int v){
	for(int i=id; i<=n ;i+=i&-i) bit[i]+=v;
}
int query(int id){
	int ans=0;
	for(int i=id; i>=1 ;i-=i&-i) ans+=bit[i];
	return ans;
}
int main(){
	ios::sync_with_stdio(false);
	cin >> n;
	for(int i=1; i<=n ;i++){
		cin >> a[i];
		a[i]=min(a[i],n);
		if(a[i]<i) qr[a[i]+1].push_back(i);
		else qr[i].push_back(i);
	}
	ll ans=0;
	for(int i=1; i<=n ;i++){
		for(int j=0; j<qr[i].size() ;j++){
			int cur=qr[i][j];
			ans+=query(cur);
		}
		update(1,1);
		update(a[i]+1,-1);
	}
	cout << ans << endl;
}