#include<iostream>
#include<algorithm>
#include<queue>
#include<cmath>
using namespace std;
int n,q,p,k;
int a[100001];
int ans[340][100001];
int mid=320;
int main(){
	ios::sync_with_stdio(false);
	cin >> n;
	for(int i=1; i<=n ;i++) cin >> a[i];
	mid=sqrt(n);
	for(int i=1; i<=mid ;i++){
		for(int j=n; j>=1 ;j--){
			if(j+a[j]+i>n) ans[i][j]=1;
			else ans[i][j]=ans[i][j+a[j]+i]+1;
		}
	}
	cin >> q;
	for(int i=1; i<=q ;i++){
		cin >> p >> k;
		if(k<=mid){
			cout << ans[k][p] << endl;
			continue;
		}
		int ret=0;
		while(p<=n){
			ret++;
			p=p+a[p]+k;
		}
		cout << ret << endl;
	}
}