#include <bits/stdc++.h>
using namespace std;

int pre[100100], longest[100100], cnt[100100];

void calcPre(string p)
{
	int i = 0, j = -1, n = p.size();
	pre[0] = -1;
	while (i < n)
	{
		while (j >= 0 && p[i] != p[j]) j = pre[j];
		longest[i++] = j++;
		pre[i] = (j >= n || p[i] != p[j] ? j : pre[j]);
	}
}

int main()
{
	ios::sync_with_stdio(0);
	string s;
	cin >> s;
	
	calcPre(s);
	int n = s.size();
	for (int i = 0; i < n; i++) cnt[i] = 1;
	for (int i = n - 1; i >= 0; i--) 
		if (longest[i] >= 0) cnt[longest[i]] += cnt[i];
	
	vector < pair<int,int> > ans;
	for (int i = n - 1; i >= 0; i = longest[i])
		ans.push_back(make_pair(i + 1, cnt[i]));
		
	sort(ans.begin(), ans.end());
	cout << ans.size() << endl;
	for (int i = 0; i < int(ans.size()); i++)
		cout << ans[i].first << ' ' << ans[i].second << '\n';
}