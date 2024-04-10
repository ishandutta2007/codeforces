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
vector<int>g[3100];
int dist[3100][3100];
int L[3100][3];
int R[3100][3];
int main(){
	int a,b;scanf("%d%d",&a,&b);
	for(int i=0;i<b;i++){
		int p,q;scanf("%d%d",&p,&q);p--;q--;
		g[p].push_back(q);
	}
	for(int i=0;i<a;i++){
		for(int j=0;j<a;j++)dist[i][j]=-1;
		queue<int>Q;
		Q.push(i);
		dist[i][i]=0;
		while(Q.size()){
			int at=Q.front();Q.pop();
			for(int j=0;j<g[at].size();j++){
				int to=g[at][j];
				if(dist[i][to]==-1){
					dist[i][to]=dist[i][at]+1;
					Q.push(to);
				}
			}
		}
	}
	for(int i=0;i<a;i++){
		L[i][0]=L[i][1]=L[i][2]=-1;
		for(int j=0;j<a;j++){
			if(i==j)continue;
			if(dist[j][i]==-1)continue;
			if(L[i][0]==-1||dist[j][i]>dist[L[i][0]][i]){
				L[i][2]=L[i][1];
				L[i][1]=L[i][0];
				L[i][0]=j;
			}else if(L[i][1]==-1||dist[j][i]>dist[L[i][1]][i]){
				L[i][2]=L[i][1];
				L[i][1]=j;
			}else if(L[i][2]==-1||dist[j][i]>dist[L[i][2]][i]){
				L[i][2]=j;
			}
		}
	}
	for(int i=0;i<a;i++){
		R[i][0]=R[i][1]=R[i][2]=-1;
		for(int j=0;j<a;j++){
			if(i==j)continue;
			if(dist[i][j]==-1)continue;
			if(R[i][0]==-1||dist[i][j]>dist[i][R[i][0]]){
				R[i][2]=R[i][1];
				R[i][1]=R[i][0];
				R[i][0]=j;
			}else if(R[i][1]==-1||dist[i][j]>dist[i][R[i][1]]){
				R[i][2]=R[i][1];
				R[i][1]=j;
			}else if(R[i][2]==-1||dist[i][j]>dist[i][R[i][2]]){
				R[i][2]=j;
			}
		}
	}
	int A,B,C,D;
	int bs=0;
	for(int i=0;i<a;i++){
		for(int j=0;j<a;j++){
			for(int k=0;k<3;k++)for(int l=0;l<3;l++){
				if(L[i][k]==-1||R[j][l]==-1||dist[i][j]==-1)continue;
				if(i==j||i==R[j][l]||j==L[i][k]||L[i][k]==R[j][l])continue;
				if(bs<dist[L[i][k]][i]+dist[i][j]+dist[j][R[j][l]]){
					bs=dist[L[i][k]][i]+dist[i][j]+dist[j][R[j][l]];
					A=L[i][k];B=i;C=j;D=R[j][l];
				}
			}
		}
	}
	set<int>S;
	S.insert(A);
	S.insert(B);
	S.insert(C);
	S.insert(D);
	if(S.size()!=4){
		while(1);
	}
	printf("%d %d %d %d\n",A+1,B+1,C+1,D+1);
}