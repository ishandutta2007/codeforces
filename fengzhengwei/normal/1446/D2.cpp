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
vector<int>v[xx];
int t[xx];
int maxx;
struct nod
{
	int col,size;
	bool operator<(const nod&w)const{return size>w.size;}
}s[xx];
int a[xx];
int minn[xx<<1];
int c(int x){return x+xx;}
signed main(){
	n=read();
	for(int i=1;i<=n;i++)
	{
		a[i]=read();
		t[a[i]]++;
		maxx=max(maxx,t[a[i]]);
		v[a[i]].push_back(i);
	}
	int op=-1;
	for(int i=1;i<=n;i++)
	{
		s[i].col=i;
		s[i].size=t[i];
		if(maxx==t[i])
		{
			if(op!=-1)return cout<<n<<"\n",0;
			op=i;
		}
	}
	sort(s+1,s+n+1);
	int b=sqrt(n);
	int ans=0;
	memset(minn,0x7f,sizeof(minn));
	for(int i=1;i<=n;i++)
	{
		if(s[i].col==op)continue;
		if(s[i].size>=b)//bb 
		{
			int opt=0;
			minn[c(opt)]=0;
			for(int j=1;j<=n;j++)
			{
				opt+=(a[j]==op);
				opt-=(a[j]==s[i].col);
				minn[c(opt)]=min(minn[c(opt)],j);
				ans=max(ans,j-minn[c(opt)]);
			}
			opt=0;
			minn[c(opt)]=2147483647;
			for(int j=1;j<=n;j++)
			{
				opt+=(a[j]==op);
				opt-=(a[j]==s[i].col);
				minn[c(opt)]=2147483647;
			}
		}
	}
	for(int i=1;i<=b;i++)
	{
		memset(t,0,sizeof(t));
		int rpos=1;
		int now=0;
		for(int lpos=1;lpos<=n;lpos++)
		{
			while(rpos<=n&&t[op]+(a[rpos]==op)<=i)
			{
				now-=(t[a[rpos]]==i);
				t[a[rpos]]++;
				now+=(t[a[rpos]]==i);
				rpos++;
				if(now>=2&&t[op]==i)ans=max(ans,rpos-lpos);
			}
			now-=(t[a[lpos]]==i);
//			if(i==2)cout<<t[a[lpos]]<<" "<<now<<"\n";
			t[a[lpos]]--;
			now+=(t[a[lpos]]==i);
			if(now>=2&&t[op]==i)ans=max(ans,rpos-lpos);
//			if(i==2)cout<<lpos<<" "<<rpos<<" "<<now<<"\n";
		}
	}
	cout<<ans<<"\n";
	return 0;
}