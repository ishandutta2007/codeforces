#include<iostream>
#include<cstring>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define abs(x) ((x)>0?(x):-(x))
#define MAXN 100001
int N,M,K,a[MAXN],b[MAXN];
bool check(int x){int l=1,r=0,id=1;while(id<=K){while(r<M&&a[r+1]-a[l]+min(abs(a[r+1]-b[id]),abs(a[l]-b[id]))<=x)r++;if(r==M)return 1;l=r+1,r=l-1;id++;}return 0;}
int main()
{
	cin>>N;For(i,1,N){char c;cin>>c;if(c=='*')a[++M]=i;if(c=='P')b[++K]=i;}
	int l=1,r=N*2,ans=N*2;while(l<=r){int mid=l+r>>1;check(mid)?ans=mid,r=mid-1:l=mid+1;}cout<<ans<<endl;return 0;
}