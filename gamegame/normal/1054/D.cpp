#include<iostream>
#include<map>
using namespace std;
typedef long long ll;
map<int,int>m;
#define fi first
#define se second
int n,k;
int main(){
	ios::sync_with_stdio(false);
	cin >> n >> k;
	int cur=0;
	m[0]++;
	for(int i=1; i<=n ;i++){
		int a;
		cin >> a;
		if(a&(1<<(k-1))) a^=((1<<k)-1);
		cur^=a;
		m[cur]++;
	}
	ll ans=0;
	for(auto cur:m){
		int num=cur.se/2;
		int num2=cur.se-num;
		ans+=1LL*num*(num-1)/2;
		ans+=1LL*num2*(num2-1)/2;
	}
	cout << 1LL*n*(n+1)/2-ans << endl;
}