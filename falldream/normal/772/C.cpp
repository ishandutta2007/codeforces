#include<iostream>
#include<cstdio>
#include<vector> 
#define MN 200000
using namespace std;
inline int read()
{
	int x = 0 , f = 1; char ch = getchar();
	while(ch < '0' || ch > '9'){ if(ch == '-') f = -1;  ch = getchar();}
	while(ch >= '0' && ch <= '9'){x = x * 10 + ch - '0';ch = getchar();}
	return x * f;
}

int  n , m , from , ans = 0 , f[MN + 5] , last = 1 , ne[MN + 5];
bool b[MN + 5];
vector<int> v[MN + 5];
inline int gcd(int x,int y){return !y ? x :gcd(y , x % y);}

int exgcd(int a , int b , int&x , int&y)
{
	if(!b) {x = 1 , y = 0; return a;} 	
	int c = exgcd(b , a % b , x , y);
	int t = x; x = y; y = t - (a / b) * x;
	return c;
}

void solve(int x)
{
	if(ne[x]) solve(ne[x]);
	int X = 0, Y = 0 , Z;
	for(int i = 0 ; i < v[x].size() ; ++i)
		Z = exgcd(last , m , X , Y) , printf("%d ",(1LL * X * v[x][i] / Z % m + m) % m) , last = v[x][i];
}

int main()
{
	n = read(); m = read();
	for(int i = 1 ; i <= n ; ++i) b[read()] = 1;
	for(int i = 1 ; i < m ; ++i) if(!b[i]) v[gcd(i , m)].push_back(i);
	for(int i = 1 ; i < m ; ++i) 
	{
		if((f[i] += v[i].size()) > ans) ans = f[i] , from = i;
		for(int j = i << 1 ; j < m ; j += i)
			if(f[i] > f[j]) f[j] = f[i] , ne[j] = i;
	}
	printf("%d\n", ans + !b[0]);
	solve(from);
	if(!b[0]) puts("0");
	return 0;
}