#include<iostream>
#include<vector>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define MAXN 100001
int T,N,M,a[MAXN],b[MAXN],c[MAXN],ans[MAXN];vector<int>pos[MAXN];
int main()
{
	cin>>T;
	while(T--)
	{
		cin>>N>>M;For(i,1,N)cin>>a[i],pos[i].clear();For(i,1,N)cin>>b[i],b[i]!=a[i]?pos[b[i]].push_back(i),0:0;For(i,1,M)cin>>c[i];
		int x=0;if(!pos[c[M]].empty())ans[M]=x=pos[c[M]].back(),pos[c[M]].pop_back();else For(i,1,N)if(b[i]==c[M]){ans[M]=x=i;break;}if(!x){cout<<"NO\n";continue;}
		For(i,1,M-1)if(!pos[c[i]].empty())a[ans[i]=pos[c[i]].back()]=c[i],pos[c[i]].pop_back();else a[ans[i]=x]=c[i];a[x]=c[M];
		bool flag=1;For(i,1,N)if(a[i]!=b[i]){flag=0;cout<<"NO\n";break;}if(flag){cout<<"YES\n";For(i,1,M)cout<<ans[i]<<' ';cout<<endl;}
	}
	return 0;
}