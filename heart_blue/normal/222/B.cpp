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
ifstream fin("ab.txt");
#define MIN(a,b) (a) < (b) ? (a) : (b)
#define MAX(a,b) (a) > (b) ? (a) : (b)
int board[1001][1001];
int row[1001];
int col[1001];
int main()
{
	int n,m,k;
	int a,b;
	char c;
	cin >> n >> m >> k;
	for(int i = 1; i <= n; i++) row[i] = i;
	for(int i = 1; i <= m; i++) col[i] = i;
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= m; j++)
		{
			scanf("%d",&board[i][j]);
		}
	}
	while(k--)
	{
		cin >> c >> a >> b;
		
		if(c == 'r') swap(row[a],row[b]);
		if(c == 'c') swap(col[a],col[b]);
		if(c == 'g') printf("%d\n",board[row[a]][col[b]]);
	}
	return 0;
}