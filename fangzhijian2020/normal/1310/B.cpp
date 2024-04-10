#include<iostream>
#include<iomanip>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int read(){
	int a=0;bool opt=0;char c=getchar();
	while(c<'0'||c>'9')opt|=c=='-',c=getchar();
	while(c>='0'&&c<='9')a=(a<<3)+(a<<1)+(c^48),c=getchar();
	return opt?-a:a;
}
int n,k,opt[200005],f[400005][2][2];
void ckmax(int&a,int b){a=max(a,b);}
int Max(int k){
	return max(max(f[k][0][0],f[k][1][1]+1),max(f[k][1][0]+1,f[k][0][1]+1));
}
int solve(int k,int l,int r,int l1,int l2,int r1,int r2){
	int tmp=f[l][l1][l2]+f[r][r1][r2]+(l1|r1)+(l2|r2);
	for(int i=0;i<2;++i){
		int p1=i?l1:r1,p2=i?r1:l1;
		for(int j=0;j<2;++j){
			int p3=j?l2:r2;
			tmp+=(p2|p3);
			ckmax(f[k][p1][p2],tmp);
			ckmax(f[k][p1][p3],tmp);
			tmp-=(p2|p3);
		}
	}
}
void merge(int k,int l,int r){
	for(int l1=0;l1<2;++l1){
		for(int l2=0;l2<2;++l2){
			if(f[l][l1][l2]<0)continue;
			for(int r1=0;r1<2;++r1){
				for(int r2=0;r2<2;++r2){
					if(f[r][r1][r2]<0)continue;
					solve(k,l,r,l1,l2,r1,r2);
				}
			}
		}
	}
}
void divide(int k,int l,int r){
	if(l+1==r){
		if(!opt[l]&&!opt[r])f[k][0][0]=0;
		else if(opt[l]&&opt[r])f[k][1][1]=1;
		else f[k][1][0]=f[k][0][1]=1;
		return;
	}
	int mid=l+r>>1;
	divide(k<<1,l,mid);divide(k<<1|1,mid+1,r);
	merge(k,k<<1,k<<1|1);
}
int main(){
//	freopen("mao.in","r",stdin);
//	freopen("mao.out","w",stdout);
	n=read();k=read();
	for(int i=1;i<=k;++i)opt[read()]=1;
	memset(f,-0x3f,sizeof(f));divide(1,1,1<<n);
	printf("%d\n",Max(1));
	return 0;
}