#include<bits/stdc++.h>
#define ll long long
using namespace std;
int read()
{
	char c;
	int w=1;
	while((c=getchar())>'9'||c<'0')if(c=='-')w=-1;
	int ans=c-'0';
	while((c=getchar())>='0'&&c<='9')ans=(ans<<1)+(ans<<3)+c-'0';
	return ans*w;
}
int n;
const int xx=2e5+5;
struct node
{
	int a,id;
	bool operator<(const node&w)const
	{
		return a==w.a?id<w.id:a<w.a;
	}
}e[xx];
int to[5000005];
int t[5000005];
bitset<5000005>bit1,bit2;
void check(int s)
{
	vector<int>ss;
	for(int i=1;i<=n;i++)
	{
		if(to[s-e[i].a]&&to[s-e[i].a]!=e[i].id)
		{
			ss.push_back(e[i].id);
			ss.push_back(to[s-e[i].a]);
			if(ss.size()==4)break;
		}
	}
	puts("YES");
	for(int i=0;i<ss.size();i++)cout<<ss[i]<<" ";
	exit(0);
}
signed main(){
//	freopen("a.in","r",stdin);
	n=read();
	int cnt=0;
	vector<int>v;
//	cout<<"qweqe"<<"\n";
	for(int i=1;i<=n;i++)
	{
//		cout<<i<<"\n";
		e[i].a=read();
		t[e[i].a]++;
		if(t[e[i].a]==4)
		{
			puts("YES");
			for(int j=1;j<=i;j++)
			{
				if(e[j].a==e[i].a)cout<<j<<" ";
			}
			return 0;
		}
		if(t[e[i].a]==2)cnt++,v.push_back(e[i].a);
		e[i].id=i;to[e[i].a]=i;
	}
	sort(e+1,e+n+1);
//	cout<<"qweqe"<<"\n";
	if(cnt>=2)
	{
		int x=0,y=0;
		for(int i=1;i<=n;i++)
		{
			if(e[i].a==v[0])
			{
				if(!x)x=e[i].id;
				else if(!y)y=e[i].id;
				else 
				{
					break;
				}
			}
		}
		int a=0,b=0;
		for(int i=1;i<=n;i++)
		{
			if(e[i].a==v[1])
			{
				if(!a)a=e[i].id;
				else if(!b)b=e[i].id;
				else 
				{
					break;
				}
			}
		}
		puts("YES");
		cout<<x<<" "<<a<<" "<<b<<" "<<y<<"\n";
		return 0;
	}
	if(v.size())
	{
		int sss=v[0]*2;
		for(int i=1;i<=n;i++)
		{
			if(e[i].a>=v[0])break;
			if(to[sss-e[i].a])
			{
				puts("YES");
				cout<<e[i].id<<" "<<to[sss-e[i].a]<<" ";
				int tot=0;
				for(int j=1;j<=n;j++)
				{
					if(e[j].a==v[0])
					{
						tot++;
						cout<<e[j].id<<" ";
						if(tot==2)return 0;
					}
				}
			}
		}
	}
	bit1[e[1].a]=1;
	for(int i=2;i<=n;i++)
	{
		if(e[i].a==e[i-1].a)continue;
//		cout<<bit2<<" "<<(bit1<<e[i].a)<<" "<<e[i].a<<"\n";
		if((bit2&(bit1<<e[i].a)).count())
		{
//			cout<<"qweqe"<<'\n';
			bit1=(bit2&(bit1<<e[i].a));
			int pos=0;
			for(int i=0;i<=5000004;i++)
			{
				if(bit1[i])
				{
					pos=i;
					break;
				}
			}
//			cout<<pos<<"\n";
			check(pos);
		}
		bit2|=(bit1<<e[i].a);
		bit1[e[i].a]=1;
	}
	puts("NO");
	return 0;
}