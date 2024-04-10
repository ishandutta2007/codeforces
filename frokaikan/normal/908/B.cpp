#include <bits/stdc++.h>
#define constant const constexpr
typedef long long ll;
typedef long double db;
typedef std::string str;
constant int maxN = 1e5 + 3;
typedef int intvec[maxN];
typedef ll llvec[maxN];
typedef db dbvec[maxN];
typedef bool boolvec[maxN];
typedef str strvec[maxN];
typedef char c_str[maxN];
template <typename T> inline constant T abs(T x) {return x>=0?x:-x;}

str maze[52];
int row,col;
struct pos
{
	int x,y;
	pos(int _x=-1,int _y=-1):x(_x),y(_y) {}
	operator bool() const
	{
		if (x<0) return false;
		if (x>=row) return false;
		if (y<0) return false;
		if (y>=col) return false;
		if (maze[x][y] == '#') return false;
		return true;
	}
	bool operator==(const pos& p) const
	{
		if (x!=p.x) return false;
		if (y!=p.y) return false;
		return true;
	}
	void move(int i)
	{
		if      (i == 0) ++x;
		else if (i == 1) --x;
		else if (i == 2) ++y;
		else             --y;
	}
};
pos st,ed;
char ops[103];
int op_mapping[4];
bool used[4];
int ans,len;
void read()
{
	std::fill_n(used,false,4);
	ans = 0;
	std::scanf("%d %d",&row,&col);
	for (int r=0;r<row;++r) std::cin >> maze[r];
	std::scanf("%s",ops);
	len = std::strlen(ops);
	for (int r=0;r<row;++r)
	for (int c=0;c<col;++c)
	{
		if (maze[r][c] == 'S') st = {r,c};
		if (maze[r][c] == 'E') ed = {r,c};
	}
}
bool check()
{
	pos new_st = st;
	for (int i=0;i<len;++i)
	{
		int op = op_mapping[ops[i]-'0'];
		new_st.move(op);
		if (!bool(new_st)) return false;
		if (new_st == ed) return true;
	}
	return false;
}
void dfs(int i)
{
	if (i == 4)
	{
		if (check()) ++ans;
	}
	else
	{
		for (int o=0;o<4;++o)
		{
			if (!used[o])
			{
				used[o] = true;
				op_mapping[i] = o;
				dfs(i+1);
				used[o] = false;
			}
		}
	}
}
int main()
{
	read();
	dfs(0);
	std::printf("%d\n",ans);
}