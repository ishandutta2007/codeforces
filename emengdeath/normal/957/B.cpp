#include<bits/stdc++.h>
using namespace std;
char map1[100][100];
int main(){
	ios::sync_with_stdio(false);
	int n,m;
	cin>>n>>m;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
			cin>>map1[i][j];
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
			if (map1[i][j]=='#')
				for (int k=i;k<=n;k++)
					for (int l=1;l<=m;l++)
						if (map1[k][l]=='#'&&((map1[i][l]=='.')^(map1[k][j]=='.')==1)){
							cout<<"No";
							return 0;
						}
	cout<<"Yes";
	return 0;
}