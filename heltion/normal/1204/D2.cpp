//Author: Heltion
//Date: 08-20-2019
#include<bits/stdc++.h>
using namespace std;
using LL = long long;
template<typename T>void no(T s){cout << s; exit(0);}
void no(){cout << "NO"; exit(0);}
constexpr int maxn = 120000;
char s[maxn], t[maxn];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cout << fixed << setprecision(20);
	cin >> (s + 1);
	int n = strlen(s + 1);
	for(int i = n, dp0 = 0, dp1 = 0; i; i -= 1){
		if(s[i] == '0') dp0 = max(dp0, dp1) + 1;
		else dp1 += 1;
		if(s[i] == '0') t[i] = '0';
		else if(dp0 < dp1) t[i] = '0';
		else t[i] = '1';
	}
	cout << (t + 1);
	return 0;
}