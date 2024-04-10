#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<int,P> P1;
typedef pair<P,P> P2;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-7
#define INF 1000000000
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())
int n,p,q,r;
int a[500005],b[500005],c[500005];
vector<P>d[500005];
int Q[500005],R[500005];
#define s (1<<19)
int seg2[s*2]={};
ll seg[s*2]={},lazy[s*2]={};;
 
ll query(){
	seg[0]=max(seg[0],s*lazy[0]);
	lazy[1]=max(lazy[1],lazy[0]);
	lazy[2]=max(lazy[2],lazy[0]);
	lazy[0]=0;
	return seg[0];
}
ll sum(int a,int b,int k,int l,int r){
	seg[k]=max(seg[k],(r-l+1)*lazy[k]);
	if(k<s-1)
	{
		lazy[k*2+1]=max(lazy[k*2+1],lazy[k]);
		lazy[k*2+2]=max(lazy[k*2+2],lazy[k]);
	}
	lazy[k]=0;
	if(r<a || b<l || a>b) return 0LL;
	if(a<=l && r<=b)
	{
		seg[k]=max(seg[k],(r-l+1)*lazy[k]);
		if(k<s-1)
		{
			lazy[k*2+1]=max(lazy[k*2+1],lazy[k]);
			lazy[k*2+2]=max(lazy[k*2+2],lazy[k]);
		}
		lazy[k]=0;
		return seg[k];
	}
	return sum(a,b,k*2+1,l,(l+r)/2)+sum(a,b,k*2+2,(l+r)/2+1,r);
//	seg[k]=seg[k*2+1]+seg[k*2+2];
}
void update(int a,int b,int k,int l,int r,ll val)
{
	seg[k]=max(seg[k],(r-l+1)*lazy[k]);
	if(k<s-1)
	{
		lazy[k*2+1]=max(lazy[k*2+1],lazy[k]);
		lazy[k*2+2]=max(lazy[k*2+2],lazy[k]);
	}
	lazy[k]=0;
	if(r<a || b<l || a>b) return ;
	
	if(a<=l && r<=b)
	{
		lazy[k]=max(lazy[k],val);
		seg[k]=max(seg[k],(r-l+1)*lazy[k]);
		if(k<s-1)
		{
			lazy[k*2+1]=max(lazy[k*2+1],lazy[k]);
			lazy[k*2+2]=max(lazy[k*2+2],lazy[k]);
		}
		lazy[k]=0;
		return;
	}
	update(a,b,k*2+1,l,(l+r)/2,val);
	update(a,b,k*2+2,(l+r)/2+1,r,val);
	seg[k]=seg[k*2+1]+seg[k*2+2];
}
void upd(int idx,int v)
{
	idx+=s-1;
	while(idx)
	{
		seg2[idx]=max(seg2[idx],v);
		idx=(idx-1)/2;
	}
}
int calcpos(int v)
{
	int pos=0;
	while(pos<s-1)
	{
		if(seg2[pos*2+2]>v) pos=(pos*2+2);
		else pos=(pos*2+1);
	}
	return pos;
}

int main(){
	scanf("%d%d%d%d",&n,&p,&q,&r);
	for(int i=1;i<=n;i++){
		scanf("%d%d%d",&a[i],&b[i],&c[i]);
		d[a[i]].pb(mp(b[i],c[i]));
	}
	ll ret = 0;
	int MQ=0,MR=0;
	for(int i=p;i>=1;i--){
		for(int j=0;j<d[i].size();j++){
			MQ = max(MQ,d[i][j].fi);
			MR = max(MR,d[i][j].sc);
		}
		Q[i] = MQ; R[i] = MR;
	}
	for(int i=0;i<p;i++){
		for(int j=0;j<d[i].size();j++){
			int x = d[i][j].fi,y = d[i][j].sc;
			int p=calcpos(y);
			while(seg2[p]>y) p++;
			p -= (s-1);p = max(1,p);
			//[p,x]
			if(p<=x){
				update(p,x,0,0,s-1,y);
				upd(x,y);
				upd(p,y);
			}
		}
		int p = calcpos(R[i+1]); //cout << p << endl;
		while(seg2[p]>R[i+1]) p++;
		p -= (s-1);p = max(1,p);//cout << p << endl;
		if(Q[i+1]+1 < p) ret += 1LL*(q-Q[i+1])*(r-R[i+1]) - sum(Q[i+1]+1,p-1,0,0,s-1) + 1LL*(p-Q[i+1]-1)*(R[i+1]);
		else ret += 1LL*(q-Q[i+1])*(r-R[i+1]);
		//cout << max(Q[i+1]+1,p) << " " << sum(max(Q[i+1]+1,p),q,0,0,s-1) <<" " << ret <<  endl;
	}
	cout << ret << endl;
}