#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int rd(){
    int x=0,ch=getchar();
    while(!isdigit(ch))ch=getchar();
    while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
    return x;
}
struct Node{
	int tm,dis;
};
struct Qnode{
	int id,isz,tm,dis;
};
int n,m,v[300005][25][2];
bool operator <(Node x,Node y){
	if(max(x.tm,y.tm)<=20)return x.dis+(1<<x.tm)<y.dis+(1<<y.tm);
	if(x.tm==y.tm)return x.dis<y.dis;
	return x.tm<y.tm;
}
bool operator >(Node x,Node y){
	if(max(x.tm,y.tm)<=20)return x.dis+(1<<x.tm)>y.dis+(1<<y.tm);
	if(x.tm==y.tm)return x.dis>y.dis;
	return x.tm>y.tm;
}
bool operator <(Qnode x,Qnode y){
	if(max(x.tm,y.tm)<=20)return x.dis+(1<<x.tm)>y.dis+(1<<y.tm);
	if(x.tm==y.tm)return x.dis>y.dis;
	return x.tm>y.tm;
}
Node operator +(Node x,Node y){
	return (Node){x.tm+y.tm,x.dis+y.dis};
}
Node dis[300005][25][2];
vector<int> g[300005],g2[300005];
int Dijkstra(){
	for(int i=1;i<=n;i++){
		for(int j=0;j<=23;j++)dis[i][j][0]=dis[i][j][1]={1<<29,1<<29},v[i][j][0]=v[i][j][1]=0;
	}
	priority_queue<Qnode> q;
	dis[1][0][0]={0,0},q.push((Qnode){1,0,0,0});
	while(!q.empty()){
		int x=q.top().id,num=q.top().tm,o=q.top().isz;
		num=min(num,23);
		q.pop();
		if(v[x][num][o])continue;
		v[x][num][o]=1;
		if(!o){
			for(int y:g[x]){
				if(dis[y][num][0]>(dis[x][num][o]+(Node){0,1})){
					dis[y][num][0]=(dis[x][num][o]+(Node){0,1});
					q.push((Qnode){y,0,dis[x][num][o].tm,dis[x][num][o].dis+1});
				}
			}
		}
		else {
			for(int y:g2[x]){
				if(dis[y][num][1]>(dis[x][num][o]+(Node){0,1})){
					dis[y][num][1]=(dis[x][num][o]+(Node){0,1});
					q.push((Qnode){y,1,dis[x][num][o].tm,dis[x][num][o].dis+1});
				}
			}
		}
		if(dis[x][min(num+1,23)][o^1]>(dis[x][num][o]+(Node){1,0})){
			dis[x][min(num+1,23)][o^1]=(dis[x][num][o]+(Node){1,0});
			q.push((Qnode){x,o^1,dis[x][num][o].tm+1,dis[x][num][o].dis});
		}
	}
	Node tmp={1<<29,1<<29};
	for(int i=0;i<=23;i++)tmp=min(tmp,min(dis[n][i][0],dis[n][i][1]));
	int ans=1;
	for(int i=1;i<=tmp.tm;i++)ans=ans*2%mod;
	ans=(ans-1+mod)%mod;
	return (ans+tmp.dis)%mod;
}
int main(){
	n=rd(),m=rd();
	for(int i=1,x,y;i<=m;i++){
		x=rd(),y=rd(),g[x].push_back(y),g2[y].push_back(x);
	}
	cout<<Dijkstra();
    return 0;
}