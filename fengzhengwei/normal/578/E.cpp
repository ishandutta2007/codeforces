#include<bits/stdc++.h>
#define ll long long
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
void pc(char c,int op)
{
	static char buf[1<<16],*s=buf,*t=buf+(1<<16);
	(op||((*s++=c)&&s==t))&&(fwrite(buf,1,s-buf,stdout),s=buf);
}
void wt(int x)
{
	if(x>9)wt(x/10);
	pc('0'+x%10,0);
}
void wts(int x,char op)
{
	if(x<0)pc('-',0),x=-x;
	wt(x);pc(op,0);
}
const int xx=1e5+5;
char s[xx];
vector<int>v[xx];
queue<int>q1,q2;
vector<int>id[4];
int to[5005];
void out(int x){for(auto it:v[x])cout<<it<<" ";}
int main(){
	to['L']=0,to['R']=1;
	scanf("%s",s+1);
	int tt=0,n=strlen(s+1);
	//2R 
	for(int i=1;i<=n;i++)
	{
		if(s[i]=='L')
		{
			if(q2.size())
				v[q2.front()].push_back(i),q1.push(q2.front()),q2.pop();
			else 
				v[++tt].push_back(i),q1.push(tt);
		}
		else 
		{
			if(q1.size())
				v[q1.front()].push_back(i),q2.push(q1.front()),q1.pop();
			else 
				v[++tt].push_back(i),q2.push(tt);
		}
	}
	cout<<tt-1<<"\n";
	for(int i=1;i<=tt;i++)
	{
//		cout<<s[v[i][0]]<<" "<<s[v[i][v[i].size()-1]]<<" "<<to[s[v[i][0]]]*2+to[s[v[i][v[i].size()-1]]]<<"\n";
		id[to[s[v[i][0]]]*2+to[s[v[i][v[i].size()-1]]]].push_back(i);
	}
//	cout<<q1.size()<<" "<<q2.size()<<"!\n";
//	cout<<id[0].size()<<" "<<id[1].size()<<" "<<id[2].size()<<" "<<id[3].size()<<"\n";
	if(!id[0].size()&&!id[3].size()&&!id[2].size())
	{
		for(auto it:id[1])out(it);
		exit(0);
	}
	if(!id[0].size()&&!id[3].size()&&!id[1].size())
	{
		for(auto it:id[2])out(it);
		exit(0);
	}
	if((id[0].size()+id[3].size())&1)
	{
		if(id[0].size()>id[3].size())
		{
			for(auto it:id[1])out(it);
			for(int i=0;i<id[3].size();i++)out(id[0][i]),out(id[3][i]);
			out(id[0][id[0].size()-1]);
			for(auto it:id[2])out(it);
		}
		else 
		{
			for(auto it:id[2])out(it);
			for(int i=0;i<id[0].size();i++)out(id[3][i]),out(id[0][i]);
			out(id[3][id[3].size()-1]);
			for(auto it:id[1])out(it);
		}
		exit(0);
	}
	if(!id[0].size()&&!id[3].size())
	{
		int idl=id[1][id[1].size()-1],idr=id[2][id[2].size()-1];
		//LR                     RL
		if(*--v[idl].end()>*--v[idr].end())v[idr].push_back(*--v[idl].end()),v[idl].pop_back();
		else v[idl].push_back(*--v[idr].end()),v[idr].pop_back();
		for(int i=0;i<4;i++)id[i].clear();
		for(int i=1;i<=tt;i++)
			id[to[s[v[i][0]]]*2+to[s[v[i][v[i].size()-1]]]].push_back(i);
	}
	out(id[3][id[3].size()-1]);//RR
	for(auto it:id[1])out(it);//LR
	out(id[0][id[0].size()-1]);//LL
	for(auto it:id[2])out(it);//RL
	for(int i=0;i<id[0].size()-1;i++)out(id[3][i]),out(id[0][i]);
	pc('1',1);
	return 0;
}