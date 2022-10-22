#include<algorithm>
#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define MAXN 1000001
int T,N,a[MAXN],b[MAXN],cnt[MAXN];vector<int>sta[MAXN];vector<pair<int,int>>ans;vector<int>ssh;
int get(){int x=0,f=1;char c=getchar();while(c<'0'||c>'9')c=='-'&&(f=-1),c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x*f;}
void opt(int x,int y){ans.push_back({x,b[y]});}
int solve(int l,int r)
{
	//cout<<"solve "<<l<<' '<<r<<'\n';
	For(i,l+1,r-1)opt(r+i-l-1,a[i]);ssh.push_back(r-l<<1);int k=r-l-1;
	//cout<<"r= "<<r<<' '<<"k= "<<k<<'\n';
	//cout<<"-------\n";
	vector<int>ins;For(i,l+1,r-1)ins.push_back(a[i]);
	//cout<<ins.size()<<'\n';
	FOR(i,N,r+1)a[i+k*2]=a[i];N+=k*2;int j=0;FOR(i,r+k*2,r+k+1)a[i]=ins[j++];
	//cout<<"array: ";For(i,r+k+1,N)cout<<a[i]<<' ';cout<<'\n';
	return r+r-l;
}
int main()
{
	T=get();
	while(T--)
	{
		N=get();For(i,1,N)a[i]=get(),b[i]=a[i];sort(b+1,b+N+1);
		int K=unique(b+1,b+N+1)-b-1;For(i,1,N)a[i]=lower_bound(b+1,b+K+1,a[i])-b;
		For(i,1,K)cnt[i]=0;For(i,1,N)cnt[a[i]]++;bool flag=1;For(i,1,K)if(cnt[i]&1){flag=0;break;}if(!flag){cout<<"-1\n";continue;}
		ans.clear();int pre=1;ssh.clear();
		while(pre<=N)
		{
			For(i,pre+1,N)if(a[i]==a[pre]){pre=solve(pre,i);break;}
			//cout<<"pre= "<<pre<<'\n';
		}
		cout<<ans.size()<<'\n';
		for(auto i:ans)cout<<i.first<<' '<<i.second<<'\n';
		cout<<ssh.size()<<'\n';
		for(auto i:ssh)cout<<i<<' ';cout<<'\n';
	}
}