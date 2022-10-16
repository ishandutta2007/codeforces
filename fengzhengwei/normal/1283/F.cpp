#include<bits/stdc++.h>
#define ll long long
#define re register
using namespace std;
char gc(){static char buf[1<<16],*s,*t;if(s==t){t=(s=buf)+fread(buf,1,1<<16,stdin);if(s==t)return EOF;}return *s++;}
//#define getchar gc
int read()
{
	char c;
	int w=1;
	while((c=getchar())>'9'||c<'0')if(c=='-')w=-1;
	int ans=c-'0';
	while((c=getchar())>='0'&&c<='9')ans=(ans<<1)+(ans<<3)+c-'0';
	return ans*w;
}
const int xx=2e5+5;
int n;
int vis[xx];//vis
int now;
void gn(){while(vis[now])now--;}
vector<pair<int,int> >v;
void add(int x,int y){v.push_back(make_pair(x,y));}
int main(){
	n=read();
	int root=read();
	now=n;
	vis[root]=vis[n]=1;
	if(root==n)gn(),vis[now]=1;
	int last=root;
	for(int i=2;i<n;i++)
	{
		int a=read();
		if(vis[a])add(last,now),gn(),vis[now]=1,last=a;
		else add(last,a),vis[a]=1,last=a;
	}
	add(last,now);
	cout<<root<<"\n";
	for(auto it:v)cout<<it.first<<" "<<it.second<<"\n";
	return 0;
}