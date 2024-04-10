#include <iostream>
using namespace std;
int ans[10005],vis[10005];
int main(int argc, char** argv) {
	int n;
	cin >> n;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(i==j) continue;
			if(!ans[i]&&!ans[j])
			{
				cout << "? " << i << " " << j << endl;
				int x;
				cin >> x;
				cout << "? "<< j << ' ' << i << endl;
				int y;
				cin >> y;
				if(y>=x) ans[j]=y;
				else ans[i]=x;
			}
		}
	}
	for(int i=1;i<=n;i++)
		vis[ans[i]]=1;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(!vis[j]&&!ans[i])
				ans[i]=j;
		}
	}
	cout << "! ";
	for(int i=1;i<=n;i++)
		cout << ans[i] << " ";
	cout << endl;
	return 0;
}