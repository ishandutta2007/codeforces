#include<bits/stdc++.h>
#define ll long long 
#define dd double
#define LL __int128
#define ull unsigned ll
using namespace std;
char gc(){static char buf[1<<16],*s,*t;if(s==t){t=(s=buf)+fread(buf,1,1<<16,stdin);if(s==t)return EOF;}return *s++;}
#define getchar gc
ll read()
{
	char c;
	ll w=1;
	while((c=getchar())>'9'||c<'0')if(c=='-')w=-1;
	ll ans=c-'0';
	while((c=getchar())>='0'&&c<='9')ans=(ans<<1)+(ans<<3)+c-'0';
	return ans*w;
}
void pc(char c,int op)
{
	static char buf[1<<16],*s=buf,*t=(buf+(1<<16));
	(op||((*s++=c)&&(s==t)))&&(fwrite(buf,1,s-buf,stdout),s=buf);
}
void wt(int x)
{
	if(x>9)wt(x/10);
	pc('0'+x%10,0);
}
void wts(int x,char op)
{
	if(x<0)pc('-',0),x=-x;
	wt(x),pc(op,0);
}
const int xx=2e5+5;
deque<int>q[2];
int d[2],op;
char s[xx],c[xx];
vector<pair<int,int> >ans;
int nid;
void in(int x,int y)
{
	d[0]-=x,d[0]+=y,d[1]+=x,d[1]-=y; 
//	cerr<<nid<<" "<<x<<" "<<y<<" "<<q[0].size()<<" "<<q[1].size()<<" "<<q[0][0]+d[0]<<" "<<q[1][1]+d[1]<<"##\n";
	if(nid)ans.push_back({y,x});else ans.push_back({x,y});
}
void rev(){swap(q[0],q[1]),swap(d[0],d[1]),nid^=1;}
void full_swap(int x,int y)
{
	if(x==y&&x==1)
	{
		in(q[0].front()+d[0],q[1].front()+d[1]);
		q[0].pop_front(),q[1].pop_front();
		return;
	}
	int cr=0;
	if(x>y)rev(),cr=1;
	assert(x<=1);
	vector<int>info;
	for(int i=0;i<y;i++)info.push_back(q[1][i]+d[1]);
	in(!x?0:q[0][x-1]+d[0],q[1][y-1]+d[1]);
	while(y--)q[1].pop_front();
	while(x--)q[0].pop_front();
	if(!q[0].size())
	{
		reverse(info.begin(),info.end());
		for(auto it:info)q[0].push_front(it-d[0]);
	}
	else 
	{
		info.pop_back();
		reverse(info.begin(),info.end());
		for(auto it:info)q[0].push_front(it-d[0]);
	}
	if(cr)rev();
}
int main(){
//	freopen("a.in","r",stdin);
//	freopen("a.out","w",stdout);
	scanf("%s",s+1),scanf("%s",c+1);
	int n=strlen(s+1),m=strlen(c+1);
	// /2  +2  
	op=s[1]!=c[1];
	for(int i=1;i<=n;i++)
		if(i==n||s[i]!=s[i+1])q[0].push_back(i);
	for(int i=1;i<=m;i++)
		if(i==m||c[i]!=c[i+1])q[1].push_back(i);
	int lim=(q[0].size()-1+q[1].size()-1+1)/2;
	while(q[0].size()>2||q[1].size()>2)
	{
		if(q[1].size()==1)swap(q[0],q[1]),swap(d[0],d[1]),nid^=1;
		if(q[0].size()==1)
		{
			if(op)
			{
				if(q[1].size()==3){full_swap(0,2);op^=1;}
				else full_swap(1,3);
			}
			else 
			{
				if(q[1].size()==3){full_swap(1,2);}
				else full_swap(0,3),op^=1;
			}
			continue;
		}
		if(op)
		{
			if(q[0].size()>2&&q[1].size()>2)full_swap(1,1);
			else 
			{
				if(q[0].size()>q[1].size())rev();
				if(q[1].size()<=3)full_swap(1,1);
				else full_swap(1,3);
			}
			continue;
		}
		else 
		{
			if(q[0].size()>q[1].size())rev();
			full_swap(1,2);
			continue;
		}
	}
	if(q[0].size()==q[1].size())
	{
		if(q[0].size()==2)
		{
			if(!op)
			{
				in(q[0].front()+d[0],0);
				q[0].pop_front();
				in(q[0].front()+d[0],q[1].front()+d[1]);
				q[0].pop_front(),q[1].pop_front();
			}
			else 
			{
				in(q[0].front()+d[0],q[1].front()+d[1]);
				q[0].pop_front(),q[1].pop_front();
			}
		}
	}
	else 
	{
		if(q[1].size()==2)swap(q[0],q[1]),swap(d[0],d[1]),nid^=1;
		if(!op)
		{
			in(q[0].front()+d[0],0);
			q[0].pop_front();
		}
		else 
		{
			in(q[0].front()+d[0],q[1].front()+d[1]);
			q[0].pop_front(),q[1].pop_front();
		}
	}
	cerr<<ans.size()<<" "<<lim<<"$$\n";
	assert((int)ans.size()<=lim+2);
	cout<<ans.size()<<"\n";
	for(auto it:ans)cout<<it.first<<" "<<it.second<<"\n";
	pc('1',1);
	return 0;
}
/*


ababab
ababab

ababa
ababa

abababa
ababab

abababab
abababa

ababab
a

abababa
a

ababab
bababa

abababa
bababab

ababab
babab

abababa
bababa

ababab
b

abababa
b


*/