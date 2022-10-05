#include<bits/stdc++.h>
#define For(i,a,b) for(register int i=(a);i<=(b);++i)
#define Rep(i,a,b) for(register int i=(a);i>=(b);--i)
using namespace std;
inline int read()
{
    char c=getchar();int x=0;bool f=0;
    for(;!isdigit(c);c=getchar())f^=!(c^45);
    for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
    if(f)x=-x;return x;
}
#define maxn 2505
int n,m,k;
char mp[2505][2505];
int s[2505][2505];
inline int sum(int x,int y,int xx,int yy){
	if(x>xx||y>yy)return 0;
	return s[xx][yy]-s[x-1][yy]-s[xx][y-1]+s[x-1][y-1];
}
long long res;
int mn[maxn],mx[maxn];
void solve(int x,int y,int xx,int yy)
{
	if(x==xx||y==yy)return;
	if(xx-x==1&&yy-y==1)return res+=(sum(x+1,y+1,xx,yy)==k),void();
	if(xx-x>=yy-y){
		int mid=(x+xx)>>1;
		solve(x,y,mid,yy),solve(mid,y,xx,yy);
		For(i,y+1,yy)
		{
			// mn mx:j 
			mn[0]=mx[0]=mid;
			For(j,1,k+1)mn[j]=x,mx[j]=xx;
			For(j,i,yy){
				For(t,1,k+1){
					while(sum(mn[t]+1,i,mid,j)>=t)mn[t]++;
					while(sum(mid+1,i,mx[t],j)>=t)mx[t]--; 
				}
				For(t,0,k) res+=(mn[t]-mn[t+1])*(mx[k-t+1]-mx[k-t]);
			}
		}
		return;
	}
	int mid=(y+yy)>>1;
	solve(x,mid,xx,yy),solve(x,y,xx,mid);
	For(i,x+1,xx)
	{
		mn[0]=mx[0]=mid;
		For(j,1,k+1)mn[j]=y,mx[j]=yy;
		For(j,i,xx){
			For(t,1,k+1){
				while(sum(i,mn[t]+1,j,mid)>=t)mn[t]++;
				while(sum(i,mid+1,j,mx[t])>=t)mx[t]--;
			}
			For(t,0,k)res+=(mn[t]-mn[t+1])*(mx[k-t+1]-mx[k-t]);
		}
	}
}

signed main()
{
	n=read(),m=read(),k=read();
	For(i,1,n){
		scanf("%s",mp[i]+1);
		For(j,1,m)s[i][j]=s[i-1][j]+s[i][j-1]-s[i-1][j-1]+(mp[i][j]-'0'); 
	}
	solve(0,0,n,m);
	cout<<res;
	return 0;
}