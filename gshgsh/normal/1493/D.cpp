#include<iostream>
#include<map>
#include<set>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define P 1000000007
#define MAXN 200001
int N,M,top,prm[MAXN],Div[MAXN],ans=1;bool Not[MAXN];multiset<int>cnt[MAXN];map<int,int>tot[MAXN];
void upd(int pos,int x)
{
	while(x!=1)
	{
		int tmp=Div[x],v=0;while(Div[x]==tmp)x/=tmp,v++;
		int lst=tot[pos][tmp];tot[pos][tmp]+=v;int mn=0;if(cnt[tmp].size()==N)mn=(*cnt[tmp].begin());if(lst)cnt[tmp].erase(cnt[tmp].find(lst));cnt[tmp].insert(lst+v);
		if(cnt[tmp].size()==N)For(i,mn+1,(*cnt[tmp].begin()))ans=1ll*ans*tmp%P;
	}
}
int main()
{
	N=MAXN-1;For(i,2,N){if(!Not[i])prm[++top]=i,Div[i]=i;for(int j=1;j<=top&&i*prm[j]<=N;j++){Not[i*prm[j]]=1,Div[i*prm[j]]=prm[j];if(i%prm[j]==0)break;}}
	cin>>N>>M;For(i,1,N){int x;cin>>x;upd(i,x);}For(i,1,M){int pos,x;cin>>pos>>x;upd(pos,x);cout<<ans<<endl;}return 0;
}