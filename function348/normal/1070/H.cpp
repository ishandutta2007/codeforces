#include<cstdio>
#include<iostream>
#include<set>
#include<queue>
#include<map>
#include<vector>
#include<cstring>
#include<algorithm>
#define FR first
#define SC second
#define MP make_pair
using namespace std;
void upmax(int &a,int b) { if (a<b) a=b;}
void upmin(int &a,int b) { if (a>b) a=b;}
typedef long long LL;
typedef pair<int,int> PII;
//---------------------------------
const int N=1000010,p=1000000007;
int n,num;
char ans[N][10];
char s[100];
int cnt[N],v[N],ch[N][40];
int main()
{
	scanf("%d",&n);
	while (1)
	{
		scanf("%s",s);
		int len=strlen(s);
		for (int i=0;i<len;i++)
		{
			int now=0;
			int c;
			for (int j=i;j<len;j++)
			{
			if (s[j]>='a'&&s[j]<='z') c=s[j]-'a';else
			if (s[j]<='9'&&s[j]>='0') c=s[j]-48+26;else
				c=36;
				if (ch[now][c]==0) ch[now][c]=++num;
				now=ch[now][c];
				if (v[now]!=n) 
				{
					v[now]=n,cnt[now]++;
					if (cnt[now]==1) 
						for (int k=0;k<=len;k++) ans[now][k]=s[k];
				}
			}
		}
		n--;
		if (n==0) break;
	}
	scanf("%d",&n);
	while (n--)
	{
		scanf("%s",s);
		int len=strlen(s);
		int now=0;
		for (int i=0;i<len;i++)
		{
			if (s[i]>='a'&&s[i]<='z') s[i]=s[i]-'a';else
			if (s[i]<='9'&&s[i]>='0') s[i]=s[i]-48+26;else
				s[i]=36;
		}
		int flag=0;
		for (int i=0;i<len;i++)
		{
			if (ch[now][s[i]]==0) 
			{
				printf("0 -\n");
				flag=1;
				break;
			}
			now=ch[now][s[i]];
		}
		if (!flag) printf("%d %s\n",cnt[now],ans[now]);
	}
	return 0;
}