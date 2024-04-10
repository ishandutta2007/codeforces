//while(true)rp++;
#include<algorithm>
#include<cstdlib>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<deque>
#include<fstream>
#include<iostream>
#include<iomanip>
#include<map>
#include<queue>
#include<set>
#include<stack>
#include<string>
#include<utility>
#include<vector>
using namespace std;
typedef long long ll;
#define FF first
#define SS second
#define PB push_back
#define MP make_pair
const int maxn=400011;
ll sum2=0;
bool vis[maxn];
struct SAM
{
	int go[maxn][27],pre[maxn],len[maxn],tot,last;
	void init()
	{
		memset(go,-1,sizeof(go));
		memset(pre,-1,sizeof(pre));
		memset(len,0,sizeof(len));
		memset(sum,0,sizeof(sum));
		tot=1;last=0;
	}
	void insert(char c)
	{
		c-='a';
		int p=last,np=tot++;
		len[np]=len[last]+1;
		while(p!=-1&&go[p][c]==-1)
			go[p][c]=np,p=pre[p];
		if(p==-1)
			pre[np]=0;
		else
		{
			int q=go[p][c];
			if(len[p]+1==len[q])
				pre[np]=q;
			else
			{
				int nq=tot++;
				len[nq]=len[p]+1;
				for(int i=0;i<27;i++)
					go[nq][i]=go[q][i];
				pre[nq]=pre[q];
				pre[q]=pre[np]=nq;
				while(p!=-1&&go[p][c]==q)
					go[p][c]=nq,p=pre[p];
			}
		}
		last=np;
	}
	vector<int> con[maxn];
	int sum[maxn];
	int dfs(int p)
	{
		if(vis[p])return sum[p];
		vis[p]=1;
		for(int i=0;i<26;i++)
			if(go[p][i]!=-1)
				sum[p]+=dfs(go[p][i]);
		if(p)
		{
//			cout<<-len[pre[p]]+len[p]<<" "<<sum[p]<<endl;
			sum2+=1ll*(-len[pre[p]]+len[p])*sum[p]*sum[p];
		}
		return sum[p];
	}
	void calc()
	{
		memset(vis,0,sizeof(vis));
		int p=last;
		while(p!=-1)sum[p]++,p=pre[p];
		dfs(0);
	}
}sam;
char s[100111];
int main()
{
	int Tn;
	scanf("%d",&Tn);
	while(Tn--)
	{
		scanf("%s",s);
		int n=strlen(s);
	//	sam.insert('z'+1);
		sam.init();
		for(int i=0;i<n;i++)
			sam.insert(s[i]);
	//	for(int i=1;i<sam.tot;i++)cout<<sam.pre[i]<<" ";cout<<endl;
	//	for(int i=1;i<sam.tot;i++)cout<<sam.len[i]<<" ";cout<<endl;
		sum2=0;
		sam.calc();
		cout<<sum2<<endl;
	}
	return 0;
}