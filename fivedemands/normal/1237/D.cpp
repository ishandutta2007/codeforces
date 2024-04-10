#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
int n,m;
int a[300001];
int rt[300001];
int mx[20][300001];
multiset<int>s;
int ans[100001];
int main(){
	ios::sync_with_stdio(false);
	cin >> n;
	for(int i=1; i<=n ;i++){
		cin >> a[i];
		a[i+n]=a[i+n+n]=a[i];
	}
	a[3*n]=-1e9;
	int m=3*n;
	for(int i=1; i<=m ;i++) mx[0][i]=a[i];
	for(int j=1; (1<<j)<=m ;j++){
		for(int i=1; i+(1<<j)<=m+1 ;i++){
			mx[j][i]=min(mx[j-1][i],mx[j-1][i+(1<<(j-1))]);
		}
	}
	for(int i=1; i<=m ;i++){
		int id=i;
		for(int j=19; j>=0 ;j--){
			if(id+(1<<j)>m) continue;
			if(mx[j][id]*2>=a[i]) id+=(1<<j);
		}
		rt[i]=id;
	}
	int l=1;
	for(int i=1; i<=m && l<=n;i++){
		s.insert(rt[i]);
		while(l<=n && i>=*s.begin()){
			s.erase(s.find(rt[l]));
			ans[l]=i-1;
			l++;
		}
	}
	for(int i=1; i<=n ;i++){
		if(ans[i]==3*n-1) cout << -1 << ' '; 
		else cout << ans[i]-i+1 << ' ';
	}
	cout << '\n';
}