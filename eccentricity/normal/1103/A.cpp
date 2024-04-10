#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define maxn 1200
char s[maxn];
int main(){
	ios::sync_with_stdio(false);
	int c = 1, u = 0;
	cin >> s;
	int n = strlen(s);
	for(int i = 0; i < n; i += 1)
		if(s[i] == '0'){
			cout << 1 << " " << c << endl;
			c += 1;
			if(c == 5) c= 1;
		}
		else{
			cout << 4 << " " << (u ? 1 : 3) << endl;
			u = 1 - u;
		}
}