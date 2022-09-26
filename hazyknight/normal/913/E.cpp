#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <queue>

using namespace std;

const int rev = (1 << 8) - 1;
const int INF = (1 << 30) - 1;

int n;
int len[(1 << 8)][3];
string ans[(1 << 8)][3];

struct Node
{
	int to;
	string path;
	int lev;
};

queue<Node> Q;

void change(int to,string path,int lev)
{
	if (path.size() < len[to][lev] || (path.size() == len[to][lev] && path < ans[to][lev]))
	{
		ans[to][lev] = path;
		len[to][lev] = path.size();
		Q.push((Node){to,path,lev});
	}
}

void init()
{
	for (int i = 0;i < (1 << 8);i++)
		len[i][0] = len[i][1] = len[i][2] = INF;
	ans[15][0] = "x";
	len[15][0] = 1;
	Q.push((Node){15,"x",0});
	ans[51][0] = "y";
	len[51][0] = 1;
	Q.push((Node){51,"y",0});
	ans[85][0] = "z"; 
	len[85][0] = 1;
	Q.push((Node){85,"z",0});
	while (!Q.empty())
	{
		int now = Q.front().to,to,lev = Q.front().lev;
		string path = Q.front().path,newpath;
		Q.pop();
		if (path != ans[now][lev])
			continue;
		
		to = (now ^ rev);
		if (!lev)
		{
			newpath = "!" + path;
			change(to,newpath,0);
		}
		else
		{
			newpath = "!(" + path + ")";
			change(to,newpath,0);
		}
		
		for (int i = 0;i < (1 << 8);i++)
		{
			if (len[i][0] <= path.size())
			{
				to = (now | i);
				newpath = path + "|" + ans[i][0];
				change(to,newpath,1);
				newpath = ans[i][0] + "|" + path;
				change(to,newpath,1);
				
				to = (now & i);
				newpath.clear();
				if (lev == 1)
					newpath = "(" + path + ")" + "&" + ans[i][0];
				else
					newpath = path + "&" + ans[i][0];
				change(to,newpath,2);
				newpath.clear();
				if (lev == 1)
					newpath = ans[i][0] + "&" + "(" + path + ")";
				else
					newpath = ans[i][0] + "&" + path;
				change(to,newpath,2);
			}
			if (len[i][1] <= path.size())
			{
				to = (now | i);
				newpath = path + "|" + ans[i][1];
				change(to,newpath,1);
				newpath = ans[i][1] + "|" + path;
				change(to,newpath,1);
				
				to = (now & i);
				newpath.clear();
				if (lev == 1)
					newpath = "(" + path + ")" + "&(" + ans[i][1] + ")";
				else
					newpath = path + "&(" + ans[i][1] + ")";
				change(to,newpath,2);
				newpath.clear();
				if (lev == 1)
					newpath = "(" + ans[i][1] + ")" + "&(" + path + ")";
				else
					newpath = "(" + ans[i][1] + ")&" + path;
				change(to,newpath,2);
			}
			if (len[i][2] <= path.size())
			{
				to = (now | i);
				newpath = path + "|" + ans[i][2];
				change(to,newpath,1);
				newpath = ans[i][2] + "|" + path;
				change(to,newpath,1);
				
				to = (now & i);
				newpath.clear();
				if (lev == 1)
					newpath = "(" + path + ")&" + ans[i][2];
				else
					newpath = path + "&" + ans[i][2];
				change(to,newpath,2);
				newpath.clear();
				if (lev == 1)
					newpath = ans[i][2] + "&(" + path + ")";
				else
					newpath = ans[i][2] + "&" + path;
				change(to,newpath,2);
			}
		}
	}
	for (int i = 0;i < (1 << 8);i++)
		change(i,ans[i][1],0),change(i,ans[i][2],0);
}

int main()
{
	ios::sync_with_stdio(false);
	init();
	cin >> n;
	for (int i = 1;i <= n;i++)
	{
		string s;
		cin >> s;
		int cnt = 0;
		for (int j = 0;j < 8;j++)
			if (s[7 - j] == '1')
				cnt += (1 << j);
		cout << ans[cnt][0] << endl;
	}
	return 0;
}