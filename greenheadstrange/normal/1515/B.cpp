//Awwawa! Dis cold yis ratten buy tEMMIE!
#include <bits/stdc++.h>
#define ll long long
#define maxn 1000005 /*rem*/
#define mod 998244353
#define db double
#define vi vector<int>
#define pb push_back
#define mp make_pair
#define pi pair<int, int>
#define fi first
#define se second

template <typename T> bool chkmax(T &x, T y) {return x < y ? x = y, true : false;}
template <typename T> bool chkmin(T &x, T y) {return x > y ? x = y, true : false;}

using namespace std;

set<ll> a;

int main() {
	for (int i=1;i<=100000;i++) {
		a.insert(2ll*i*i);
		a.insert(4ll*i*i);
	}
	int T;
	scanf("%d",&T);
	for (int i=0;i<T;i++) {
		int x;
		scanf("%d",&x);
		puts(a.count(x)?"YES":"NO");
	}
}