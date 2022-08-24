#include<iostream>
#include<cmath>
#include<set>
#include<queue>
#include<algorithm>
using namespace std;
typedef long long ll;
int n,k;
ll cal(int x){
	if(x==0) return 1;
	if(x==1) return 0;
	if(x==2){
		return 1LL*n*(n-1)/2;
	}
	if(x==3) return 1LL*n*(n-1)*(n-2)/3;
	if(x==4) return 1LL*n*(n-1)*(n-2)*(n-3)/8*3;
}
int main(){
	ios::sync_with_stdio(false);
	cin >> n >> k;
	ll ans=0;
	for(int i=0; i<=k ;i++){
		ans+=cal(i);
	}
	cout << ans << endl;
}