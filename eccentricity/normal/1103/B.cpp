#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define maxn 10
char s[maxn];
int t, c;
bool ask(LL x, LL y){
	c += 1;
	cout << "? " << x << " " << y << endl;
//	return x % t >= y % t;
	cin >> s;
	return s[0] == 'x';
}
void ans(LL x){
	cout << "! " << x << endl;
//	cout << c;
}
int main(){
	while(cin >> s){
		c = 0;
		if(s[0] == 'e') return 0;
		LL k = 1, ok = 0;
		while(ask(2 * k, k)){
			k *= 2;
			if(k * 2 > 2E9){
				ans(1);
				ok = 1;
				break;
			} 
		} 
		if(ok) continue;
		if(ask(0, 2 * k)){
			ans(2 * k);
			continue;
		}
		LL x = k;
		for(k /= 2; k; k /= 2){
			int r = ask(x + k * 2 - 1, x + k - 1);
			if(r == 0) x += k;
		}
		ans(x);
	}
}