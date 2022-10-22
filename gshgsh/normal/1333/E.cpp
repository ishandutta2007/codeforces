#include<iostream>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define MAXN 501
int N,a[MAXN][MAXN];
int main()
{
	cin>>N;if(N<=2){cout<<-1<<endl;return 0;}
	int x=4,y=1;For(i,1,N*N-9)a[x][y]=i,max(x,y)&1?y==1?x++:x<y?x++:y--:x==1?y++:x>y?y++:x--;
	a[1][1]=N*N-8,a[1][2]=N*N-5,a[1][3]=N*N-6,a[2][1]=N*N-4,a[2][2]=N*N-7,a[2][3]=N*N-1,a[3][1]=N*N,a[3][2]=N*N-3,a[3][3]=N*N-2;
	For(i,1,N)For(j,1,N)cout<<a[i][j]<<" \n"[j==N];return 0;
}