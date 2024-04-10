#include<bits/stdc++.h>
using namespace std;
using LL = long long;
void no(const char *s = "NO"){cout << s;exit(0);} 
constexpr int maxn = 120;
int aa[] = {1, 0, 0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 0, 1};
int bb[] = {0, 1, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 1, 0};
int cc[] = {0, 0, 1, 0, 1, 0, 0, 0, 0, 1, 0, 1, 0, 0};
int main(){
	ios::sync_with_stdio(false); 
	int a, b, c, ans = 0;
	cin >> a >> b >> c;
	ans = min(min(a / 3, b / 2), c / 2);
	a -= ans * 3;
	b -= ans * 2;
	c -= ans * 2;
	ans *= 7;
	int pans = 0;
	for(int i = 0; i < 14; i += 1)
		for(int j = i; j < 14; j += 1){
			int aaa = 0, bbb = 0, ccc = 0;
			for(int k = i; k <= j; k += 1) aaa += aa[k], bbb += bb[k], ccc += cc[k];
			if(aaa <= a and bbb <= b and ccc <= c) pans = max(pans, j - i + 1);
		}
	cout << ans + pans;
}