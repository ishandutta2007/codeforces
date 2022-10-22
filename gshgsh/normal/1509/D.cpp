#include<iostream>
#include<vector>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define MAXN 300001
int T,N,a[MAXN],b[MAXN],c[MAXN],ans[MAXN];vector<int>val[MAXN];int get(){char c=getchar();while(c!='0'&&c!='1')c=getchar();return c-'0';}
void sol(int *a,int *b,int v)
{
	For(i,0,N)val[i].clear();int id=0;For(i,1,N*2)if(a[i]==v&&id<N)id++;else val[id].push_back(a[i]);id=0;For(i,1,N*2)if(b[i]==v&&id<N)id++;else val[id].push_back(b[i]);
	for(auto i:val[0])cout<<i;For(i,1,N){cout<<v;for(auto j:val[i])cout<<j;}cout<<endl;
}
int main()
{
	cin>>T;
	while(T--)
	{
		cin>>N;int cnt1=0,cnt2=0,cnt3=0;For(i,1,N*2)cnt1+=a[i]=get();For(i,1,N*2)cnt2+=b[i]=get();For(i,1,N*2)cnt3+=c[i]=get();
		if(cnt1>=N&&cnt2>=N)sol(a,b,1);else if(cnt1>=N&&cnt3>=N)sol(a,c,1);else if(cnt2>=N&&cnt3>=N)sol(b,c,1);
		else if(cnt1<=N&&cnt2<=N)sol(a,b,0);else if(cnt1<=N&&cnt3<=N)sol(a,c,0);else sol(b,c,0);
	}
	return 0;
}