#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <vector>
#include <iostream>
#include <functional>
#include <queue>
 
using namespace std;
 
typedef pair<int,int> P;
typedef pair<int,P> P1;
#define fi first
#define sc second
#define mp make_pair
#define pb push_back
#define INF 100000000

int main()
{
	string s[8];
	for(int i=0;i<8;i++) cin >> s[i];
	int x[26]={};
	x['q'-'a'] = 9;
	x['r'-'a'] = 5;
	x['b'-'a'] = 3;
	x['n'-'a'] = 3;
	x['p'-'a'] = 1;
	x['k'-'a'] = 0;
	int w = 0,b = 0;
	for(int i=0;i<8;i++)
	{
		for(int j=0;j<8;j++)
		{
			if(s[i][j] == '.') continue;
			if(0 <= s[i][j]-'A' && s[i][j]-'A' < 26)
			{
				w += x[s[i][j]-'A'];
			}
			else
			{
				b += x[s[i][j]-'a'];
			}
		}
	}
	if(w>b) puts("White");
	if(w==b) puts("Draw");
	if(w<b) puts("Black");
}