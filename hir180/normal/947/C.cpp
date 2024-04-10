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
#define mod 1000000007
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
#define repn(i,x) for(int i=1;i<=x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())
int n,a[300005],b[300005];
struct node
{
	int sum;
	int vec[2];
	node()
	{
		sum = 0;
		for(int i=0;i<2;i++)
		{
			vec[i]=-1;
		}
	}
};
vector<node>nod;
void make(int id,int cur,int num,int add)
{
	nod[id].sum+=add;
	if(cur==30)
	{
		return;
	}
	int nxt=(((num>>(29-cur))&1));
	if(nod[id].vec[nxt]!=-1)
	{
		make(nod[id].vec[nxt],cur+1,num,add);
	}
	else
	{
		nod[id].vec[nxt]=nod.size();
		nod.resize(nod.size()+1);
		make(nod[id].vec[nxt],cur+1,num,add);
	}
}
int go(int id,int cur,int num,int val)
{
    //if(id == 0) cout<<nod[id].sum<<endl;
	if(cur==30)
	{
		return val;
	}
	int nxt=(((num>>(29-cur))&1)); //cout<<nxt;
	if(nod[id].vec[nxt] != -1 && nod[nod[id].vec[nxt]].sum != 0)
	{
		return go(nod[id].vec[nxt],cur+1,num,val*2+0);
	}
	else
	{
	    //assert(nod[id].vec[1-nxt] != -1);
		return go(nod[id].vec[1-nxt],cur+1,num,val*2+1);
	}
}
int main(){
	scanf("%d",&n); nod.pb(node());
	rep(i,n) scanf("%d",&a[i]);
	rep(i,n){
	    scanf("%d",&b[i]); 
		make(0,0,b[i],1);
	}
	rep(i,n){
		int get_val = go(0,0,a[i],0);
		printf("%d ",get_val);
		make(0,0,(a[i]^get_val),-1);
	}
	puts("");
}