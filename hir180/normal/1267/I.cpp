#include <bits/stdc++.h>
#define SIZE 205
using namespace std;
typedef pair <int,int> P;

int memo[SIZE][SIZE];
char str[SIZE];
bool zan[SIZE];
int ord[SIZE];
int n;

void make()
{
	n=100;
	for(int i=0;i<2*n;i++) ord[i]=i;
	random_shuffle(ord,ord+2*n);
}
bool ask(int i,int j)//true if Ai<Aj 
{
	//return ord[i]<ord[j];
	
	if(memo[i][j]!=-1) return memo[i][j];
	printf("? %d %d\n",i+1,j+1);
	fflush(stdout);
	scanf("%s",&str);
	if(str[0]=='<') memo[i][j]=1,memo[j][i]=0;
	else memo[i][j]=0,memo[j][i]=1;
	return memo[i][j];
}
void solve()
{
	//make();
	scanf("%d",&n);
	for(int i=0;i<2*n;i++) for(int j=0;j<2*n;j++) memo[i][j]=-1;
	P p=P(0,1),q=P(2,3),r=P(4,5);
	if(ask(p.first,p.second)) swap(p.first,p.second);
	if(ask(q.first,q.second)) swap(q.first,q.second);
	if(ask(r.first,r.second)) swap(r.first,r.second);
	//f>s
	if(ask(p.second,q.second)) swap(p,q);
	if(ask(p.second,r.second)) swap(p,r);
	if(ask(q.first,r.first)) swap(q,r);
	//p.s : max , q.f > r.f
	vector <int> ans{p.first,q.first};
	int mx;
	if(ask(p.second,r.first)) ans.push_back(r.first),mx=q.first;
	else ans.push_back(p.second),mx=p.first;
	for(int i=3;i<n;i++)
	{
		int f=2*i,s=2*i+1;
		if(ask(f,s)) swap(f,s);
		//f>s
		bool up=false;
		for(int j=0;j<ans.size();j++)
		{
			if(ans[j]==mx) continue;
			if(ask(ans[j],s))
			{
				up=true;
				break;
			}
		}
		if(!up)
		{
			for(int j=0;j<2*i;j++) zan[j]=true;
			for(int j=0;j<ans.size();j++) zan[ans[j]]=false;
			for(int j=0;j<2*i;j++) if(zan[j]&&ask(f,j)) f=j;
			ans.push_back(f);
		}
		else
		{
			vector <int> na{mx,f};
			int mn=s;
			for(int j=0;j<ans.size();j++)
			{
				if(ans[j]==mx) continue;
				if(ask(mn,ans[j])) na.push_back(ans[j]);
				else
				{
					na.push_back(mn);
					mn=ans[j];
				}
			}
			ans=na;
			mx=f;
		}
	//	printf("%d\n",mx);
	//	for(int j=0;j<ans.size();j++) printf("%d ",ans[j]);puts("");
	}
	vector <int> vx;
	for(int i=0;i<n;i++) vx.push_back(ord[ans[i]]);
	sort(vx.begin(),vx.end());
	//printf("%d %d\n",vx[0],vx[n-1]);
	puts("!");
	fflush(stdout);
}
int main()
{
	//srand((unsigned) time(NULL));
	int T;
	scanf("%d",&T);
	//T=100;
	while(T--) solve();
	return 0;
}