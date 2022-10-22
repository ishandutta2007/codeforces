#include<algorithm>
#include<iostream>
#include<cstdlib>
#include<vector>
#include<cstdio>
#include<ctime>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
int T,N,K;
int ask(int l,int r,int x,int y){cout<<"? "<<r-l+1<<' '<<y-x+1<<'\n';For(i,l,r)cout<<i<<" \n"[i==r];For(i,x,y)cout<<i<<" \n"[i==y];cout.flush();string s;cin>>s;return s=="FIRST"?0:s=="SECOND"?1:2;}
void solve(int l,int r){int ans=r+1;while(l<=r){int mid=l+r>>1;int x=ask(1,mid-l+1,l,mid);if(!x)ans=mid,r=mid-1;else l=mid+1;}cout<<"! "<<ans<<endl;}
int main()
{
	cin>>T;srand(time(0));
	while(T--)
	{
		cin>>N>>K;bool flag=0;
		For(i,1,20){int x=rand()%(N-1)+2;int y=ask(1,1,x,x);if(y==1){cout<<"! 1"<<'\n';cout.flush();flag=1;break;}}
		if(!flag){int r=1;while(r<N){int x=ask(1,min(r,N-r),r+1,min(N,r<<1));if(!x){solve(r+1,min(N,r<<1));break;}r=min(N,r<<1);}}cout.flush();
	}
	return 0;
}