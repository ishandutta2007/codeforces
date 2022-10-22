#include<iostream>
#include<cstring>
#define ll long long
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define MAXN 20
int T;ll a,b,f[MAXN][4];
ll get(){ll x=0;char c=getchar();while(c<'0'||c>'9')c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x;}
void put(ll x){if(x>=10)put(x/10);putchar(x%10+'0');}
ll dfs(int pos,int cnt)
{
	if(cnt>3)return 0;if(pos==1)return 1;if(f[pos][cnt]!=-1)return f[pos][cnt];
	f[pos][cnt]=0;For(i,0,9)f[pos][cnt]+=dfs(pos-1,cnt+(i!=0));return f[pos][cnt];
}
ll sol(ll x)
{
	int cnt=0,tmp[MAXN],cnt1=0;ll ans=0;while(x)tmp[++cnt]=x%10,x/=10;For(i,1,cnt-1)For(j,1,9)ans+=dfs(i,1);
	FOR(i,cnt,1){For(j,i==cnt?1:0,tmp[i]-1)ans+=dfs(i,cnt1+(j!=0));cnt1+=tmp[i]!=0;}return ans;
}
int main(){memset(f,-1,sizeof(f));T=get();while(T--)a=get(),b=get(),put(sol(b+1)-sol(a)),putchar('\n');return 0;}