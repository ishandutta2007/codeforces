#include <cstdlib>    
#include <cctype>   
#include <cstring>   
#include <cstdio>   
#include <cmath>   
#include <algorithm>   
#include <vector>   
#include <string>   
#include <iostream>   
#include <sstream>   
#include <map>   
#include <set>   
#include <queue>   
#include <stack>   
#include <fstream>   
#include <numeric>   
#include <iomanip>   
#include <bitset>   
#include <list>   
#include <stdexcept>   
#include <functional>   
#include <utility>   
#include <ctime>
using namespace std;
ifstream fin("aa.txt");
#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define MEM(a,b) (memset((a),(b),sizeof(a)))
int flag[101];
int ans[10];
int main()
{
	int n,q;
	int a,b;
	string str;
	cin >> n >> q;
	cin >> str;
	for(int i = 0; i < q; i++)
	{
		cin >> a >> b;
		a--;
		b--;
		MEM(flag,1);
		int p1,p2;
		
		p1 = a;
		p2 = 1;
		MEM(ans,0);
		string tmp = str;
		while(p1 >= a && p1 <= b) 
		{
			if(tmp[p1] == '<')
			{
				int pt = p1;
				p2 = -1;
				p1 += p2;
				if(p1 < a) break;
				while(flag[p1] == 0)
				{
					p1--;
					if(p1 < a) break;
				}
				if(p1 < a)break;
				if(tmp[p1] == '<' || tmp[p1] == '>')
				{
					flag[pt] = 0;
				}
				continue;
			}
			if(tmp[p1] == '>')
			{
				int pt = p1;
				p2 = 1;
				p1 += p2;
				if(p1 > b) break;

				while(flag[p1] == 0)
				{
					p1++;
					if(p1 > b) break;
				}
				if(p1 > b) break;
				if(tmp[p1] == '<' || tmp[p1] == '>')
				{
					flag[pt] = 0;
				}
				continue;
			}
			
			ans[tmp[p1]-'0']++;
			
			if(tmp[p1] == '0') flag[p1] = 0;
			else tmp[p1]--;
			p1 += p2;
			if(p1 > b || p1 < a)
				break;
			while(flag[p1] == 0)
			{
				p1 += p2;
				if(p1 > b || p1 < a)
					break;
			}
			
		}
		cout << ans[0];
		for(int i = 1; i < 10; i++)
		{
			cout << ' ' << ans[i];
		}
		cout << endl;
	}

	return 0;
}