#include<bits/stdc++.h>
#define maxn 320
using namespace std;
typedef long long LL;
auto no = [](){cout << "NO"; exit(0);};
char s[maxn];
int main(){
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	while(n --){
		LL k, x;
		cin >> k >> x;
		cout << (k - 1) * 9 + x << endl;
	} 
}