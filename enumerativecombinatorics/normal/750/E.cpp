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
char in[210000];
struct wolf{
	int t[5][5];
	wolf(){for(int i=0;i<5;i++)for(int j=0;j<5;j++)t[i][j]=-1;}
};
wolf segtree[524288];
wolf zero;
wolf dame;
wolf query(int a,int b,int c,int d,int e){
	if(d<=a||b<=c)return zero;
	if(c<=a&&b<=d){
		//printf("%d %d %d %d %d\n",a,b,c,d,e);

		return segtree[e];
	}
	wolf L=query(a,(a+b)/2,c,d,e*2);
	wolf R=query((a+b)/2,b,c,d,e*2+1);
	//for(int i=0;i<5;i++){
//		for(int j=0;j<5;j++)printf("%d ",R.t[i][j]);printf("\n");
//	}
	wolf ret;
	for(int i=0;i<5;i++)for(int j=i;j<5;j++){
		for(int k=i;k<=j;k++){
			//printf("%d %d %d\n",L.t[i][k],R.t[k][j],ret.t[i][j]);
			if(~L.t[i][k]&&~R.t[k][j]&&(ret.t[i][j]==-1||ret.t[i][j]>L.t[i][k]+R.t[k][j])){

				ret.t[i][j]=L.t[i][k]+R.t[k][j];
			}
		}
	}
	return ret;
}
int main(){
	int a,b;scanf("%d%d",&a,&b);
	scanf("%s",in);
	for(int i=0;i<a;i++){
		for(int j=0;j<5;j++)segtree[i+262144].t[j][j]=0;
		if(in[i]=='2'){
			segtree[i+262144].t[0][0]=1;
			segtree[i+262144].t[0][1]=0;
		}else if(in[i]=='0'){
			segtree[i+262144].t[1][1]=1;
			segtree[i+262144].t[1][2]=0;
		}else if(in[i]=='1'){
			segtree[i+262144].t[2][2]=1;
			segtree[i+262144].t[2][3]=0;
		}else if(in[i]=='6'){
			segtree[i+262144].t[3][3]=1;
			segtree[i+262144].t[4][4]=1;
		}else if(in[i]=='7'){
			segtree[i+262144].t[3][3]=1;
			segtree[i+262144].t[3][4]=0;
		}
		
	}
	for(int i=a;i<262144;i++)for(int j=0;j<5;j++)segtree[i+262144].t[j][j]=0;
	for(int i=262143;i>0;i--){
		for(int j=0;j<5;j++)for(int k=j;k<5;k++){
			for(int l=j;l<=k;l++){
				if(segtree[i*2].t[j][l]==-1||segtree[i*2+1].t[l][k]==-1)continue;
				if(~segtree[i].t[j][k])segtree[i].t[j][k]=min(segtree[i].t[j][k],segtree[i*2].t[j][l]+segtree[i*2+1].t[l][k]);
				else segtree[i].t[j][k]=segtree[i*2].t[j][l]+segtree[i*2+1].t[l][k];
			}
		}
	}
	for(int i=0;i<5;i++)zero.t[i][i]=0;
	for(int i=0;i<5;i++)for(int j=0;j<5;j++)dame.t[i][j]=-1;
	while(b--){
		int p,q;scanf("%d%d",&p,&q);p--;
		wolf res=query(0,262144,p,q,1);

		printf("%d\n",res.t[0][4]);
	}
}