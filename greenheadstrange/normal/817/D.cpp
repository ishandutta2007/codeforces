#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#define maxn 1000005
using namespace std;
int st[maxn], top = 0;
int n, a[maxn]; 
int l[maxn], r[maxn]; 
int main()
{   //
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	long long ans = 0; 
	
	top = 0;
	//find min
	for(int i = n; i >= 1; i--) 
	{
		r[i] = i;
		while(top)
			if(a[st[top - 1]] > a[i]) top--;
			else break;	
		while(top && a[st[top - 1]] == a[i])
			r[i] = st[top - 1], top--;
		if(top && a[st[top - 1]] < a[i]) r[i] = st[top - 1] - 1;
		else r[i] = n;
		st[top++] = i;
	}
	top = 0;
	
	for(int i = 1; i <= n; i++)
	{
		l[i] = i;
		while(top)
			if(a[st[top - 1]] > a[i]) top--;
			else break;	
		if(top) l[i] = st[top - 1] + 1;
		else l[i] = 1;
		st[top++] = i;
		ans -= (long long)(r[i] - i + 1) * (long long)(i - l[i] + 1) * (long long)a[i];
	//	cout<<i<<" "<<r[i]<<" "<<l[i]<<endl;
	}
	for(int i = 1; i <= n; i++)
		a[i] = -a[i];
	top = 0;
	//find min
	for(int i = n; i >= 1; i--) 
	{
		r[i] = i;
		while(top)
			if(a[st[top - 1]] > a[i]) top--;
			else break;	
		while(top && a[st[top - 1]] == a[i])
			r[i] = st[top - 1], top--;
		if(top && a[st[top - 1]] < a[i]) r[i] = st[top - 1] - 1;
		else r[i] = n;
		st[top++] = i;
	}
	top = 0;
	
	for(int i = 1; i <= n; i++)
	{
		l[i] = i;
		while(top)
			if(a[st[top - 1]] > a[i]) top--;
			else break;	
		if(top) l[i] = st[top - 1] + 1;
		else l[i] = 1;
		st[top++] = i;
		ans -= (long long)(r[i] - i + 1) * (long long)(i - l[i] + 1) * (long long)a[i];
	//	cout<<i<<" "<<r[i]<<" "<<l[i]<<" "<<a[i]<<endl;
	}
	printf("%I64d\n", ans);
	return 0;
 }