#include <iostream>
#include <fstream>

using namespace std;
#define N 444
int n, m, k, s[N][N], x[26];
char a[N][N];
long long ans=0;
int main()
{
	ifstream cin("input.txt");
	ofstream cout("output.txt");
	cin >> n >> m >> k;
	for (int i=0; i<n; i++) {
		cin >> a[i];
		for (int j=0; j<m; j++) s[i+1][j]=s[i][j]+(a[i][j]=='a');
	}
	for (int i=0; i<n; i++) for (int j=i+1; j<n; j++) {
		for (int z=0; z<26; z++) x[z]=0;
		int l=0, r=0, sum=0;
		while (r<m) {

			while (r<m&&a[i][r]!=a[j][r]) sum+=s[j+1][r]-s[i][r], r++;
			if (r==m||a[i][r]!=a[j][r]) break;
			else sum+=s[j+1][r]-s[i][r], r++;
			while (sum > k) {
				sum-=s[j+1][l]-s[i][l], l++;
				if (a[i][l-1]==a[j][l-1]) x[a[i][l-1]-'a']--;
			}
			if (l<r) ans+=x[a[i][r-1]-'a'];
			x[a[i][r-1]-'a']++;
		}
	}
	cout << ans;
	return 0;
}