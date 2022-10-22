#include<iostream>
#include<string>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
int T,x,y,c1,c2,c3,c4,c5,c6;
int main()
{
	cin>>T;
	while(T--)
	{
		cin>>x>>y>>c1>>c2>>c3>>c4>>c5>>c6;
		For(j,1,10)c1=min(c1,c2+c6),c2=min(c2,c1+c3),c3=min(c3,c2+c4),c4=min(c4,c3+c5),c5=min(c5,c4+c6),c6=min(c6,c1+c5);
		if(!x&&!y){cout<<"0\n";continue;}if(!x){cout<<(y>0?1ll*c2*y:-1ll*c5*y)<<endl;continue;}if(!y){cout<<(x>0?1ll*c6*x:-1ll*c3*x)<<endl;continue;}
		if(x>0&&y<0){cout<<1ll*c6*x-1ll*c5*y<<endl;continue;}if(x<0&&y>0){cout<<1ll*c2*y-1ll*c3*x<<endl;continue;}
		if(x>0){cout<<1ll*c1*min(x,y)+(x>y?1ll*c6*(x-y):1ll*c2*(y-x))<<endl;continue;}
		cout<<-1ll*c4*max(x,y)+(x<y?1ll*c3*(y-x):1ll*c5*(x-y))<<endl;
	}
	return 0;
}