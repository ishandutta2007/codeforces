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
int a[maxn];
ll s[maxn];
point r[maxn];
db res[maxn];
int cnt = 0;
int main() {
	int n;
	cin >> n;
	s[0] = 0;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		s[i] = s[i - 1] + a[i];
	}
	for (int i = n; i >= 0; i--) {
		point cur = point(i, s[i]);
		while (cnt >= 2 && (r[cnt - 1] - cur) * (r[cnt - 2] - cur) <= 0) cnt--;
		r[cnt++] = cur;
	}
	for (int i = cnt - 1; i >= 1; i--)
		for (int j = r[i].x + 1; j <= r[i - 1].x; j++)
			res[j] = 1.0 * (r[i - 1].y - r[i].y) / (r[i - 1].x - r[i].x);
	for (int i = 1; i <= n; i++) {
		printf("%.10lf\n", res[i]);
	}
	return 0;
}
/*
1 2
..
*/