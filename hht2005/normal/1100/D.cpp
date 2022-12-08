#include<bits/stdc++.h>
using namespace std;
const int N=1010;
const int dx[2]={1,-1},dy[2]={1,-1};
int x[N],y[N],X,Y,S[2][2],t[1010][1010];
int win(int X,int Y) {
	int cnt=0;
	for(int i=1;i<=666;i++)
		if(x[i]==X||y[i]==Y)
			cnt++;
	return cnt>=1;
}
void to(int x1,int y1) {
	X=x1,Y=y1;
	cout<<X<<' '<<Y<<endl;
	int k;
	cin>>k>>x1>>y1;
	if(k<1)exit(0);
	x[k]=x1,y[k]=y1;
}
int calc(int X,int Y) {
	for(int i=1;i<=666;i++)
		if(x[i]==X&&y[i]==Y)
			return 0;
	return 1;
}
int main() {
	scanf("%d%d",&X,&Y);
	for(int i=1;i<=666;i++)
		scanf("%d%d",x+i,y+i);
	while(X<500)to(X+1,Y);
	while(X>500)to(X-1,Y);
	while(Y<500)to(X,Y+1);
	while(Y>500)to(X,Y-1);
	for(int i=1;i<=666;i++)
		S[x[i]>500][y[i]>500]++;
	int a=0,b=0;
	for(int i=0;i<2;i++)
		for(int j=0;j<2;j++)
			if(S[i][j]<S[a][b])
				a=i,b=j;
	while(1) {
		if(calc(X+dx[a],Y+dy[b]))
			to(X+dx[a],Y+dy[b]);
		else {
			if(win(X+dx[a],Y))to(X+dx[a],Y);
			else to(X,Y+dy[b]);
		}
	}
	return 0;
}