#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,cnt[1000005],f[2][10][10],ans=0;
void upd(int &x,int y){
	x=max(x,y);
}
int main(){
	cin>>n>>m,memset(f,0xc0,sizeof(f));
	for(int i=1,x;i<=n;i++)scanf("%d",&x),cnt[x]++;
	for(int i=1;i<=m;i++)while(cnt[i]>9)cnt[i]-=3,ans++;
	f[2&1][cnt[1]][cnt[2]]=0;
	for(int i=2;i<=m;i++){
		int I=i&1,J=I^1;
		memset(f[J],0xc0,sizeof(f[J]));
		for(int j=9;j>=0;j--){
			for(int k=9;k>=0;k--){
				upd(f[J][k][cnt[i+1]],f[I][j][k]);
				if(j>=1&&k>=1&&cnt[i+1]>=1)upd(f[J][k-1][cnt[i+1]-1],f[I][j][k]+1);
				if(j>=2&&k>=2&&cnt[i+1]>=2)upd(f[J][k-2][cnt[i+1]-2],f[I][j][k]+2);
				if(k>=3)upd(f[I][j][k-3],f[I][j][k]+1);
				if(j>=3)upd(f[I][j-3][k],f[I][j][k]+1);
				if(j>=3&&k>=3)upd(f[I][j-3][k-3],f[I][j][k]+2);
			}
		}
	}
	int mx=0;
	for(int i=0;i<=9;i++)for(int j=0;j<=9;j++)mx=max(mx,f[m&1][i][j]);
	cout<<mx+ans;
	return 0;
}