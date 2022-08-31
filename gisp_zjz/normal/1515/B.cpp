#include<bits/stdc++.h>
#define F first
#define S second
#define pb push_back
using namespace std;
typedef pair<int,int>pi;
typedef vector<int>vi;
typedef long long ll;
const int maxn=1e5+20;
const int M=998244353;
int _,n;
bool check(int x){
	if (x%2) return 0;
	x/=2;
	int y=sqrt(0.5+(double)x);
	if (y*y==x) return 1;
	if (x%2) return 0;
	x/=2;
	y=sqrt(0.5+(double)x);
	if (y*y==x) return 1;
	return 0;
}
int main(){
	cin >> _;
	while (_--){
		cin >> n;
		if (check(n)) puts("YES"); else puts("NO");
	}
	return 0;
}