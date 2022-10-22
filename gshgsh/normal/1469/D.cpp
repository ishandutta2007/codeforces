#include<iostream>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define MAXN 300001
int T,N,x[MAXN],y[MAXN];
int main()
{
	cin>>T;
	while(T--)
	{
		cin>>N;int cnt=0;if(N<=10){For(i,3,N-1)x[++cnt]=i,y[cnt]=i+1;int a=N;while(a>1){a=a+1>>1;x[++cnt]=N,y[cnt]=2;}}
		else{For(i,3,7)x[++cnt]=i,y[cnt]=i+1;For(i,9,N-1)x[++cnt]=i,y[cnt]=i+1;int a=N;while(a>1){a=a+7>>3;x[++cnt]=N,y[cnt]=8;}For(i,1,3)x[++cnt]=8,y[cnt]=2;}
		cout<<cnt<<endl;For(i,1,cnt)cout<<x[i]<<' '<<y[i]<<endl;
	}
	return 0;
}