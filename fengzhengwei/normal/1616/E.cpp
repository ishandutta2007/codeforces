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
	(op||((*s++=c)&&s==t))&&((fwrite(buf,1,s-buf,stdout)),s=buf);
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
const int xx=2e5+5;
int T;
char s[xx],c[xx];
int t1[29],t2[29],n;
int lb(int x){return x&-x;}
int sum[xx];
void add(int x,int y)
{
	for(;x<=n;x+=lb(x))sum[x]+=y;
}
int ask(int x)
{int ans=0;
for(;x;x-=lb(x))ans+=sum[x];return ans;
}
vector<int>v[27];
int cnt[27];
int main(){
	T=read();
	while(T--)
	{
		n=read();
		scanf("%s",s+1);
		scanf("%s",c+1);
		for(int i=0;i<26;i++)t1[i]=0;
		for(int i=0;i<26;i++)t2[i]=0;
		for(int i=1;i<=n;i++)t1[s[i]-'a']++;
		for(int i=1;i<=n;i++)t2[c[i]-'a']++;
		int op=0;
		int now=0;
		for(int i=1;i<=n;i++)sum[i]=0;
		for(int i=1;i<=n;i++)
		{
			while(!t1[now])now++;
			t1[now]--;
//			cout<<i<<" "<<now<<"!!\n";
			if(now<c[i]-'a')
			{
				op=1;
				break;
			}
			if(now>c[i]-'a')break;
		}
		for(int i=0;i<26;i++)v[i].clear();
		for(int i=0;i<26;i++)cnt[i]=0;
		for(int i=1;i<=n;i++)
			v[s[i]-'a'].push_back(i);
		if(!op)
		{
			puts("-1");
			continue;
		}
		ll ans=1e18,res=0;
		set<int>S;
		for(int i=0;i<26;i++)
		{
			if(cnt[i]!=v[i].size())
			{
				S.insert(v[i][0]);
				cnt[i]++;
			}
			else cnt[i]++;
		}
		for(int i=1;i<=n;i++)
		{
//			if(!S.size())break;
			int A=-1;
			for(auto it:S)
			{
				if(s[it]<c[i])
				{
					A=it;
					break;
				}
			}
//			*s.begin();
//			cout<<A<<"QQQ\n";
			if(A!=-1)
			ans=min(ans,res+A-ask(A)-1);
//			cout<<ans<<"Q\n";
			int id=c[i]-'a';
			if(cnt[c[i]-'a']==v[c[i]-'a'].size()+1)break;// 
			res+=v[id][cnt[id]-1]-ask(v[id][cnt[id]-1])-1;
			add(v[id][cnt[id]-1],1);
			S.erase(v[id][cnt[id]-1]);
			if(cnt[c[i]-'a']!=v[c[i]-'a'].size())
				S.insert(v[id][cnt[id]]);
			cnt[id]++;// 
		}
		cout<<ans<<"\n";
	}
	pc('1',1);
	return 0;
}