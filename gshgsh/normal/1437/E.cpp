#include<algorithm>
#include<iostream>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define lowbit(x) x&-x
#define MAXN 500001
int N,M,a[MAXN],tot,b[MAXN],f[MAXN],c[MAXN],ans; 
int get(){int x=0;char c=getchar();while(c<'0'||c>'9')c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x;}
void upd(int x,int v){for(int i=x;i<=tot;i+=lowbit(i))c[i]=max(c[i],v);}
int ask(int x){int ans=0;for(int i=x;i;i-=lowbit(i))ans=max(ans,c[i]);return ans;}
void clear(int l,int r){For(i,l,r)for(int j=a[i];j<=tot;j+=lowbit(j))c[j]=0;}
int sol(int l,int r){upd(a[l],f[l]=1);int ans=0;For(i,l+1,r)if((l==1||a[i]>=a[l])&&(r==N||a[i]<=a[r]))ans=max(ans,f[i]=ask(a[i])+1),upd(a[i],f[i]);clear(l,r);For(i,l,r)ans=max(ans,f[i]);return r-l+1-ans;}
int main()
{
	N=get(),M=get();For(i,1,N)b[++tot]=a[i]=get()-i;sort(b+1,b+tot+1);tot=unique(b+1,b+tot+1)-b-1;For(i,1,N)a[i]=lower_bound(b+1,b+tot+1,a[i])-b;
	For(i,1,M)b[i]=get();For(i,2,M)if(a[b[i]]<a[b[i-1]]){cout<<-1<<endl;return 0;}b[0]=1,b[++M]=N;
	For(i,1,M)if((b[i-1]==1&&b[i]-b[i-1]>=1)||(b[i]==N&&b[i]-b[i-1]>=1)||b[i]-b[i-1]>=2)ans+=sol(b[i-1],b[i]);cout<<ans<<endl;return 0;
}