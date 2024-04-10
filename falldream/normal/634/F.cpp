#include<algorithm>
#include<iostream>
#include<cstdio>
#define MN 3000
#define pa pair<int,int>
using namespace std;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
int r,c,n,k,ne[MN+5],rk[MN+5],la[MN+5],top=0,q[MN+5],id[MN+5],a[MN+5],b[MN+5];
pa s[MN+5];long long ans=0;
bool cmp(int x,int y){return s[x].second<s[y].second;}

void Delete(int&tot,int x)
{
//	cout<<"Delete"<<x<<endl;
	int l=0,r=0;b[0]=a[0]=x;
	for(int t=ne[x]; t&&r<k;t=ne[t]) b[++r]=t;
	for(int t=la[x];~t&&l<k;t=la[t]) a[++l]=t;
	if(r>=k-1) tot-=(s[q[x]].second-s[q[a[1]]].second)*(c+1-s[q[b[k-1]]].second);
	if(r==k) tot+=(s[q[x]].second-s[q[a[1]]].second)*(c+1-s[q[b[k]]].second);
//	cout<<s[q[x]].second<<" "<<s[q[a[1]]].second<<" "<<
//	cout<<"after 1 = "<<tot<<endl;
	//cout<<"l="<<l<<endl;
	for(int i=1;i<=min(l-1,k-1);++i)
	{
	//	cout<<i<<" "<<s[q[a[i]]].second-s[q[a[i+1]]].second<<" "<<c+1-s[q[b[k-1-i]]].second<<" "<<c+1-s[q[b[k-0-i]]].second<<endl; 
		if(i+1+r>=k) tot-=(s[q[a[i]]].second-s[q[a[i+1]]].second)*(c+1-s[q[b[k-1-i]]].second);
		if(i+0+r>=k) tot+=(s[q[a[i]]].second-s[q[a[i+1]]].second)*(c+1-s[q[b[k-0-i]]].second);	
	}
	la[ne[x]]=la[x];ne[la[x]]=ne[x];
}

int main()
{
	r=read();c=read();n=read();k=read();
	for(int i=1;i<=n;++i) s[i].first=read(),s[i].second=read(),rk[i]=i;
	sort(s+1,s+n+1);sort(rk+1,rk+n+1,cmp);s[n+1].second=c+1;la[0]=-1;
	for(int i=1;i<=r;++i) 
	{
		top=0;
		for(int j=1;j<=n;++j) if(s[rk[j]].first>=i) q[++top]=rk[j],id[rk[j]]=top;
		int tot=0;q[top+1]=n+1;
		for(int j=1;j<=top;++j) ne[j]=j+1,la[j]=j-1;ne[0]=1;la[top+1]=top;ne[top+1]=0;
		for(int j=1;j+k-1<=top+1&&j<=top;++j) tot+=(s[q[j]].second-s[q[j-1]].second)*(c+1-s[q[j+k-1]].second);
				//	cout<<j<<" "<<q[j]<<" "<<q[j+k-1]<<" "<<tot<<endl;
		for(int j=r,l=n;j>=i;--j)
		{
			ans+=tot;
		//	cout<<i<<" "<<j<<" "<<tot<<endl;
			for(;s[l].first==j;--l) Delete(tot,id[l]);	
		}
	}
	printf("%lld\n",ans);
	return 0;
}