#include<iostream>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define MAXN 200001
int T,N,a[MAXN],b[MAXN];
bool check1(int x){For(i,1,N-x)if(a[i+x]<b[i])return 0;return 1;}
bool check2(int x){For(i,1,x)if(a[i]>b[N-x+i])return 0;return 1;}
int main()
{
	cin>>T;
	while(T--)
	{
		cin>>N;int M=0;For(i,1,N){cin>>a[i];For(j,a[i-1]+1,a[i]-1)b[++M]=j;}For(i,a[N]+1,N*2)b[++M]=i;
		int l=0,r=N,x=N+1;while(l<=r){int mid=l+r>>1;if(check1(mid))x=mid,r=mid-1;else l=mid+1;}
		l=0,r=N;int y=-1;while(l<=r){int mid=l+r>>1;if(check2(mid))y=mid,l=mid+1;else r=mid-1;}cout<<max(y-x+1,0)<<endl;
	}
	return 0;
}