#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int isPalin[2020][2020],f[2020][2020];
long long ans;

int main()
{
	string s;
	cin >> s;
	int n=s.size();
	
	for (int i=0;i<n;i++) isPalin[i][i]=f[i][i]=1;
	for (int i=0;i+1<n;i++) isPalin[i][i+1]=s[i]==s[i+1], f[i][i+1]=2+(s[i]==s[i+1]);
	
	for (int l=2;l<n;l++)
		for (int i=0;i+l<n;i++)
		{
			int j=i+l;
			isPalin[i][j]=(isPalin[i+1][j-1] && s[i]==s[j]);
			f[i][j]=f[i][j-1]+f[i+1][j]-f[i+1][j-1]+isPalin[i][j];
		}
		
	for (int i=0;i+1<n;i++)
		for (int j=i;j+1<n;j++)
			if (isPalin[i][j]) ans+=f[j+1][n-1];
			
	cout << ans << endl;
}