#include<cstdio>
#include<cstring>
#include<stack>
using namespace std;
const int MAXN = 5e2 + 5;

inline void chk_max(int &a,int b){ if(a<b) a=b;}

int n;
char s[MAXN];
int nxt[MAXN];

int ans=0,al=1,ar=1;
stack<int> sta;
void solve(int l,int r)
{
	memset(nxt,0,sizeof(nxt));
	while(!sta.empty()) sta.pop();
	int res=0;
	
	sta.push(0);
	for(int i=1; i<=n; ++i)
	{
		if(s[i]=='(') sta.push(i);
		else
		{
			if(sta.top()>0)
			{
				nxt[sta.top()]=i;
				sta.pop();
			}
			else sta.push(-i);
		}
	}
	
	int cnt=0, frm=0,to=n+1;
	while(sta.top()>0)
	{
		to=sta.top();
		++cnt;
		sta.pop();
	}
	frm=-sta.top();
	if((int)sta.size()-1 != cnt) return;
	
	if(frm) res=1;
	for(int i=frm+1; i<to; i=nxt[i]+1)
		++res;
	
	if(ans<res) ans=res, al=l, ar=r;
}


int main(void)
{
	scanf("%d%s",&n,s+1);
	
	solve(1,1);
	for(int i=1; i<=n; ++i)
		for(int j=i+1; j<=n; ++j)
		{
			swap(s[i],s[j]);
			solve(i,j);
			swap(s[i],s[j]);
		}
	
	printf("%d\n%d %d",ans,al,ar);
	return 0;
}