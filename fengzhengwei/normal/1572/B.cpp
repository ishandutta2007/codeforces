#include<bits/stdc++.h>
#define ll long long
#define dd double
using namespace std;
char gc(){static char buf[1<<16],*s,*t;if(s==t){t=(s=buf)+fread(buf,1,1<<16,stdin);if(s==t)return EOF;}return *s++;}
//#define getchar gc
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
const int xx=2e5+5;
int a[xx],sum[xx];
vector<int>ans;
void ap(int x){ans.push_back(x);a[x]=a[x+1]=a[x+2]=(a[x]^a[x+1]^a[x+2]);}
int main(){
	int T=read();
	while(T--)
	{
		int n=read();
		for(int i=1;i<=n;i++)a[i]=read(),sum[i]=sum[i-1]+a[i];
		if(sum[n]&1){puts("NO");continue;}
		int cr=0,id=0;
		for(int i=1;i<=n;i++)
		{
			if(a[i]==0)
			{
				if((sum[i]&1)==0)
				{
					cr=1,id=i;
					break;
				}
			}
		}
		ans.clear();
		if(!cr)
		{
			int lst=-1;
			for(int i=1;i<=n;i++)
			{
				if(a[i])
				{
//					cout<<i<<" "<<lst<<" "<<((i-lst)%2==0)<<" "<<(lst!=-1)<<"!!!\n";
					if(lst!=-1&&(i-lst)%2==0)
					{
//						puts("SSS");
						for(int j=lst;j<i;j+=2)ap(j);
						break;
					}
				}
				if(a[i])lst=i;
			}
		}
		if(!cr)
		{
		for(int i=1;i<=n;i++)sum[i]=sum[i-1]+a[i];
			for(int i=1;i<=n-2;i++)
			{
				if(a[i]==0)
				{
					if((sum[i]&1)==0)
					{
						cr=1,id=i;
						break;
					}
				}
			}
		}
		if(!cr){puts("NO");continue;}
		puts("YES");
		for(int i=id;i<=n;i++)
		{
			if(!a[i+1])continue;
			if(a[i+1]==a[i+2])ap(i);
			else ap(i+1),i--;
		}
		for(int i=id;i>=1;i--)
		{
			if(!a[i-1])continue;
			if(a[i-1]==a[i-2])ap(i-2);
			else ap(i-3),i++;
		}
		cout<<ans.size()<<"\n";
		for(auto it:ans)cout<<it<<" ";
		puts("");
	}
	pc('1',1);
	return 0;
}