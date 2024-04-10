#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define maxn 120000
char s[maxn];
int main(){
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	int mx = 0, my = 0;
	while(n --){
		cin >> s;
		if(*s == '+'){
			int x, y;
			cin >> x >> y;
			if(x > y) swap(x, y);
			mx = max(mx, x);
			my = max(my, y);
		}
		else{
			int h, w;
			cin >> h >> w;
			if(h > w) swap(h, w);
			cout << (h >= mx && w >= my ? "YES" : "NO") << endl;
		}
	}
}