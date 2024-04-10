#include<bits/stdc++.h>
#define ll long long
#define dd double
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
int len[18];
ll pw(ll a){return a*a;}
const int mod=998244353,base=2011111;
ll N[xx],P[xx],sum[xx],cf[xx];
ll ksm(ll a,ll b)
{
	ll ans=1;
	while(b)
	{
		if(b&1)ans*=a,ans%=mod;
		a*=a,a%=mod,b>>=1;
	}
	return ans;
}
ll get(ll l,ll r){return (sum[r]-sum[l-1]+mod)*N[l]%mod;}
bool cr[xx][18];
int t[26][xx];
ll val[xx][26];
int check(int l,int r,int a,int b)
{
	int len=r-l+1,L=1,R=len,ans=0;
	
	while(L<=R)
	{
		int mid=L+R>>1;
		if(get(l,l+mid-1)==get(a,a+mid-1))ans=mid,L=mid+1;
		else R=mid-1;
	}
//	cout<<l<<" "<<r<<" "<<a<<" "<<b<<" "<<ans<<"!!\n";
	if(get(r-(len-ans-1)+1,r)==get(b-(len-ans-1)+1,b))return ans+1;
	
	return -1;
}
int main(){
	P[0]=N[0]=1,P[1]=base,N[1]=ksm(base,mod-2);
	for(int i=1;i<xx;i++)P[i]=P[i-1]*P[1]%mod;
	for(int i=1;i<xx;i++)N[i]=N[i-1]*N[1]%mod;
	len[0]=1;
	for(int i=1;i<=16;i++)len[i]=len[i-1]*2+1;
	scanf("%s",s+1);
	int n=strlen(s+1);
	for(int i=0;i<26;i++)
		for(int j=1;j<=n;j++)
			t[i][j]+=t[i][j-1],t[i][j]+=(s[j]==(i+'a'));
	for(int i=1;i<=n;i++)sum[i]=(sum[i-1]+s[i]*P[i])%mod;
	ll ans=0,re=0;
	for(int i=1;i<=n;i++)
	{
		cr[i][0]=1;
		//=0+n 
		for(int j=1;j<=17;j++)
		{
			if(i<len[j])break;
			int l=i-len[j]+1,r=i,mid=l+r>>1;
			int Deng=(get(l,mid-1)==get(mid+1,r));
			if(cr[i][j-1]&&cr[mid-1][j-1]&&t[s[mid]-'a'][r]-t[s[mid]-'a'][l-1]==1&&Deng)
				cf[l]+=pw(len[j]),cf[r+1]-=pw(len[j]),re+=pw(len[j]),cr[i][j]=1;
			if(!cr[i][j-1]&&!cr[mid-1][j-1])continue;
			if(cr[i][j-1]&&cr[mid-1][j-1]&&Deng)// 
			{
				for(int k=0;k<26;k++)
					if(t[k][r]-t[k][l-1]==0)val[mid][k]+=pw(len[j]);
			}
			int Mid=s[mid]-'a';
			// aab
			if(!Deng&&cr[i][j-1]&&cr[mid-1][j-1])
			{
				int id=check(l,mid-1,mid+1,r);
//				puts("ASDSAD");
//				cout<<id<<" "<<l<<" "<<mid<<" "<<r<<"!!\n";
				if(id!=-1)
				{
					if(t[Mid][mid]-t[Mid][l-1]==1)
						val[mid+1+id-1][s[l+id-1]-'a']+=pw(len[j]);
					if(t[Mid][r]-t[Mid][mid-1]==1)
						val[l+id-1][s[mid+1+id-1]-'a']+=pw(len[j]);
				}
			}
			if(cr[mid-1][j-1]&&!cr[i][j-1])
			{
				int id=check(l,mid-1,mid+1,r);
				if(id!=-1)
				{
					if(t[Mid][mid]-t[Mid][l-1]==1)
						val[mid+1+id-1][s[l+id-1]-'a']+=pw(len[j]);
				}
			}
			if(cr[i][j-1]&&!cr[mid-1][j-1])
			{
				int id=check(l,mid-1,mid+1,r);
				if(id!=-1)
				{
					if(t[Mid][r]-t[Mid][mid-1]==1)
						val[l+id-1][s[mid+1+id-1]-'a']+=pw(len[j]);
				}
			}
		}
	}
	ans=re;
	for(int i=1;i<=n;i++)cf[i]+=cf[i-1];
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<26;j++)
		{
			if(s[i]-'a'==j)continue;
			ans=max(ans,re-cf[i]+val[i][j]);
		}
	}
	cout<<ans+n<<"\n";
	pc('1',1);
	return 0;
}