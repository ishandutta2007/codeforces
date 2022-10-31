#include<stdio.h>
#include<math.h>
#include<algorithm>
#include<queue>
#include<string.h>
#include<vector>
#include<set>
using namespace std;
const long long mod=1000000007;
const long long inf=mod*mod;
int c[2100][4100];
int s[2100];
int t[2100];
int ans[510000];
typedef unsigned long long wolf;
wolf mat[2100][65];
int D=64;
int x[510000];
int y[510000];
int main(){
	int a,b;scanf("%d%d",&a,&b);
	for(int i=0;i<b;i++){
		int p,q;scanf("%d%d",&p,&q);p--;q--;
		c[p][q]=1;
		x[i]=p;y[i]=q;
	}
	for(int i=0;i<a;i++)for(int j=0;j<a*2;j++){
		if(c[i][j]||j==i+a)mat[i][j/D]+=(1LL<<(j%D));
	}
	int cur=0;
	for(int i=0;i<a;i++){
		int at=-1;
		for(int j=cur;j<a;j++){
			if(mat[j][i/D]&(1LL<<(i%D))){
				at=j;break;
			}
		}
		if(!~at)continue;
		for(int k=0;k<65;k++)swap(mat[at][k],mat[cur][k]);
		for(int j=0;j<a;j++){
			if(cur==j)continue;
			if(mat[j][i/D]&(1LL<<(i%D))){
				for(int k=0;k<65;k++)mat[j][k]^=mat[cur][k];
			}
		}

		cur++;
	}
	for(int i=0;i<b;i++){
		if(mat[y[i]][(a+x[i])/D]&(1LL<<((a+x[i])%D)))printf("NO\n");
		else printf("YES\n");
	}
}