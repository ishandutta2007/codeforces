#include<algorithm>
#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
const int tot=10,v[11]={0,2,3,5,7,11,13,17,19,23,29};
int get(){int x=0,f=1;char c=getchar();while(c<'0'||c>'9')c=='-'&&(f=-1),c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x*f;}
int main()
{
	int T=get();
	while(T--){int N=get();For(i,1,tot)if(N-1>=v[i]+2&&(N-1)%v[i]){cout<<N-1-v[i]<<' '<<v[i]<<" 1\n";break;}}
}