#include<algorithm>
#include<iostream>
#include<cmath>
using namespace std;
#define ll long long
#define For(i,l,r) for(int i=l;i<=r;i++)
#define MAXN 100001
int N,M,Q,K,a[MAXN],cnt[1<<20];ll ans[MAXN];struct A{int l,r,id;bool operator<(A x)const{return l/M!=x.l/M?l/M<x.l/M:l/M&1?r>x.r:r<x.r;}}q[MAXN];
int main()
{
	cin>>N>>Q>>K,M=sqrt(N);For(i,1,N)cin>>a[i],a[i]^=a[i-1];For(i,1,Q)cin>>q[i].l>>q[i].r,q[i].id=i,q[i].l--;sort(q+1,q+Q+1);
	int l=1,r=0;ll res=0;For(i,1,Q){while(r<q[i].r)res+=cnt[a[++r]^K],cnt[a[r]]++;while(l>q[i].l)res+=cnt[a[--l]^K],cnt[a[l]]++;while(r>q[i].r)cnt[a[r]]--,res-=cnt[a[r--]^K];while(l<q[i].l)cnt[a[l]]--,res-=cnt[a[l++]^K];ans[q[i].id]=res;}
	For(i,1,Q)cout<<ans[i]<<endl;return 0;
}