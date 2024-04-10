#include<bits/stdc++.h>
using namespace std;
const int n=999;
const int m=666;
typedef long long ll;
int X,Y;
bool t[n+2][n+2];
struct Car{
	int x,y;
}a[m+233];
void Move(int x,int y){
	if(t[X+x][Y+y])y=0;
	cout<<X+x<<" "<<Y+y<<endl;
	X+=x,Y+=y;
	int k;
	cin>>k>>x>>y;
	assert(k);
	if(k==-1)exit(0);
	t[a[k].x][a[k].y]=false;
	a[k].x=x,a[k].y=y;
	t[x][y]=true;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>X>>Y;
	for(int i=1;i<=m;++i){
		cin>>a[i].x>>a[i].y;
		t[a[i].x][a[i].y]=true;
	}
	while(X<500)Move(1,0);
	while(X>500)Move(-1,0);
	while(Y<500)Move(0,1);
	while(Y>500)Move(0,-1);
	int cnt[2][2]={0,0,0,0};
	for(int i=1;i<=m;++i){
		cnt[a[i].x>=500][a[i].y>=500]++;
	}
	int px=0,py=0;
	for(int i=0;i<2&&!px;++i){
		for(int j=0;j<2;++j){
			if(cnt[i][j]<=166){
				px=i?-1:1;py=j?-1:1;
				break;
			}
		}
	}
	assert(px&&py);
	while(true)Move(px,py);
	return 0;
}