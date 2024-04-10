#include<bits/stdc++.h>
#define pb push_back
#define SZ(x) ((int)x.size())
#define lowbit(x) ((x)&(-(x)))
const int N=100005;typedef long long ll;
char s[N],t[N];
struct BIT{
	int c[N],lim;
	void add(int x,int C){for(;x<=lim+1;x+=lowbit(x))c[x]+=C;}
	int ask(int x){int ans=0;for(;x;x-=lowbit(x))ans+=c[x];return ans;}
	int get1(int L){
		int l=1,r=lim+1,mid;
		while(l<r)mid=(l+r)>>1,ask(mid)>=L?r=mid:l=mid+1;
		return l;
	}
	int get2(int R){
		int l=0,r=lim+1,mid;
		while(l<r)mid=(l+r+1)>>1,ask(mid)<=R?l=mid:r=mid-1;
		return l;
	}
}tr[26];
std::vector<int> pos[26];int NXT[26];
void MAIN(){
	int n;scanf("%d%s%s",&n,s+1,t+1);
	for(int i=0;i<26;++i)pos[i].clear();
	for(int i=1;i<=n;++i)pos[s[i]-'a'].pb(i);
	for(int i=0;i<26;++i){
		tr[i].lim=SZ(pos[i]),memset(tr[i].c,0,(SZ(pos[i])+3)<<2);
		int c=0;for(auto it:pos[i])tr[i].add(++c,it),tr[i].add(c+1,-it);
		tr[i].add(SZ(pos[i])+1,1e9);
	}
	ll ans=1e18,cur=0;
	for(int i=1;i<=n;++i){
		int v=-1;for(int j=0;j<26;++j)NXT[j]=tr[j].get1(i);
		for(int j=0;j<26;++j)if(tr[j].ask(NXT[j])==i)v=j;
		for(int j=0;j<t[i]-'a';++j){
			int k=tr[j].ask(NXT[j]);
			if(k<=n)ans=std::min(ans,cur+k-i);
		}
		if(v+'a'==t[i])continue;
		int tmp=t[i]-'a',qwq=NXT[tmp],to=tr[tmp].ask(qwq);
		if(to>n)break;
		cur+=to-i;int pre=tr[tmp].ask(qwq-1);
		tr[tmp].add(qwq,pre-to),tr[tmp].add(qwq+1,to-pre);
		for(int j=0;j<26;++j)if(j!=tmp){
			int L=NXT[j],R=tr[j].get2(to);
			tr[j].add(L,1),tr[j].add(R+1,-1);
		}
	}
	printf("%lld\n",ans>=1e18?-1:ans);
}
int main(){
	int _;scanf("%d",&_);
	while(_--)MAIN();
	return 0;
}