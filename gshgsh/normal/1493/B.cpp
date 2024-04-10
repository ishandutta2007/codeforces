#include<iostream>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
const int mir[10]={0,1,5,-1,-1,2,-1,-1,8,-1};
int T,H,M,x,y;
bool check(int x,int y)
{
	int a=mir[x/10],b=mir[x%10],c=mir[y/10],d=mir[y%10];
	if(a==-1||b==-1||c==-1||d==-1)return 0;return d*10+c<H&&b*10+a<M;
}
int main()
{
	cin>>T;
	while(T--)
	{
		char tmp;cin>>H>>M>>x>>tmp>>y;
		while(!check(x,y))x=(x+(y+1)/M)%H,y=(y+1)%M;cout<<x/10<<x%10<<':'<<y/10<<y%10<<endl;
	}
	return 0;
}