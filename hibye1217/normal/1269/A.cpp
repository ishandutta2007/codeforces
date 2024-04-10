#include <bits/stdc++.h>
#define Fast ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define f first
#define s second
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;

bool f(int x){
	for (int i = 2; i*i <= x; i++) if (x % i == 0) return true;
	return false;
}

int main(){
	Fast;
	int n;
	cin >> n;
	for (int i = 4; ; i++){
		if (f(i) && f(i+n)){
			cout << i+n << ' ' << i;
			return 0;
		}
	}
}