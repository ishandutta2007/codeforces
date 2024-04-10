#include<iostream>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define MAXN 51
int T,N,M,a[MAXN][MAXN];
int get(){int x=0;char c=getchar();while(c<'0'||c>'9')c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x;}
int main()
{
    T=get();
    while(T--)
    {
        N=get(),M=get();For(i,1,N)For(j,1,M){char c;cin>>c;a[i][j]=c=='.'?2:c=='R';}
        int x=0,y=0;For(i,1,N)For(j,1,M)if(a[i][j]!=2){x=i,y=j;break;}
        if(!x&&!y){cout<<"YES\n";For(i,1,N){For(j,1,M)cout<<(i+j&1?'R':'W');cout<<endl;}continue;}
        bool flag=1;For(i,1,N)For(j,1,M)if(a[i][j]!=2&&(((i+j&1)!=(x+y&1))^(a[i][j]!=a[x][y]))){flag=0;break;}if(!flag){cout<<"NO\n";continue;}
        cout<<"YES\n";For(i,1,N){For(j,1,M)cout<<(((i+j&1)!=(x+y&1))^(a[x][y])?'R':'W');cout<<endl;}
    }
}