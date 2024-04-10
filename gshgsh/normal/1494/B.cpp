#include<iostream>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
int T,N,u,d,l,r;
int main()
{
	cin>>T;
	while(T--)
	{
		cin>>N>>u>>r>>d>>l;bool flag=0;
		For(i,0,15)
		{
			int U=u-(i&1)-((i>>1)&1),D=d-((i>>2)&1)-((i>>3)&1),L=l-(i&1)-((i>>2)&1),R=r-((i>>1)&1)-((i>>3)&1);
			if(U>=0&&U<=N-2&&D>=0&&D<=N-2&&L>=0&&L<=N-2&&R>=0&&R<=N-2){flag=1;cout<<"YES\n";break;}
		}
		if(!flag)cout<<"NO\n";
	}
	return 0;
}