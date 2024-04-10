#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

int n;
ll d[200005];

ll findStart(){
	ll sum = 0, mini = 0;
	for(int i = 1; i <= n; i++){
		sum += d[i];
		mini = min(mini, sum);
	}
	return 1 - mini;
}

int findBreak(ll x){
	if(x <= 0)return 0;
	for(int i = 1; i <= n; i++){
		x += d[i];
		if(x <= 0)return i;
	}
	return -1;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	ll h, sum = 0;
	cin>>h>>n;
	for(int i = 1; i <= n; i++){
		cin>>d[i];
		sum += d[i];
	}
	ll mini = findStart();
	if(sum >= 0 || h < mini){
		cout<<findBreak(h)<<endl;
		exit(0);
	}
	sum = -sum;
	ll t = (h - mini)/sum;
	ll ans = t*n;
	h -= t*sum;
	while(findBreak(h) == -1){
		ans += n;
		h -= sum;
	}
	cout<<ans + findBreak(h)<<endl;
}