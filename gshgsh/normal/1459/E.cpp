#include<iostream>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define swap(a,b) a^=b^=a^=b
#define MAXN 1001
int T,N,M,a[MAXN][MAXN],b[MAXN][MAXN],p[3],upd[3],now[3];
int get(){int x=0;char c=getchar();while(c<'0'||c>'9')c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x;}
int getc(){char c=getchar();while(c!='R'&&c!='L'&&c!='D'&&c!='U'&&c!='I'&&c!='C')c=getchar();return c=='R'?0:c=='L'?1:c=='D'?2:c=='U'?3:c=='I'?4:5;}
void put(int x){if(x>=10)put(x/10);putchar(x%10+'0');}
int main()
{
	T=get();
	while(T--)
	{
		N=get(),M=get();For(i,0,N-1)For(j,0,N-1)a[i][j]=get()-1;For(i,0,2)p[i]=i,upd[i]=0;
		For(i,1,M){int opt=getc();opt<2?opt&1?upd[p[1]]--:upd[p[1]]++:opt<4?opt&1?upd[p[0]]--:upd[p[0]]++:opt&1?swap(p[0],p[2]):swap(p[1],p[2]);}
		For(i,0,N-1)For(j,0,N-1)now[0]=i,now[1]=j,now[2]=a[i][j],b[((now[p[0]]+upd[p[0]])%N+N)%N][((now[p[1]]+upd[p[1]])%N+N)%N]=((now[p[2]]+upd[p[2]])%N+N)%N;
		For(i,0,N-1)For(j,0,N-1)put(b[i][j]+1),putchar(j==N-1?'\n':' ');
	}
	return 0;
}