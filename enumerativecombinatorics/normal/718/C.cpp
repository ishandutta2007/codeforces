#include<stdio.h>
#include<math.h>
#include<algorithm>
#include<queue>
#include<string.h>
#include<vector>
#include<set>
#include<stdlib.h>
using namespace std;
const long long mod=1000000007;
const long long inf=mod*mod;
struct mat{
	long long t[2][2];
	mat(){t[0][0]=t[0][1]=t[1][0]=t[1][1]=0;}
};

mat seg1[262144];
bool flag[262144];
long long seg2[262144][2];
int p[110000];
mat tmp;
mat I;
mat F(int a){
	mat ret;
	mat val;
	ret.t[0][0]=ret.t[1][1]=1;
	val.t[0][0]=val.t[0][1]=val.t[1][0]=1;
	while(a){
		if(a%2){
			for(int i=0;i<2;i++)for(int j=0;j<2;j++)tmp.t[i][j]=0;
			for(int k=0;k<2;k++)for(int i=0;i<2;i++)for(int j=0;j<2;j++)tmp.t[i][j]=(tmp.t[i][j]+ret.t[i][k]*val.t[k][j])%mod;
			for(int i=0;i<2;i++)for(int j=0;j<2;j++)ret.t[i][j]=tmp.t[i][j];
		}
		a/=2;
		for(int i=0;i<2;i++)for(int j=0;j<2;j++)tmp.t[i][j]=0;
		for(int k=0;k<2;k++)for(int i=0;i<2;i++)for(int j=0;j<2;j++)tmp.t[i][j]=(tmp.t[i][j]+val.t[i][k]*val.t[k][j])%mod;
		for(int i=0;i<2;i++)for(int j=0;j<2;j++)val.t[i][j]=tmp.t[i][j];
	}
	return ret;
}
long long t2[2];
void add(int a,int b,int c,int d,int e,mat f){
	if(d<a||b<c)return;
	if(c<=a&&b<=d){
		flag[e]=true;
		t2[0]=seg2[e][0]*f.t[0][0]+seg2[e][1]*f.t[0][1];
		t2[1]=seg2[e][0]*f.t[1][0]+seg2[e][1]*f.t[1][1];
		seg2[e][0]=t2[0]%mod;
		seg2[e][1]=t2[1]%mod;
		for(int i=0;i<2;i++)for(int j=0;j<2;j++)tmp.t[i][j]=0;
		for(int k=0;k<2;k++)for(int i=0;i<2;i++)for(int j=0;j<2;j++)tmp.t[i][j]=(tmp.t[i][j]+f.t[i][k]*seg1[e].t[k][j])%mod;
		for(int i=0;i<2;i++)for(int j=0;j<2;j++)seg1[e].t[i][j]=tmp.t[i][j];
		return;
	}
	if(flag[e]){
		flag[e*2]=flag[e*2+1]=true;
		for(int i=0;i<2;i++)for(int j=0;j<2;j++)tmp.t[i][j]=0;
		for(int k=0;k<2;k++)for(int i=0;i<2;i++)for(int j=0;j<2;j++)tmp.t[i][j]=(tmp.t[i][j]+seg1[e].t[i][k]*seg1[e*2].t[k][j])%mod;
		for(int i=0;i<2;i++)for(int j=0;j<2;j++)seg1[e*2].t[i][j]=tmp.t[i][j];
		t2[0]=seg2[e*2][0]*seg1[e].t[0][0]+seg2[e*2][1]*seg1[e].t[0][1];
		t2[1]=seg2[e*2][0]*seg1[e].t[1][0]+seg2[e*2][1]*seg1[e].t[1][1];
		seg2[e*2][0]=t2[0]%mod;
		seg2[e*2][1]=t2[1]%mod;
		for(int i=0;i<2;i++)for(int j=0;j<2;j++)tmp.t[i][j]=0;
		for(int k=0;k<2;k++)for(int i=0;i<2;i++)for(int j=0;j<2;j++)tmp.t[i][j]=(tmp.t[i][j]+seg1[e].t[i][k]*seg1[e*2+1].t[k][j])%mod;
		for(int i=0;i<2;i++)for(int j=0;j<2;j++)seg1[e*2+1].t[i][j]=tmp.t[i][j];
		t2[0]=seg2[e*2+1][0]*seg1[e].t[0][0]+seg2[e*2+1][1]*seg1[e].t[0][1];
		t2[1]=seg2[e*2+1][0]*seg1[e].t[1][0]+seg2[e*2+1][1]*seg1[e].t[1][1];
		seg2[e*2+1][0]=t2[0]%mod;
		seg2[e*2+1][1]=t2[1]%mod;
		flag[e]=false;
		seg1[e]=I;
	}
	add(a,(a+b)/2,c,d,e*2,f);
	add((a+b)/2+1,b,c,d,e*2+1,f);
	seg2[e][0]=(seg2[e*2][0]+seg2[e*2+1][0])%mod;
	seg2[e][1]=(seg2[e*2][1]+seg2[e*2+1][1])%mod;
	
}
long long calc(int a,int b,int c,int d,int e){
	if(d<a||b<c)return 0;
	if(c<=a&&b<=d){
	//	return (seg2[e][0]*seg1[e].t[0][0]+seg2[e][1]*seg1[e].t[0][1])%mod;
		return seg2[e][0];
	}
	if(flag[e]){
		flag[e*2]=flag[e*2+1]=true;
		for(int i=0;i<2;i++)for(int j=0;j<2;j++)tmp.t[i][j]=0;
		for(int k=0;k<2;k++)for(int i=0;i<2;i++)for(int j=0;j<2;j++)tmp.t[i][j]=(tmp.t[i][j]+seg1[e].t[i][k]*seg1[e*2].t[k][j])%mod;
		for(int i=0;i<2;i++)for(int j=0;j<2;j++)seg1[e*2].t[i][j]=tmp.t[i][j];
		t2[0]=seg2[e*2][0]*seg1[e].t[0][0]+seg2[e*2][1]*seg1[e].t[0][1];
		t2[1]=seg2[e*2][0]*seg1[e].t[1][0]+seg2[e*2][1]*seg1[e].t[1][1];
		seg2[e*2][0]=t2[0]%mod;
		seg2[e*2][1]=t2[1]%mod;
		for(int i=0;i<2;i++)for(int j=0;j<2;j++)tmp.t[i][j]=0;
		for(int k=0;k<2;k++)for(int i=0;i<2;i++)for(int j=0;j<2;j++)tmp.t[i][j]=(tmp.t[i][j]+seg1[e].t[i][k]*seg1[e*2+1].t[k][j])%mod;
		for(int i=0;i<2;i++)for(int j=0;j<2;j++)seg1[e*2+1].t[i][j]=tmp.t[i][j];
		t2[0]=seg2[e*2+1][0]*seg1[e].t[0][0]+seg2[e*2+1][1]*seg1[e].t[0][1];
		t2[1]=seg2[e*2+1][0]*seg1[e].t[1][0]+seg2[e*2+1][1]*seg1[e].t[1][1];
		seg2[e*2+1][0]=t2[0]%mod;
		seg2[e*2+1][1]=t2[1]%mod;
		flag[e]=false;
		seg1[e]=I;
	}
	long long ret=(calc(a,(a+b)/2,c,d,e*2)+calc((a+b)/2+1,b,c,d,e*2+1))%mod;

	seg2[e][0]=(seg2[e*2][0]+seg2[e*2+1][0])%mod;
	seg2[e][1]=(seg2[e*2][1]+seg2[e*2+1][1])%mod;
	return ret;
}
int main(){
	int a,b;scanf("%d%d",&a,&b);
	for(int i=0;i<a;i++){
		scanf("%d",p+i);
	}
	for(int i=0;i<a;i++){
		mat tmp=F(p[i]-1);
		seg2[i+131072][0]=tmp.t[0][0];
		seg2[i+131072][1]=tmp.t[1][0];

	}
	for(int i=131071;i>=0;i--){
		seg2[i][0]=(seg2[i*2][0]+seg2[i*2+1][0])%mod;
		seg2[i][1]=(seg2[i*2][1]+seg2[i*2+1][1])%mod;
	}
	for(int i=0;i<262144;i++){
		for(int j=0;j<2;j++)for(int k=0;k<2;k++)seg1[i].t[j][k]=(j==k);
	}
	I.t[0][0]=I.t[1][1]=1;
	while(b--){
		int v;scanf("%d",&v);
		if(v==1){
			int x,y,z;scanf("%d%d%d",&x,&y,&z);x--;y--;
			add(0,131071,x,y,1,F(z));
		}else{
			int x,y;scanf("%d%d",&x,&y);x--;y--;
			printf("%I64d\n",calc(0,131071,x,y,1));
		}
	}
}