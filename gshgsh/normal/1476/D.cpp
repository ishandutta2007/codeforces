#include<iostream>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--) 
#define MAXN 300001
int T,N,a[MAXN],l[MAXN][2],r[MAXN][2];
int main()
{
	cin>>T;
	while(T--)
	{
		cin>>N;For(i,1,N){char c;cin>>c;a[i]=c=='L';}For(i,0,N)l[i][0]=r[i][0]=l[i][1]=r[i][1]=i;
		For(i,1,N)l[i][0]=a[i]?l[i-1][1]:i,l[i][1]=a[i]^1?l[i-1][0]:i;FOR(i,N-1,0)r[i][0]=a[i+1]^1?r[i+1][1]:i,r[i][1]=a[i+1]?r[i+1][0]:i;
		For(i,0,N)cout<<r[i][0]-l[i][0]+1<<' ';cout<<endl;
	}
	return 0;
}