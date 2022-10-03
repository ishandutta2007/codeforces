#include<bits/stdc++.h>
using namespace std;

stack<int> st;

int to[200010],pre[200010],n,k;
char s[200010];
bool bo[200010];

inline int rd()
{
	int x=0;char ch=getchar();
	for (;ch<'0'||ch>'9';ch=getchar());
	for (;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-'0';
	return x;
}

int main()
{
	n=rd();k=rd();
	scanf("%s",s+1);
	for (int i=1;i<=n;i++)
	{
		if (s[i]=='(') st.push(i);
		else
		{
			int hh=st.top();st.pop();
			to[hh]=i;pre[i]=hh;
		}
	}
	int now=0;
	memset(bo,true,sizeof(bo));
	for (int i=1;i<=n&&now<(n-k)/2;i++) if (s[i]=='(') bo[i]=false,now++;
	for (int i=1;i<=n;i++)
	{
		if (s[i]=='('&&bo[i]) putchar(s[i]);
		if (s[i]==')'&&bo[pre[i]]) putchar(s[i]);
	}
	putchar('\n');
	return 0;
}