//Author: Heltion
//Date: 08-13-2019
#include<bits/stdc++.h>
using namespace std;
using LL = long long;
template<typename T>void no(T s){cout << s; exit(0);}
void no(){cout << "NO"; exit(0);}
constexpr int maxn = 100;
struct node{
	int a, b;
}z[maxn], f[maxn];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cout << fixed << setprecision(20);
	int n, r, zn = 0, fn = 0;
	cin >> n >> r;
	for(int i = 0; i < n; i += 1){
		int a, b;
		cin >> a >> b;
		if(b >= 0) z[zn ++] = {a, b};
		else f[fn ++] = {a, b};
	}
	sort(z, z + zn, [](const node &x, const node &y){
		return x.a < y.a;
	});
	for(int i = 0; i < zn; i += 1) if(r < z[i].a) no();
	else r += z[i].b;
	sort(f, f + fn, [](const node &x, const node &y){
		return x.a + x.b > y.a + y.b;
	});
	for(int i = 0; i < fn; i += 1) if(r < f[i].a) no();
	else r += f[i].b;
	if(r < 0) no();
	cout << "YES";
	return 0;
}