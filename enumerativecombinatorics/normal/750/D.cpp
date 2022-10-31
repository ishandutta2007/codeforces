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
int b[32];
int vis[410][410];
bool f[410][410][30][8];
int dx[]={1,1,0,-1,-1,-1,0,1};
int dy[]={0,1,1,1,0,-1,-1,-1};
int D=200;
int main(){
	int a;scanf("%d",&a);
	for(int i=0;i<a;i++){
		scanf("%d",b+i);
	}
	b[0]--;
	queue<pair<pair<int,int>,pair<int,int> > > Q;
	Q.push(make_pair(make_pair(D,D),make_pair(0,0)));
	f[D][D][0][0]=1;
	while(Q.size()){
		int row=Q.front().first.first;
		int col=Q.front().first.second;
		int ph=Q.front().second.first;
		int dir=Q.front().second.second;Q.pop();
		vis[row][col]=1;
		for(int i=0;i<b[ph];i++){
			row+=dx[dir];
			col+=dy[dir];
			vis[row][col]=1;
		}
		if(ph==a-1)continue;

		if(!f[row][col][ph+1][(dir+1)%8]){
			f[row][col][ph+1][(dir+1)%8]=true;
			Q.push(make_pair(make_pair(row,col),make_pair(ph+1,(dir+1)%8)));
		}
		if(!f[row][col][ph+1][(dir+7)%8]){

			f[row][col][ph+1][(dir+7)%8]=true;
			Q.push(make_pair(make_pair(row,col),make_pair(ph+1,(dir+7)%8)));
		}
	}
	int ret=0;
	for(int i=0;i<410;i++)for(int j=0;j<410;j++)ret+=vis[i][j];
		printf("%d\n",ret);
}