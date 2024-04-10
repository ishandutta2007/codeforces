#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,q,f[32][32],g[400005][32];
char a[100005],b[10];
string s[]={"a","b","c","ab","bc"};
void Pushup(int p){
	int *x=g[p<<1],*y=g[p*2+1],*z=g[p];
	for(int i=0;i<32;i++)z[i]=1e9;
	for(int i=0;i<32;i++){
		if(g[p<<1][i]>=1e9)continue;
		for(int j=0;j<32;j++){
			if(f[i][j]!=-1){
				z[f[i][j]]=min(z[f[i][j]],x[i]+y[j]);
			}
		}
	}
}
void Build(int p,int l,int r){
	if(l==r){
		for(int i=0;i<32;i++)g[p][i]=1e9;
		g[p][1]=g[p][2]=g[p][4]=1;
		g[p][1<<(a[l]-'a')]=0;
		return ;
	}
	int mid=(l+r)/2;
	Build(p*2,l,mid),Build(p*2+1,mid+1,r);
	Pushup(p);
}
void Upd(int p,int l,int r,int x){
	if(l==r){
		for(int i=0;i<32;i++)g[p][i]=1e9;
		g[p][1]=g[p][2]=g[p][4]=1;
		g[p][1<<(a[l]-'a')]=0;
		return ;
	}
	int mid=(l+r)/2;
	if(x<=mid)Upd(p*2,l,mid,x);
	else Upd(p*2+1,mid+1,r,x);
	Pushup(p);
}
int main(){
	scanf("%d%d%s",&n,&q,a+1);
	for(int i=0;i<32;i++){
		for(int j=0;j<32;j++){
			int t=i|j,F=1;
			for(int k=0;k<5;k++){
				for(int l=0;l<5;l++){
					if((i&(1<<k))&&(j&(1<<l))){
						if(s[k]+s[l]=="abc")F=0;
						for(int p=0;p<5;p++){
							if(s[k]+s[l]==s[p])t|=1<<p;
						}
					}
				}
			}
			if(F==0)f[i][j]=-1;
			else f[i][j]=t;
		}
	}
	Build(1,1,n);
	for(int i=1,x;i<=q;i++){
		scanf("%d%s",&x,b);
		a[x]=b[0],Upd(1,1,n,x);
		int ans=1e9;
		for(int i=0;i<32;i++)ans=min(ans,g[1][i]);
		cout<<ans<<'\n';
	}
}