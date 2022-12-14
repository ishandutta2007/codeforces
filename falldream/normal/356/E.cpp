#include<bits/stdc++.h>
#define MN 100000
#define mod 1004585309
using namespace std;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
char s[MN+5];
int n,ok[18][MN+5],num[26][MN+5],ha[MN+5],pw[MN+5];
long long f[MN+5][26],ans,sum[MN+5];
int GetH(int l,int r){return (ha[r]-1LL*ha[l-1]*pw[r-l+1]%mod+mod)%mod;}
int lcp(int x,int y)
{
	int l=1,r=n-y+1,mid,res=0;
	while(l<=r)
	{
		mid=l+r>>1;
		if(GetH(x,x+mid-1)==GetH(y,y+mid-1)) res=mid,l=mid+1;
		else r=mid-1;	
	}
	return res;
}
int main()
{
	scanf("%s",s+1);n=strlen(s+1);pw[0]=1;
	for(int i=1;i<=n;++i) ok[0][i]=1,pw[i]=37LL*pw[i-1]%mod,ha[i]=(37LL*ha[i-1]+s[i])%mod;
	for(int j=0;j<26;++j) for(int i=1;i<=n;++i) num[j][i]=num[j][i-1]+(s[i]-'a'==j);
	for(int len=3,k=1;len<=n;len=len*2+1,++k)
		for(int i=1;i+len-1<=n;++i)
		{
			int l=i,r=i+len-1,mid=i+(len/2);
			if(!ok[k-1][i]&&!ok[k-1][mid+1]) continue;
		//	cout<<l<<" "<<mid<<" "<<r<<endl;
			if(GetH(l,mid-1)==GetH(mid+1,r))
			{
			//	cout<<"???"<<" "<<ok[k-1][i]<<" "<<ok[k-1][mid+1]<<endl;
				if(ok[k-1][i]&&ok[k-1][mid+1]&&num[s[mid]-'a'][r]-num[s[mid]-'a'][l-1]==1) 
					ok[k][i]=1,sum[1]+=1LL*len*len,sum[l]-=1LL*len*len,sum[r+1]+=1LL*len*len;
				for(int k=0;k<26;++k)
				{
					if(num[k][r]-num[k][l-1]<=(s[mid]-'a'==k))
						f[mid][k]+=1LL*len*len;
				}
			}
			else
			{
				int P=lcp(l,mid+1);
			//	cout<<"lcp="<<P<<endl;
				if(P<len/2-1&&P+1+lcp(l+P+1,mid+1+P+1)<len/2) continue;
			//	cout<<"get??"<<endl;
				if(ok[k-1][mid+1])
				{
					int pre=s[l+P];
					if(num[s[mid]-'a'][r]-num[s[mid]-'a'][l-1]-(pre==s[mid])==1) 
				//	cout<<l+P<<" "<<s[mid+1+P]<<" += "<<len*len<<endl;
						f[l+P][s[mid+1+P]-'a']+=1LL*len*len;
				}
				if(ok[k-1][l])
				{
					int pre=s[mid+1+P];
					if(num[s[mid]-'a'][r]-num[s[mid]-'a'][l-1]-(pre==s[mid])==1)
				//	cout<<mid+1+P<<" "<<s[l+P]<<" += "<<len*len<<endl;
						f[mid+1+P][s[l+P]-'a']+=1LL*len*len;	
				}
			}
		}
	for(int i=1;i<=n;++i) 
	{
		sum[i]+=sum[i-1];
		for(int j=0;j<26;++j) ans=max(ans,sum[i]+f[i][j]);
	}
	printf("%lld\n",ans+n);
	return 0;
}