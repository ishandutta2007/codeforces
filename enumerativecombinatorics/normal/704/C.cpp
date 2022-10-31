#include<stdio.h>
#include<math.h>
#include<algorithm>
#include<queue>
#include<string.h>
#include<vector>
#include<set>
#include<map>
#include<stdlib.h>
using namespace std;
const long long mod=1000000007;
const long long inf=mod*mod;
int L[110000];
int R[110000];
vector<int>g[110000];
int ABS(int a){
	return max(a,-a);
}
int num=1;
int ord[110000];
int lm[110000];
int v[110000];
pair<int,int> p[110000];
long long dp[110000][2][2][2];
vector<int>q[110000];
int main(){
	int a,b;scanf("%d%d",&b,&a);
	for(int i=0;i<b;i++){
		int x;scanf("%d",&x);
		if(x==1){
			scanf("%d",L+i);
		}else{
			scanf("%d%d",L+i,R+i);
		//	if(ABS(L[i])<ABS(R[i]))swap(L[i],R[i]);
			if(ABS(L[i])!=ABS(R[i])){
				g[ABS(L[i])].push_back(ABS(R[i]));
				g[ABS(R[i])].push_back(ABS(L[i]));
			}
		}
	}
	for(int i=1;i<=a;i++)v[i]=-1;
	for(int i=1;i<=a;i++)p[i]=make_pair(g[i].size(),i);
	std::sort(p+1,p+a+1);
	for(int i=1;i<=a;i++){
		int at=p[i].second;
		if(~v[at])continue;
		int id=at;
		int tl=num;
		if(p[i].first!=2)tl=-1;

		while(1){
			bool ok=false;
			ord[num]=id;
			v[id]=num++;
			lm[id]=tl;
			for(int j=0;j<g[id].size();j++){
				if(~v[g[id][j]])continue;
				ok=true;
				id=g[id][j];
				break;
			}
			if(!ok)break;
		}
	}
	for(int i=0;i<b;i++){
		q[max(v[ABS(L[i])],v[ABS(R[i])])].push_back(i);
	}
//	for(int i=1;i<=a;i++)printf("%d ",v[i]);
//	printf("\n");
	dp[0][0][0][0]=1;
	for(int i=0;i<a;i++){
		for(int j=0;j<2;j++)for(int k=0;k<2;k++)for(int l=0;l<2;l++){
			if(!dp[i][j][k][l])continue;
			for(int m=0;m<2;m++){
				int tl=l;
				int tk=m;
				int tj=j;
				if(lm[ord[i+1]]==i+1)tj=m;

				for(int t=0;t<q[i+1].size();t++){
					int ql=L[q[i+1][t]];
					int qr=R[q[i+1][t]];
					if(ABS(ql)==ord[i+1]){
						if(qr==0){
							if(ql>0&&m)tl^=1;
							if(ql<0&&!m)tl^=1;
						}else if(ABS(qr)==ord[i+1]){
							if(((ql<0)^m)||((qr<0)^m))tl^=1;
						}else if(ABS(qr)==ord[i]){
							if(((ql<0)^m)||((qr<0)^k))tl^=1;
						}else{
							if(((ql<0)^m)||((qr<0)^j))tl^=1;
						}
					}else{
						if(ABS(ql)==ord[i]){
							if(((qr<0)^m)||((ql<0)^k))tl^=1;
						}else{
							if(((qr<0)^m)||((ql<0)^j))tl^=1;
						}
					}
				}
				dp[i+1][tj][tk][tl]=(dp[i+1][tj][tk][tl]+dp[i][j][k][l])%mod;
			}
		}
	}
	long long ret=0;
	for(int i=0;i<2;i++)for(int j=0;j<2;j++)ret+=dp[a][i][j][1];
	ret%=mod;
	printf("%d\n",(int)ret);
}