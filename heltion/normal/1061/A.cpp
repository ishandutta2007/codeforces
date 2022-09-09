#include<bits/stdc++.h>
#define maxn
using namespace std;
typedef long long LL;
int main(){
	ios::sync_with_stdio(false);
	LL n, S;
	cin >> n >> S;
	cout << (S + n - 1) / n;
}