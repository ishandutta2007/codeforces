#include<bits/stdc++.h>
using namespace std;
#define maxn 240000
char s[maxn];
char t[6][4] = {
	"RGB",
	"RBG",
	"GRB",
	"GBR",
	"BRG",
	"BGR"
};
int main(){
	ios::sync_with_stdio(false);
	int n;
	cin >> n >> s;
	int ans = n + 1, mT = -1;
	for(int T = 0; T < 6; T += 1){
		int pans = 0;
		for(int i = 0; i < n; i += 1)
			if(s[i] != t[T][i % 3]) pans += 1;
		if(pans < ans){
			ans = pans;
			mT = T;
		}
	}
	cout << ans << endl;
	for(int i = 0; i < n; i += 1)	
		cout << (char)t[mT][i % 3];
}