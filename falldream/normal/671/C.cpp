#include<iostream>
#include<vector>
#include<cstdio>
#include<set> 
#define MN 200000
using namespace std;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
int n,a[MN+5],last[MN+5],first[MN+5],vis[MN+5],mx=0,lt=0;
vector<int> v[MN+5];long long tot=0,ans=0;
set<pair<int,int> > st;

void insert(int pos,int x)
{
	if(pos<=lt) return;
//	cout<<"Insert"<<pos<<" "<<x<<endl;
	set<pair<int,int> >::iterator it=st.lower_bound(make_pair(pos,0)),it2,it3;
//	cout<<"last = "<<it->first<<" "<<it->second<<endl;
	if(it->second>=x) return;
	int Lt=(it==st.begin()?lt:(it2=it,--it2)->first);
	tot+=((pos-Lt)*(x-it->second));
	if(it->first==pos) st.erase(it);
	st.insert(make_pair(pos,x));
	for(it=st.lower_bound(make_pair(pos,0));it!=st.begin();)
	{
		it2=it;--it2;
		if(it2->second>x) return;
		Lt=(it2==st.begin()?lt:(it3=it2,--it3)->first);
		tot+=(it2->first-Lt)*(x-it2->second);
		st.erase(it2);
	}
}

int main()
{
	n=read();
	for(int i=1;i<=MN;++i)
		for(int j=i;j<=MN;j+=i)
			v[j].push_back(i);
	for(int i=1;i<=n;++i) a[i]=read();
	for(int i=n,Mx=0;i;--i)
	{
		for(int j=0;j<v[a[i]].size();++j)
		{
			if(last[v[a[i]][j]]>i) Mx=max(Mx,v[a[i]][j]);
			last[v[a[i]][j]]=max(last[v[a[i]][j]],i);
			first[v[a[i]][j]]=i;
		}
		st.insert(make_pair(i,Mx));tot+=Mx;
	//	cout<<i<<" "<<Mx<<" "<<endl;
	}
	for(int i=0;i<n;++i)
	{
		tot-=st.begin()->second;lt=i+1;
		//cout<<i<<" find "<<st.begin()->first<<" "<<st.begin()->second<<endl;
		if(st.begin()->first<=i+1) st.erase(st.begin());
		for(int j=0;j<v[a[i]].size();++j)
		{
	//		cout<<v[a[i]][j]<<" "<<first[v[a[i]][j]]<<endl;
			if(v[a[i]][j]>mx&&i>first[v[a[i]][j]]) insert(n,mx=v[a[i]][j]); 
			if(v[a[i]][j]>mx&&last[v[a[i]][j]]>i) insert(last[v[a[i]][j]],v[a[i]][j]);
		}
		ans+=tot+mx;
	//	cout<<i<<" "<<tot<<" "<<mx<<endl;
	}
	printf("%lld\n",ans);
	return 0;
}