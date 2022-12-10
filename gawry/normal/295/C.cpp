#include<cstdio>
#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;
int n,k,half,whole,total;
const int MOD=1000000000+7;
const int INF=1000000000;
int dist[60][60][2],ways[60][60][2],choose[110][110];
typedef pair<int,int> p2;
typedef pair<p2,int> p3;
vector<p3> q;
void check(int x,int y,int z,int _d,int _w){
	if(_d<dist[x][y][z]){
		dist[x][y][z]=_d;
		ways[x][y][z]=_w;
		q.push_back(p3(p2(x,y),z));
	}else if(_d==dist[x][y][z]){
		ways[x][y][z]=(ways[x][y][z]+_w)%MOD;
	}
}
void go(int x,int y,int z){
//cout<<x<<" "<<y<<" "<<z<<" "<<dist[x][y][z]<<endl;
	if(!z){
		for(int i=0;i<=half-x;i++)for(int j=0;j<=whole-y;j++)if(i+j&&i+2*j<=total){
			check(x+i,y+j,1,dist[x][y][z]+1,(long long)ways[x][y][z]*choose[half-x][i]%MOD*choose[whole-y][j]%MOD);
		}
	}else{
		for(int i=0;i<=x;i++)for(int j=0;j<=y;j++)if(i+j&&i+2*j<=total){
			check(x-i,y-j,0,dist[x][y][z]+1,(long long)ways[x][y][z]*choose[x][i]%MOD*choose[y][j]%MOD);
		}
	}
}
main(){
	for(int i=0;i<100;i++){choose[i][0]=1;for(int j=0;j<i;j++)choose[i][j+1]=(choose[i-1][j]+choose[i-1][j+1])%MOD;}
	scanf("%d %d",&n,&k);
	total=k/50;
	for(int i=1;i<=n;i++){
		int a;
		scanf("%d",&a);
		if(a==50)++half;else ++whole;
	}
	for(int i=0;i<=half;i++)for(int j=0;j<=whole;j++)for(int k=0;k<=1;k++)dist[i][j][k]=INF;
	q.push_back(p3(p2(0,0),0));
	dist[0][0][0]=0;
	ways[0][0][0]=1;
	for(int i=0;i<q.size();i++)go(q[i].first.first,q[i].first.second,q[i].second);
	if(dist[half][whole][1]==INF){
		puts("-1");
		puts("0");
	}else{
		printf("%d\n%d\n",dist[half][whole][1],ways[half][whole][1]);
	}
}