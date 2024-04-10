#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
constexpr int maxn = 100;
void no(){ cout << "NO"; exit(0); } 
int main(){
	ios::sync_with_stdio(false);
	int cnt1, cnt2, cnt3, cnt4;
	cin >> cnt1 >> cnt2 >> cnt3 >> cnt4; 
	if(cnt4 == cnt1 and (not cnt3 or cnt1)) cout << 1;
	else cout << 0;
}