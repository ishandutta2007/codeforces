#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
constexpr int maxn = 600;
void no(){ cout << "NO"; exit(0); }
char s[maxn];
int f[maxn][maxn];
int main(){
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	cin >> (s + 1);
	for(int L = 1; L <= n; L += 1)
		for(int i = 1; i + L - 1 <= n; i += 1)
			if(L == 1) f[i][L] = 1;
			else{
				f[i][L] = f[i + 1][L - 1] + 1;
				for(int j = i + 1; j <= i + L - 1; j += 1)
					if(s[i] == s[j]){
						f[i][L] = min(f[i + 1][j - i - 1] + f[j][i + L - j], f[i][L]);
					}
				//cout << i << " " << L << " " << f[i][L] << endl;
			}
	cout << f[1][n];
}