#include<algorithm>
#include<iostream>
#include<cmath>
using namespace std;
#define ll long long
#define For(i,l,r) for(int i=l;i<=r;i++)
#define MAXN 200001
#define MAXM 1000001
int N,M,a[MAXN],cnt[MAXM];ll ans[MAXN];struct Q{int l,r,id,in;bool operator<(Q a)const{return in!=a.in?in<a.in:in&1?r<a.r:r>a.r;}}q[MAXN];
int main()
{
	cin>>N>>M;For(i,1,N)cin>>a[i];int siz=sqrt(M);For(i,1,M)cin>>q[i].l>>q[i].r,q[i].id=i,q[i].in=q[i].l/siz;sort(q+1,q+M+1);int l=1,r=0;ll res=0;
	For(i,1,M)
	{
		while(r<q[i].r)res+=1ll*a[++r]*(2*(cnt[a[r]]++)+1);while(r>q[i].r)res-=1ll*a[r]*(2*(--cnt[a[r--]])+1);
		while(l>q[i].l)res+=1ll*a[--l]*(2*(cnt[a[l]]++)+1);while(l<q[i].l)res-=1ll*a[l]*(2*(--cnt[a[l++]])+1);ans[q[i].id]=res;
	}
	For(i,1,M)cout<<ans[i]<<endl;return 0;
}