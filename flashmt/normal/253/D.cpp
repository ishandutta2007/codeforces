#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;

int n, m, k, cntAInRow[444][444], a[444][444], cntChar[444][26];
long long ans;

int main()
{
	freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
	cin >> m >> n >> k;
	for (int i = 1; i <= m; i++) 
	{
		string s;
		cin >> s;
		for (int j = 1; j <= n; j++) 
		{
			a[i][j] = s[j - 1] - 'a';
			cntAInRow[i][j] = cntAInRow[i][j - 1] + (!a[i][j]);
		}
	}
	
	for (int j = 0; j < n; j++)
		for (int jj = j + 2; jj <= n; jj++)
			for (int ii = 1, i = 0, sumAi = 0, sumAii = 0; ii <= m; ii++)
			{
				for (int c = 0; c < 26; c++) cntChar[ii][c] = cntChar[ii - 1][c];
				sumAii += cntAInRow[ii][jj] - cntAInRow[ii][j];
				
				if (a[ii][jj] != a[ii][j + 1]) continue;

				while (sumAii - sumAi > k) i++, sumAi += cntAInRow[i][jj] - cntAInRow[i][j];
				ans += cntChar[ii][a[ii][jj]] - cntChar[i][a[ii][jj]];

				cntChar[ii][a[ii][jj]]++;
			}
	
	cout << ans << endl;
}