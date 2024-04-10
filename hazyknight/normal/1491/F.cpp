#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2005;

int T,n;
int ans[MAXN];

string t;

bool vis[MAXN << 2];

int cnt;

int ask(vector<int> a,vector<int> b)
{
	cout << "? " << a.size() << ' ' << b.size() << endl;
	for (int i = 0;i < a.size();i++)
		cout << a[i] << ' ';
	cout << endl;
	for (int i = 0;i < b.size();i++)
		cout << b[i] << ' ';
	cout << endl;
	cout.flush();
	int input;
	cin >> input;
	return input;
	cnt++;
	int n1 = 0,s1 = 0,n2 = 0,s2 = 0;
	for (int i = 0;i < a.size();i++)
	{
		if (t[a[i] - 1] == 'N')
			n1++;
		if (t[a[i] - 1] == 'S')
			s1++;
	}
	for (int i = 0;i < b.size();i++)
	{
		if (t[b[i] - 1] == 'N')
			n2++;
		if (t[b[i] - 1] == 'S')
			s2++;
	}
	int val = n1 * n2 + s1 * s2 - n1 * s2 - n2 * s1;
	if (abs(val) > n)
	{
		puts("crash");
		exit(0);
	}
	return val;
}

int FIND(int l,int r,int vl,int vr,bool need)
{
	vector<int> L,R;
	if (l == r)
	{
		if (need)
		{
			for (int i = l;i <= r;i++)
				L.push_back(i);
			for (int i = vl;i <= vr;i++)
				R.push_back(i);
			if (!ask(L,R))
				return 0;
		}
		return l;
	}
	int mid = l + r >> 1;
	L.clear();
	R.clear();
	for (int i = l;i <= mid;i++)
		L.push_back(i);
	for (int i = vl;i <= vr;i++)
		R.push_back(i);
	if (ask(L,R))
		return FIND(l,mid,vl,vr,0);
	return FIND(mid + 1,r,vl,vr,need);
}

int main()
{
	cin >> T;
	while (T--)
	{
		cnt = 0;
		memset(ans,0,sizeof(ans));
		cin >> n;
		int mag = 0;
		for (int i = 1;i < n;i++)
		{	
			vector<int> suf,cur;
			cur.push_back(i);
			for (int j = i + 1;j <= n;j++)
				suf.push_back(j);
			if (int tot = ask(cur,suf))
			{
				mag = i;
				ans[i] = 1;
				int sum = 0;
				for (int j = i + 1;j < n;j++)
				{
					suf.clear();
					suf.push_back(j);
					int tt = ask(cur,suf);
					ans[j] = tt ? 1 : -1;
					sum += tt;
				}
				ans[n] = (tot - sum) ? 1 : -1;
				if (i > 1)
				{
					int pre = FIND(1,i - 1,mag,mag,1);
					for (int j = 1;j < i;j++)
						ans[j] = (pre == j ? 1 : -1);
				}
				break;
			}
		}
		vector<int> FINAL;
		for (int i = 1;i <= n;i++)
			if (ans[i] == -1)
				FINAL.push_back(i);
		cout << "! " << FINAL.size() << ' ';
		for (int i = 0;i < FINAL.size();i++)
			cout << FINAL[i] << ' ';
		cout << endl;
	}
	return 0;
}