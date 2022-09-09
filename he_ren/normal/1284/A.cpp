#include<cstdio>
#include<cstring>
#include<iostream>
#include<string>
using namespace std;
const int MAXN = 20 + 5;

string s[MAXN],t[MAXN];

int main(void)
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1; i<=n; ++i) cin>>s[i];
	for(int i=1; i<=m; ++i) cin>>t[i];
	
	int Q;
	scanf("%d",&Q);
	while(Q--)
	{
		int q;
		scanf("%d",&q);
		q%=n*m;
		if(!q) q=n*m;
		
		int i=1,j=1;
		while(--q)
		{
			if(++i>n) i=1;
			if(++j>m) j=1;
		}
		cout<<s[i]+t[j]<<endl;
	}
	return 0;
}