#include<iostream>
#include<algorithm>
#include<queue>
#include<cmath>
using namespace std;
typedef long long ll;
int n,m,k;
bool hv[4];
int main(){
	ios::sync_with_stdio(false);
	cin >> n;
	int ans=1;
	for(int i=1; i<=10 ;i++){
		int num=((1<<i)-1)<<(i-1);
		if(num>n) break;
		if(n%num==0) ans=num;
	}
	cout << ans << endl;
}