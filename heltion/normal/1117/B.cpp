#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;
auto no = [](){cout << "No"; exit(0);};
auto read = [](){int x; cin >> x; return x;};
#define maxn 240000
LL a[maxn];
int main(){
	ios::sync_with_stdio(false);
	int mai = 0, smai = 0, n;
	LL m, k;
	cin >> n >> m >> k;
	for(int i = 1; i <= n; i += 1){
		cin >> a[i];
		if(a[i] >= a[mai]) smai = mai, mai = i;
		else if(a[i] >= a[smai]) smai = i;
	}
	LL s = m / (k + 1) * k + m % (k + 1), t = m - s;
	//cout << s << " " << t << endl;
	//cout << mai << " " << smai << endl;
	cout << s * a[mai] + t * a[smai];
}