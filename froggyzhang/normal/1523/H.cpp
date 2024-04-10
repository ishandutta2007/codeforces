#include<bits/stdc++.h>
using namespace std;
#define N 20020
typedef long long ll;
inline ll read(){
	ll x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=(x<<1)+(x<<3)+c-'0';
		c=getchar();
	}
	return x*f;
}
int n,Q,a[N],lg[N];
int f[31][17][N];
pair<int,int> st[N][17];
inline pair<int,int> Query(int l,int r){
	int k=lg[r-l+1];
	return max(st[l][k],st[r-(1<<k)+1][k]);
}
int main(){
	n=read(),Q=read();
	for(int i=1;i<=n;++i){
		a[i]=read();
		st[i][0]=make_pair(min(n,a[i]+i),i);
	}
	for(int i=2;i<=n;++i){
		lg[i]=lg[i>>1]+1;
	}
	for(int j=1;j<=16;++j){
		for(int i=1;i+(1<<j)-1<=n;++i){
			st[i][j]=max(st[i][j-1],st[i+(1<<j-1)][j-1]);
		}
	}
	for(int i=1;i<=n;++i){
		for(int k=0;k<=30;++k){
			f[k][0][i]=Query(i+1,min(n,i+a[i]+k)).second;
		}	
	}
	for(int j=1;j<=16;++j){
		for(int i=1;i<=n;++i){
			for(int k=0;k<=30;++k){
				f[k][j][i]=i;
				for(int p=0;p<=k;++p){
					f[k][j][i]=max(f[k][j][i],f[k-p][j-1][f[p][j-1][i]]);
				}
			}	
		}	
	}
	while(Q--){
		int l=read(),r=read(),z=read();
		if(l==r){
			printf("0\n");
			continue;
		}
		if(l+a[l]+z>=r){
			printf("1\n");
			continue;
		}
		int ans=2;
		vector<int> A(z+1,l);
		for(int j=16;j>=0;--j){
			bool ok=true;
			for(int k=0;k<=z;++k){
				for(int p=0;p<=k;++p){
					int t=f[k-p][j][A[p]];
					if(t+a[t]+z-k>=r){
						ok=false;
						break;
					}
				}	
			}
			if(!ok)continue;
			ans+=1<<j;
			for(int k=z;k>=0;--k){
				for(int p=k;p>=0;--p){
					A[k]=max(A[k],f[k-p][j][A[p]]);
				}
			}	
		}
		printf("%d\n",ans);
	}
	return 0;
}