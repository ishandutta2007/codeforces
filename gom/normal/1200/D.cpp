#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef pair<int,ll> P;
const int N=2005;
const ll mod=1e9+7;
int n,k,a[N][N];
int s1[N],s2[N],res[N][N],sum[N][N],ans,cur;
string ss;
void Do(int sx,int sy,int ex,int ey)
{
	sx=max(sx,1); ex=max(ex,1);
	sy=max(sy,1); ey=max(ey,1);
	res[sx][sy]++;
	res[ex+1][sy]--;
	res[sx][ey+1]--;
	res[ex+1][ey+1]++;
}
int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>ss;
		for(int j=1;j<=n;j++){
			if(ss[j-1]=='B') a[i][j]=1;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++) s1[i]+=a[i][j];
	}
	for(int j=1;j<=n;j++){
		for(int i=1;i<=n;i++) s2[j]+=a[i][j];
	}
	for(int i=1;i<=n;i++){
		if(!s1[i]){
			cur++;
			continue;
		}
		int c=0,s=-1,e=-1;
		for(int j=1;j<=k-1;j++) c+=a[i][j];
		for(int j=k;j<=n;j++){
			c+=a[i][j]; c-=a[i][j-k];
			if(c==s1[i]){
				if(s==-1) s=j-k+1;
				e=j-k+1;
			}
		}
		if(s!=-1){
			Do(i-k+1,s,i,e);
		}
	}
	for(int j=1;j<=n;j++){
		if(!s2[j]){
			cur++;
			continue;
		}
		int c=0,s=-1,e=-1;
		for(int i=1;i<=k-1;i++) c+=a[i][j];
		for(int i=k;i<=n;i++){
			c+=a[i][j]; c-=a[i-k][j];
			if(c==s2[j]){
				if(s==-1) s=i-k+1;
				e=i-k+1;
			}
		}
		if(s!=-1){
			Do(s,j-k+1,e,j);
		}
	}
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) sum[i][j]=res[i][j]+sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1];
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) ans=max(ans,sum[i][j]);
	cout<<ans+cur;
    return 0;
}