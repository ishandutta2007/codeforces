#include<iostream>
#include<vector>
#include<queue>
#include<map>
#include<cmath>
#include<stack>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define MAXN 15
#define INF 0x7FFFFFFF
#define LL long long
#define NN 100
using namespace std;

int N;
int a[MAXN];
bool B0[MAXN][MAXN];
bool B1[MAXN][MAXN];

bool chk0(){
	
	for(int i=1;i<=N;i++)
	for(int j=1;j<=N;j++){
		if(B0[i][j]!=B1[i][j]) return 0;
	}
	return 1;
}

void r90(){
	bool B4[MAXN][MAXN];
	
	memcpy(B4,B1,sizeof(B1));
	
	for(int i=1;i<=N;i++)
	for(int j=1;j<=N;j++){
		B1[i][j] = B4[N-j+1][i];
	}
}

bool chkr(){
	r90();
	if(chk0()) return 1;
	r90();
	if(chk0()) return 1;
	r90();
	if(chk0()) return 1;
	r90();
	return 0;
}

bool chklr(){
	bool B4[MAXN][MAXN];	
	memcpy(B4,B1,sizeof(B1));
	
	for(int i=1;i<=N;i++)
	for(int j=1;j<=N;j++){
		B1[i][j] = B4[i][N-j+1];
	}
	if(chk0() || chkr()) return 1;
	else return 0;
}

bool chkud(){
	bool B4[MAXN][MAXN];	
	memcpy(B4,B1,sizeof(B1));
	
	for(int i=1;i<=N;i++)
	for(int j=1;j<=N;j++){
		B1[i][j] = B4[N-i+1][j];
	}
	if(chk0() || chkr()) return 1;
	else return 0;
}

int main(){
	ios::sync_with_stdio(0);
	//freopen("1.txt","r",stdin);
	
	cin>>N;
	char c;
	for(int i=1;i<=N;i++)
	for(int j=1;j<=N;j++){
		cin>>c;
		if(c=='X') B0[i][j] = 1;
	}
	
	for(int i=1;i<=N;i++)
	for(int j=1;j<=N;j++){
		cin>>c;
		if(c=='X') B1[i][j] = 1;
	}
	
	if(chk0() || chkr() || chklr() || chkud()){
		cout<<"Yes";
	}
	else{
		cout<<"No";
	}
	
	return 0;
}