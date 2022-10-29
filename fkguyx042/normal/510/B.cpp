#include<cstdio>  
#include<cstring>  
#include<cstdlib>  
#include<algorithm>  
#include<functional>  
#include<iostream>  
#include<cmath>  
#include<cctype>  
#include<ctime>  
using namespace std;  
#define For(i,n) for(int i=1;i<=n;i++)  
#define Fork(i,k,n) for(int i=k;i<=n;i++)  
#define Rep(i,n) for(int i=0;i<n;i++)  
#define ForD(i,n) for(int i=n;i;i--)  
#define RepD(i,n) for(int i=n;i>=0;i--)  
#define Forp(x) for(int p=pre[x];p;p=next[p])  
#define Forpiter(x) for(int &p=iter[x];p;p=next[p])    
#define Lson (x<<1)  
#define Rson ((x<<1)+1)  
#define MEM(a) memset(a,0,sizeof(a));  
#define MEMI(a) memset(a,127,sizeof(a));  
#define MEMi(a) memset(a,128,sizeof(a));  
#define INF (2139062143)  
#define F (100000007)  
#define MAXN (50+10)  
long long mul(long long a,long long b){return (a*b)%F;}  
long long add(long long a,long long b){return (a+b)%F;}  
long long sub(long long a,long long b){return (a-b+(a-b)/F*F+F)%F;}  
typedef long long ll;  
int n,m;  
char a[MAXN][MAXN];  
bool b[MAXN][MAXN]={0};  
bool dfs(int i,int j,int t)  
{  
    if (b[i][j]==1) return 1;   
    b[i][j]=1;  
    if (a[i][j]==a[i-1][j]&&t!=2) if (dfs(i-1,j,1)) return 1;  
    if (a[i][j]==a[i+1][j]&&t!=1) if (dfs(i+1,j,2)) return 1;  
    if (a[i][j]==a[i][j-1]&&t!=4) if (dfs(i,j-1,3)) return 1;  
    if (a[i][j]==a[i][j+1]&&t!=3) if (dfs(i,j+1,4)) return 1;  
      
      
  
      
    return 0;  
}  
int main()  
{  
//  freopen("Dots.in","r",stdin);  
//  freopen(".out","w",stdout);  
    MEM(a)  
    cin>>n>>m;  
    For(i,n) scanf("%s",a[i]+1);  
      
      
    For(i,n) For(j,m)  
    {  
        if (!b[i][j])  
        {  
            if (dfs(i,j,0))   
            {  
                cout<<"Yes"<<endl;  
                return 0;  
            }             
        }  
    }  
    cout<<"No"<<endl;  
      
    return 0;  
}