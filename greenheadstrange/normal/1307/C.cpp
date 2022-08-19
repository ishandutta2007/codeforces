#include <bits/stdc++.h>
#define ll long long
#define maxn 1000005 /*rem*/
#define mod 998244353 
#define db double
#define vi vector<int>
#define pb push_back
#define pi pair<int, int>
#define mp make_pair
#define fi first
#define se second
using namespace std;
struct point{ //  
	ll x,y;
	point(ll x=0,ll y=0):x(x),y(y){}
	point operator+(const point c)const{return point(x+c.x,y+c.y);}
	point operator-(const point c)const{return point(x-c.x,y-c.y);}
	ll operator*(const point c)const{return 1ll*x*c.y-1ll*y*c.x;}
	bool operator<(const point c)const{return x==c.x?y<c.y:x<c.x;}
};
char inp[maxn];
int cnt[26];
ll ans[26][26];
int main() {
	scanf("%s", inp);
	ll res = 0;
	int l = strlen(inp);
	for (int i = 0; i < l; i++) {
		int c = inp[i] - 'a';
		for (int j = 0; j < 26; j++)
			ans[j][c] += cnt[j];
		cnt[c]++;
	}
	for (int i = 0; i < 26; i++) {
		res = max(res, (ll)cnt[i]);
		for (int j = 0; j < 26; j++)
			res = max(res, ans[i][j]);
	}
	cout << res << endl;
	return 0;
}
/*
1 2
..
*/