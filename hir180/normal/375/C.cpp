#include <cstdio>
#include <cmath>
#include <algorithm>
#include <queue>
#include <iostream>
using namespace std;
int v[25][25][(1<<8)];
int pr[8];
typedef pair<int,int> P;
#define mp make_pair
P za[8];
char f[25][25];
int n,m,sx,sy;
int main()
{
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			scanf(" %c",&f[i][j]);
		}
	}
	int id=0;
	while(scanf("%d",&pr[id++])!=EOF); id--;
	int id2=id;
	while(id<8) pr[id++]=-10000;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(f[i][j]=='S') { sx=i,sy=j; f[i][j]='.';}
			if(0<=f[i][j]-'0' && f[i][j]-'0'<=9)
			{
				za[f[i][j]-'1']=make_pair(i,j);
			}
			if(f[i][j]=='B') za[id2++]=mp(i,j);
		}
	}
	queue<pair<P,int> >que;
	for(int i=0;i<25;i++)for(int j=0;j<25;j++)for(int k=0;k<(1<<8);k++)v[i][j][k]=10000;
	v[sx][sy][0]=0; que.push(mp(mp(sx,sy),0));
	while(!que.empty()){
		pair<P,int> x=que.front(); que.pop();
		int a=x.first.first; int b=x.first.second; int state=x.second;
		int dx[4]={0,1,0,-1}; int dy[4]={1,0,-1,0};
		for(int i=0;i<4;i++){
			int nx=a+dx[i]; int ny=b+dy[i]; int state2=state;
			if(!(0<=nx&&nx<n)) continue;
			if(!(0<=ny&&ny<m)) continue;
			if(f[nx][ny]!='.') continue;
			//(a,b)(a-INF,b+1)
			if(i==0){
				for(int j=0;j<id2;j++){
					//
					if(nx<za[j].first && ny==za[j].second) state2^=(1<<j);
				}
			}
			if(i==2){
				for(int j=0;j<id2;j++){
					//
					if(nx<za[j].first && b==za[j].second) state2^=(1<<j);
				}
			}
			if(v[nx][ny][state2]==10000){
				v[nx][ny][state2]=v[a][b][state]+1;
				que.push(mp(mp(nx,ny),state2));
			}
		}
	}
	int ret=0;
	for(int i=0;i<(1<<id2);i++){
		int val=0; for(int j=0;j<id2;j++) if(((i>>j)&1)) val+=pr[j];
		ret=max(ret,val-v[sx][sy][i]);
	}
	printf("%d%c",ret,10);
}