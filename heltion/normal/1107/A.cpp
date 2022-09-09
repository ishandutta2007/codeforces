#include<bits/stdc++.h>
#define maxn 320
using namespace std;
typedef long long LL;
auto no = [](){cout << "NO"; exit(0);};
char s[maxn];
int main(){
	ios::sync_with_stdio(false);
	int q;
	cin >> q;
	while(q --){
		int n;
		cin >> n >> s;
		if(n == 1 or n == 2 and s[0] >= s[1]) cout << "NO" << endl;
		else cout << "YES\n2\n" << s[0] << " " << s + 1 << endl;
	}
}