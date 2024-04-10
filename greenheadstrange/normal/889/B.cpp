#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#define ll long long
#define maxn 100005 
using namespace std;
int fa[maxn];
int gfa(int a)
{
	if(fa[a] == a) return a;
	return fa[a] = gfa(fa[a]);
}
int nx[maxn], pre[maxn];
bool flag = 1;
void lk(int a, int b)
{
//	cout<<"LK"<<a<<" "<<b<<endl;
	if(nx[a] == b) return; 
	if(gfa(a) == gfa(b)) flag = 0;
	if(nx[a]) flag = 0;
	if(pre[b]) flag = 0;
	nx[a] = b, pre[b] = a;
	fa[gfa(a)] = gfa(b);
}
char inp[maxn];
bool hv[maxn];
int main() 
{
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= 26; i++) fa[i] = i;
	for(int i = 1; i <= n; i++)
	{
		scanf("%s", inp);
		int l = strlen(inp);
		for(int j = 0; j < l; j++)
			hv[inp[j] - 'a' + 1] = 1;
		for(int j = 0; j < l - 1; j++)
			lk(inp[j] - 'a' + 1, inp[j + 1] - 'a' + 1);
	}
	if(!flag) printf("NO\n");
	else
	{
		for(int i = 1; i <= 26; i++)
			if(pre[i] || !hv[i]) continue;
			else
			{
				int npl = i;
				while(npl)
					printf("%c", char('a' + npl - 1)),
					npl = nx[npl];
			}
		printf("\n"); 
	}
	return 0;
}