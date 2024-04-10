#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <set>
#define maxn 100005
#define mod 1000000007
#define ll long long
using namespace std;
set <int> nex[2]; // 
set <int> dif[2]; // 
set <int> ots[2]; // 
char inp[maxn][8];
int cnt = 0, tp[maxn];;
char otp[maxn * 5][30];

int main()
{
	int n;
	scanf("%d", &n);
	int e = 0;
	
	for(int i = 0; i < n; i++)
	{
		scanf("%s", inp[i]);
		scanf("%d", &tp[i]);	
		tp[i] ^= 1;
		if(!tp[i]) e++;
	}	
	for(int i = 1; i <= e; i++) nex[0].insert(i);
	for(int i = e + 1; i <= n; i++) nex[1].insert(i);
	for(int i = 0; i < n; i++)
	{
		int num = 0;
		int l = strlen(inp[i]);
		if(inp[i][0] == '0') num = -1;
		else
		{
			for(int j = 0; j < l; j++)
				if(inp[i][j] < '0' || inp[i][j] > '9')
				{
					num = -1;
					break;
				}
				else
				{
					num *= 10;
					num += inp[i][j] - '0';
				}
		}
		if(num > n) num = -1;
//		cout<<i<<" "<<num<<endl;
		if(num == -1) ots[tp[i]].insert(i);
		else
		{
			if(num > e) nex[1].erase(num);
			else nex[0].erase(num);
			if(tp[i] == 1 && num <= e) dif[1].insert(num);
			if(tp[i] == 0 && num > e) dif[0].insert(num);
		}
	}
	while(1)
	{
		if(dif[0].empty() && dif[1].empty())
		{
			for(int i = 0; i < 2; i++)
				while(!nex[i].empty())
				{
					int fr1 = *nex[i].begin(), ed1 = *ots[i].begin();
					sprintf(otp[cnt], "move %s %d", inp[ed1], fr1);
					nex[i].erase(fr1), ots[i].erase(ed1);
					cnt++;
				}
			break;
		}
		else
		{
			bool flag = 0;
			for(int i = 0; i < 2; i++)
				if(!dif[i].empty() && !nex[i].empty())
				{
					int fr = *dif[i].begin(), ed = *nex[i].begin();
					sprintf(otp[cnt], "move %d %d", fr, ed);
					nex[i].erase(ed), dif[i].erase(fr);
					nex[!i].insert(fr);
					cnt++;	
					flag = 1;
				} 
			if(!flag)
			{
				int fr = *dif[0].begin(), ed = *dif[1].begin();
				sprintf(otp[cnt], "move %d a", fr);
				inp[fr][0] = 'a', inp[fr][1] = '\0';
				ots[0].insert(fr);
				cnt++;
				sprintf(otp[cnt], "move %d %d", ed, fr);
				cnt++;
				nex[0].insert(ed);
				dif[0].erase(fr), dif[1].erase(ed);
			}
		}
	}
	printf("%d\n", cnt);
	for(int i = 0; i < cnt; i++)
		printf("%s\n", otp[i]);
	return 0;
 }