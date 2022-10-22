// Problem: G. The Awesomest Vertex
// Contest: Codeforces - Codeforces Global Round 4
// URL: https://codeforces.com/problemset/problem/1178/G
// Memory Limit: 256 MB
// Time Limit: 5000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

//And in that light,I find deliverance.
#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
using namespace std;
#define ll long long
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
int IN[200003],OUT[200003],cnt;
ll A[200003];
int B[200003],a[200003],b[200003];
vector<int> e[200003];
const int S=250;
vector<pair<int,ll>> f0[1003],f1[1003];
pair<int,ll> t[1003];
int tag[1003];
void dfs(int x)
{
	IN[x]=++cnt,A[cnt]=1ll*a[x]*b[x],B[cnt]=b[x];
	for(int y:e[x]) a[y]+=a[x],b[y]+=b[x],dfs(y);
	OUT[x]=cnt;
}
int n=read(),m=read();
void remake(int x)
{
	vector<pair<int,ll>>().swap(f0[x]),
	vector<pair<int,ll>>().swap(f1[x]);
	for(int i=0; i<S; ++i) t[i]=make_pair(B[x*S+i],A[x*S+i]);
	sort(t,t+S);
	// puts("BEFORE");
	// for(int i=0; i<S; ++i) printf("%d %lld\n",t[i].first,t[i].second);
	for(int i=0; i<S; ++i)
	{ 
		while((int)f1[x].size()>=2&&
		(__int128)1*(f1[x][(int)f1[x].size()-1].second-t[i].second)
		*(f1[x][(int)f1[x].size()-1].first-f1[x][(int)f1[x].size()-2].first)
		<=(__int128)1*(f1[x][(int)f1[x].size()-2].second-f1[x][(int)f1[x].size()-1].second)
		*(t[i].first-f1[x][(int)f1[x].size()-1].first))
		f1[x].pop_back();
		f1[x].push_back(t[i]);
		
		while((int)f0[x].size()>=2&&
		(__int128)1*(f0[x][(int)f0[x].size()-1].second-t[i].second)
		*(f0[x][(int)f0[x].size()-1].first-f0[x][(int)f0[x].size()-2].first)
		>=(__int128)1*(f0[x][(int)f0[x].size()-2].second-f0[x][(int)f0[x].size()-1].second)
		*(t[i].first-f0[x][(int)f0[x].size()-1].first))
		f0[x].pop_back();
		f0[x].push_back(t[i]);
	}
	// puts("AFTER A");
	// for(auto i:f0[x]) printf("%d %lld\n",i.first,i.second);
	// puts("AFTER B");
	// for(auto i:f1[x]) printf("%d %lld\n",i.first,i.second);
	return ;
}
ll qmin(int x)
{
    int l=0,r=(int)f0[x].size()-1;
    while(l<r)
    {
        int mid=(l+r)>>1;
        if(1ll*tag[x]*f0[x][mid].first+f0[x][mid].second
        >=1ll*tag[x]*f0[x][mid+1].first+f0[x][mid+1].second)
            l=mid+1; else r=mid;
    }
    return 1ll*tag[x]*f0[x][l].first+f0[x][l].second;
}
ll qmax(int x)
{
	int l=0,r=(int)f1[x].size()-1;
    while(l<r)
    {
        int mid=(l+r)>>1;
        if(1ll*tag[x]*f1[x][mid].first+f1[x][mid].second
        <=1ll*tag[x]*f1[x][mid+1].first+f1[x][mid+1].second)
            l=mid+1; else r=mid;
    }
	return 1ll*tag[x]*f1[x][l].first+f1[x][l].second;
}
signed main()
{
	for(int i=2; i<=n; ++i) e[read()].push_back(i);
	for(int i=1; i<=n; ++i) a[i]=read();
	for(int i=1; i<=n; ++i) b[i]=read();
	dfs(1);
	for(int i=1; i<n/S; ++i) remake(i);
	for(int op,x,l,r; m--;)
	{
		op=read(),x=read(),l=IN[x],r=OUT[x];
		if(op==1)
		{
			x=read();
			int bl=l/S,br=r/S;
			if(bl==br)
			{
				for(int i=l; i<=r; ++i) A[i]+=1ll*x*B[i];
				remake(bl);
				continue;
			}
			for(int i=bl+1; i<br; ++i) tag[i]+=x;
			for(int i=l; i<(bl+1)*S; ++i) A[i]+=1ll*x*B[i];
			remake(bl);
			for(int i=br*S; i<=r; ++i) A[i]+=1ll*x*B[i];
			remake(br);
		}
		else
		{
			ll mn=0,mx=0;
			int bl=l/S,br=r/S;
			if(bl==br)
			{
				for(int i=l; i<=r; ++i)
					(mn>A[i]+1ll*tag[bl]*B[i])&&(mn=A[i]+1ll*tag[bl]*B[i]),
					(mx<A[i]+1ll*tag[bl]*B[i])&&(mx=A[i]+1ll*tag[bl]*B[i]);
				printf("%lld\n",max(-mn,mx));
				continue;
			}
			for(int i=bl+1; i<br; ++i)
				mn=min(mn,qmin(i)),mx=max(mx,qmax(i));
			for(int i=l; i<(bl+1)*S; ++i) 
				(mn>A[i]+1ll*tag[bl]*B[i])&&(mn=A[i]+1ll*tag[bl]*B[i]),
				(mx<A[i]+1ll*tag[bl]*B[i])&&(mx=A[i]+1ll*tag[bl]*B[i]);
			for(int i=br*S; i<=r; ++i) 
				(mn>A[i]+1ll*tag[br]*B[i])&&(mn=A[i]+1ll*tag[br]*B[i]),
				(mx<A[i]+1ll*tag[br]*B[i])&&(mx=A[i]+1ll*tag[br]*B[i]);
			printf("%lld\n",max(-mn,mx));
		}
	}
	return 0;
}