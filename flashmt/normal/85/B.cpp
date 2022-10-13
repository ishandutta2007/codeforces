#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<string>
#include<vector>
#include<utility>
#include<set>
#include<sstream>
#define fr(a,b,c) for (a=b;a<=c;a++)
#define frr(a,b,c) for (a=b;a>=c;a--)
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define F first
#define S second
#define oo 1000111222
using namespace std;
typedef long long ll;

int k[3],t[3],n,d[100100];
long long re,f[100100],a[3][100100];

int main()
{
	int i,j;
	fr(i,0,2) cin >> k[i];
	fr(i,0,2) cin >> t[i];
	cin >> n;
	fr(i,0,2) k[i]=min(k[i],n);
	fr(i,1,n) scanf("%d",&d[i]), f[i]=d[i];
	fr(j,0,2)
	{
		int cur=0;
		fr(i,1,n) 
		{
			f[i]=max(f[i],a[j][cur])+t[j];
			a[j][cur++]=f[i];
			if (cur==k[j]) cur=0;
   	}
	}		
	cout << f[n]-d[n] << endl;
   return 0;
}