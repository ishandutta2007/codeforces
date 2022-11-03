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
typedef long long LL;
typedef unsigned long long ULL;
#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define MEM(a,b) memset((a),(b),sizeof(a))
const int N = 1<<17;
const int INF = 0x3f3f3f3f;
int q1,q2;	// [q1,q2];
int p,v;	// a[p] = v;
int xor[N*4];
int query(int o, int L, int R)
{
	if(q1 <= L && R <= q2) return xor[o];
	int M = (L+R)/2;
	int ans = INF;
	if(q1 <= M) ans = min(ans,query(o*2,L,M));
	if(M < q2) ans = min(ans,query(o*2+1,M+1,R));
	return ans;
}

void update(int o, int L, int R,int k)
{
	if(L == R) xor[o] = v;
	else
	{
		int M = (L+R)/2;
		if(p <= M) update(o*2,L,M,k-1);
		else update(o*2+1,M+1,R,k-1);
		if(k&1)
			xor[o] = xor[o*2] | xor[o*2+1];
		else
			xor[o] = xor[o*2] ^ xor[o*2+1];
	}
}
int main()
{
	//freopen("input.txt","r",stdin);

	int n,m;
	cin >> n >> m;
	int ans = 0;
	for(int i = 0; i < (1<<n); i++)
	{
		cin >> v;
		p = i+1;
		update(1,1,1<<n,n);
	}
	int x,y;
	for(int i = 0; i < m; i++)
	{
		cin >> x >> y;
		p = x;
		v = y;
		q1 = 1;
		q2 = 1<<n;
		update(1,1,1<<n,n);
		cout << query(1,1,1<<n) << endl;
	}
	return 0;
}