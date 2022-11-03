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
#define MIN(x,y) ((x) < (y) ? (x) : (y))
#define MAX(x,y) ((x) > (y) ? (x) : (y))
#define MEM(x,y) (memset((x),(y),sizeof(x)))
const int N = 100001;
class edge
{
public:
	int v,w,next;
};
int S[N*20];
edge ve[N*2];
int start[N];
int top[N];
long long tt[2*N];
int die[2*N];
int st[N];
int ed[N];
long long dis[N];
int head,tail;
int k;
void addedge(int a, int b, int c)
{
	if(start[a] == -1) start[a] = k;
	ve[k].v = b;
	ve[k].w = c;
	if(top[a] > -1) ve[top[a]].next = k;
	top[a] = k++;
}
int main()
{
	//cin.rdbuf(fin.rdbuf());
	MEM(ve,-1);
	MEM(top,-1);
	MEM(st,-1);
	MEM(ed,-1);
	MEM(start,-1);
	MEM(dis,0x3f);
	MEM(die,0);
	long long ans = dis[0];
	int n,m;
	cin >> n >> m;
	int a,b,c;
	for(int i = 0; i < m; i++)
	{
		cin >> a >> b >> c;
		addedge(a,b,c);
		addedge(b,a,c);
	}

	int key;
	int k2 = 0;
	for(int i = 1; i <= n; i++)//die
	{
		cin >> key;
		st[i] = k2;
		int tmp = k2;
		int num;
		int cnt = 0;
		while(key--)
		{
			cin >> num;
			if(cnt == 0)
			{
				cnt = 1;
				tt[k2++] = num;
			}
			else
			{
				if(num == tt[tmp]+cnt)
				{
					die[tmp]++;
					cnt++;
				}
				else
				{
					cnt = 1;
					tmp = k2;
					tt[k2++] = num;
				}
			}
		}
		ed[i] = k2;
	}
	dis[1] = 0;
	for(int i = st[1]; i < ed[1]; i++)
	{
		if(dis[1] >= tt[i])
		{
			dis[1] = MAX(dis[1],tt[i]+die[i]+1);
		}
		else break;
	}
	head = tail = 0;
	S[head++] = 1;
	
	while(head != tail)
	{
		int t = S[tail++];
		if(tail == N*20) tail = 0;
		for(int i = start[t]; i != -1; i = ve[i].next)
		{
			if(dis[t] + ve[i].w >= dis[ve[i].v]) continue;
			long long sum = dis[t]+ve[i].w;
			
			int v = ve[i].v;
			if(v == n)
			{
				if(sum < dis[v])
					dis[v] = sum;
				continue;
			}
			for(int i = st[v]; i < ed[v]; i++)
			{
				if(sum >= tt[i])
				{
					sum = MAX(sum,tt[i]+die[i]+1);
				}
				else break;
			}
			if(sum < dis[v])
			{
				S[head++] = v;
				dis[v] = sum;
				if(head == N*20) head = 0;
			}
		}
	}
	if(dis[n] == ans) cout << -1 << endl;
	else cout << dis[n] << endl;


	return 0;

}