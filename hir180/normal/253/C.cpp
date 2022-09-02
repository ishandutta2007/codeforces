#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <fstream>
#include <queue>
using namespace std;
typedef pair<int,int> P;
int num[101];
int dis[101][100005]={};
bool s[101][100005];
int main(){
	queue<P>que;
	for(int i=0;i<101;i++){
		for(int j=0;j<100005;j++){
			s[i][j]=false;
		}
	}
freopen("input.txt","r",stdin);
freopen("output.txt","w",stdout);
int n;
scanf("%d",&n);
for(int i=1;i<=n;i++){
	scanf("%d",&num[i]);
}
int a,b,c,d;
scanf("%d %d %d %d",&a,&b,&c,&d);
dis[a][b]=0;
que.push(make_pair(a,b));
s[a][b]=true;
while(que.size()){
	P p=que.front();
	que.pop();
	if(p.first==c && p.second==d){
		printf("%d\n",dis[c][d]);
		break;
	}
	if(p.first!=1){
		if(num[p.first-1]+1>=p.second){
			if(!s[p.first-1][p.second]){
			dis[p.first-1][p.second]=dis[p.first][p.second]+1;
			que.push(make_pair(p.first-1,p.second));
			s[p.first-1][p.second]=true;
			}
		}else{
			if(!s[p.first-1][num[p.first-1]+1]){
			dis[p.first-1][num[p.first-1]+1]=dis[p.first][p.second]+1;
			que.push(make_pair(p.first-1,num[p.first-1]+1));
			s[p.first-1][num[p.first-1]+1]=true;
			}
		}
	}
	if(p.first!=n){
		if(num[p.first+1]+1>=p.second){
			if(!s[p.first+1][p.second]){
			dis[p.first+1][p.second]=dis[p.first][p.second]+1;
			que.push(make_pair(p.first+1,p.second));
			s[p.first+1][p.second]=true;
			}
		}else{
			if(!s[p.first+1][num[p.first+1]+1]){
			dis[p.first+1][num[p.first+1]+1]=dis[p.first][p.second]+1;
			que.push(make_pair(p.first+1,num[p.first+1]+1));
			s[p.first+1][num[p.first+1]+1]=true;
			}
		}
	}
	if(p.second!=1 && !s[p.first][p.second-1]){
			dis[p.first][p.second-1]=dis[p.first][p.second]+1;
			que.push(make_pair(p.first,p.second-1));
			s[p.first][p.second-1]=true;
	}
	if(p.second!=num[p.first]+1 && !s[p.first][p.second+1]){
			dis[p.first][p.second+1]=dis[p.first][p.second]+1;
			que.push(make_pair(p.first,p.second+1));
			s[p.first][p.second+1]=true;
	}
}
return 0;
}