#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
constexpr int maxn = 120;
void no(){ cout << "NO"; exit(0); }
bitset<maxn> bs[maxn];
int main(){
	ios::sync_with_stdio(false);	
	int n;
	cin >> n;
	for(int i = 1; i <= n; i += 1){
		int r;
		cin >> r;
		while(r --){
			int x;
			cin >> x;
			bs[i].set(x);
		}
	}
	for(int i = 1; i <= n; i += 1){
		if(i == 1) bs[0] = bs[1];
		else bs[0] &= bs[i];
	}
	for(int i = 1; i <= 100; i += 1)
		if(bs[0].test(i))
			cout << i << " ";
}