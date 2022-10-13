#include <iostream>
#include <algorithm>
using namespace std;

int marker[1111][1111],cap[1111][1111];

int main()
{
	int n,m,x,y,closed=0,beautiful=0;
	cin >> n >> m;
	while (n--) cin >> x >> y, marker[y][x]++;
	while (m--) cin >> x >> y, cap[y][x]++;
	
	for (int i=1;i<=1000;i++)
	{
		int cnt1=0,cnt2=0;
		for (int j=1;j<=1000;j++)
		{
			cnt1+=marker[i][j];
			cnt2+=cap[i][j];
			beautiful+=min(marker[i][j],cap[i][j]);
		}
		closed+=min(cnt1,cnt2);
	}
	cout << closed << ' ' << beautiful << endl;
}