#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <set>
#define maxn 5005 
#define maxm 1005
using namespace std;
int pre[2][maxn]; // -1 mins ? 
int ope[maxn]; // 0 and 1 xor 0 or
char inp[maxn][10];
int n, m;
int num[maxn][maxm];
struct str
{
	char a[12];
	int len, id;
	bool operator < (const str & x)const
	{
		for(int i = 0; i < min(x.len, len); i++)
			if(a[i] != x.a[i]) 
				return a[i] < x.a[i];
		return len < x.len;
	}
};
set <str> q; 
int ans[2][maxm];
int nownum[maxn];
int mins[maxm], maxs[maxm];
int main()
{
	scanf("%d%d", &n, &m);
	for(int i = 0; i < n; i++)
	{
		str nows;
		nows.id = i;
		scanf("%s", nows.a);
		
		nows.len = strlen(nows.a);
	//	cout<<i<<" "<<nows.a<<" "<<nows.len<<endl;
		q.insert(nows);
		
		char inp[maxm];
		
		scanf("%s", &inp);
		scanf("%s", &inp);
		if(inp[0] == '0' || inp[0] == '1')
		{
			for(int j = 0; j < m; j++) num[i][j] = inp[j] - '0';
			pre[0][i] = -2, pre[1][i] = -2;
		}
		else
		{
			str nows2;
			for(int j = 0; j < strlen(inp); j++)
				nows2.a[j] = inp[j];
			nows2.len = strlen(inp);
			if(nows2.a[0] == '?') pre[0][i] = -1;
			else 
			{
				set <str>::iterator x;
			
				x = q.find(nows2);	
				//cout<<nows2.len<<endl;
			//	if(x == q.end()) cout<<"!find"<<endl;
				pre[0][i] = (*x).id;
			}
			
			char oper[7];
			scanf("%s", oper);
			if(oper[0] == 'A') ope[i] = 0;
			else if(oper[0] == 'X') ope[i] = 1;
			else ope[i] = 2;
			
			str nows3;
			
			scanf("%s", nows3.a);
			nows3.len = strlen(nows3.a);
			if(nows3.a[0] == '?') pre[1][i] = -1;
			else 
			{
				set <str>::iterator x;
				x = q.find(nows3);
			//	if(x == q.end()) cout<<"!find"<<endl;
			//	cout<<nows2.a<<" "<<nows2endl;
			//	if(x == q.end()) cout<<"!find";
				pre[1][i] = (*x).id;
			}
		}
	
	}
/*	for(int i = 0; i < n; i++)
	{
		cout<<i<<": ";
		for(int j = 0; j < m; j++) cout<<num[i][j];
		cout<<endl;
		cout<<pre[0][i]<<" "<<pre[1][i]<<" "<<ope[i]<<endl;
	}*/
	memset(ans, 0, sizeof(ans));
	for(int i = 0; i < m; i++)
		for(int k = 0; k < 2; k++)
		{
			ans[k][i] = 0;
			for(int j = 0; j < n; j++)
			{
				if(pre[0][j] == -2) 
					nownum[j] = num[j][i];
				else 
				{
					int cals[2];
					for(int l = 0; l < 2; l++)
					{
						if(pre[l][j] == -1) cals[l] = k;
						else cals[l] = nownum[pre[l][j]];
					}
					if(ope[j] == 0)
						nownum[j] = cals[0] & cals[1];
					else if(ope[j] == 1)
						nownum[j] = cals[0] ^ cals[1];
					else nownum[j] = cals[0] | cals[1];  
					ans[k][i] += nownum[j];
				}
		//		cout<<k<<" "<<i<<" "<<j<<":"<<nownum[j]<<" "<<endl;
			}
		}
	for(int i = 0; i < m; i++)
	{
		mins[i] = 0, maxs[i] = 0;
		if(ans[1][i] > ans[0][i]) maxs[i] = 1;
		if(ans[1][i] < ans[0][i]) mins[i] = 1;
	}
	for(int i = 0; i < m; i++)
		printf("%d", mins[i]);
	printf("\n");
	for(int i = 0; i < m; i++)
		printf("%d", maxs[i]);
	return 0;
} 
/*
3 3
aaa := 111
aa := aaa XOR ?
a := aa XOR aaa
*/