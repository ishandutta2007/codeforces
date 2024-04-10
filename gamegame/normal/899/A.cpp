#include<iostream>
#include<queue>
#include<cmath>
#include<algorithm>
using namespace std;
int n,m,k;
int a[200001],b[200001];
int main(){
	ios::sync_with_stdio(false);
	cin >> n;
	int cnt1=0,cnt2=0;
	for(int i=1; i<=n ;i++){
		cin >> a[i];
		if(a[i]==1) cnt1++;
		else cnt2++;
	}
	int ans;
	if(cnt2>cnt1) ans=cnt1;
	else{
		ans=cnt2+(cnt1-cnt2)/3;
	} 
	cout << ans << endl;
}