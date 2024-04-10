#include<bits/stdc++.h>
#define ll long long
#define int long long
inline ll read(){
	char c=getchar();while (c!='-'&&(c<'0'||c>'9'))c=getchar();
	ll k=0,kk=1;if (c=='-')c=getchar(),kk=-1;
	while (c>='0'&&c<='9')k=k*10+c-'0',c=getchar();return kk*k;
}using namespace std;
void write(ll x){if (x<0)x=-x,putchar('-');if (x/10)write(x/10);putchar(x%10+'0');}
void writeln(ll x){write(x);puts("");}
const int N=20005;
int n,k,p,sum[N],dq[51][100],ans;
signed main(){
	n=read();k=read();p=read();
	for(int i=1;i<=n;i++)sum[i]=(sum[i-1]+read())%p;
	for(int i=0;i<=k;i++)for(int j=0;j<p;j++)dq[i][j]=-1e15; dq[0][0]=0;
	for(int i=1;i<=n;i++){
		dq[1][sum[i]]=sum[i];for(int j=2;j<=k;j++){
			for(int l=0;l<p;l++){
				int t=(sum[i]+p-l)%p;
				int zs=dq[j-1][l]+t;if(i==n)ans=max(ans,zs);
				dq[j][sum[i]]=max(dq[j][sum[i]],zs);
			}
		}
	}writeln(ans);
}