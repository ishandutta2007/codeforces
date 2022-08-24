#include<iostream>
#include<queue>
#include<algorithm>
#include<cmath>
using namespace std;
int n,m;
int l[200001],r[200001];
int min1,min2;
int main(){
	ios::sync_with_stdio(false);
	r[0]=1e9+1;
	cin >> n;
	for(int i=1; i<=n ;i++){
		cin >> l[i] >> r[i];
		if(r[min1]>r[i]){
			min1=i;
		}
		if(l[min2]<l[i]){
			min2=i;
		}
	}
	int ans=0;
	int ll,rr;
	cin >> m;
	for(int i=1; i<=m ;i++){
		cin >> ll >> rr;
		ans=max(ans,max(0,l[min2]-rr));
		ans=max(ans,max(0,ll-r[min1]));
	}
	cout << ans << endl;
}