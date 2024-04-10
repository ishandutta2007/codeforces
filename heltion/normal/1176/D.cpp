//Author: Heltion
//Date: 2019-06-09
#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 3000000;
multiset<int, greater<int>> ms;
multiset<int> msp;
bool vp[maxn];
int p[maxn], pn, lpf[maxn];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cout<<fixed<<setprecision(12);
	for(int i = 2; i < maxn; i += 1)
		if(not vp[i]){
			p[pn += 1] = i;
			for(int j = i + i; j < maxn; j += i){
				vp[j] = true;
				if(not lpf[j]) lpf[j] = i;
			}
		}
	int n;
	cin >> n;
	for(int i = 0, x; i < 2 * n; i += 1){
		cin >> x;
		ms.insert(x);
	}
	while(not ms.empty()){
		int u = *ms.begin();
		ms.erase(ms.begin());
		if(not vp[u]){
			msp.insert(u);
			continue;
		}
		else{
			cout << u << " ";
			ms.erase(ms.find(u / lpf[u]));
		}
	}
	while(not msp.empty()){
		int u = *msp.begin();
		msp.erase(msp.begin());
		cout << u << " ";
		msp.erase(msp.find(p[u]));
	}
	return 0;
}