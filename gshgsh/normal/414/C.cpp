#include<iostream>
#include<cstdio>
using namespace std;
#define ll long long
#define For(i,l,r) for(int i=l;i<=r;i++)
#define MAXN 20
int N,M,a[1<<MAXN],b[1<<MAXN];ll ans[MAXN][2];
int get(){int x=0;char c=getchar();while(c<'0'||c>'9')c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x;}
void msort(int l,int r,int dep)
{
	if(!dep)return;int mid=l+r>>1;msort(l,mid,dep-1),msort(mid+1,r,dep-1);
	int i=l,j=mid+1,k=l,cnt=0;while(i<=mid&&j<=r)a[i]>a[j]?ans[dep-1][0]+=mid-i+1,j++:i++;
	i=l,j=mid+1,k=l,cnt=0;while(i<=mid&&j<=r)a[i]<a[j]?ans[dep-1][1]+=r-j+1,b[k++]=a[i++]:b[k++]=a[j++];
	while(i<=mid)b[k++]=a[i++];while(j<=r)b[k++]=a[j++];For(i,l,r)a[i]=b[i];
}
int main()
{
	N=get();For(i,0,(1<<N)-1)a[i]=get();msort(0,(1<<N)-1,N);
	M=get();For(i,1,M){int x=get();For(j,0,x-1)swap(ans[j][0],ans[j][1]);ll sum=0;For(j,0,N-1)sum+=ans[j][0];cout<<sum<<endl;}return 0;
}