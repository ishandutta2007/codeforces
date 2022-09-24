#include<bits/stdc++.h>
using namespace std;
int ss=0,used[10];
void DFS(int a,int b,int c,int s){
	ss=max(ss,s);
	if(ss==7)return ;
	if(a&&b&&c&&!used[7]){
		used[7]=1;
		DFS(a-1,b-1,c-1,s+1);
		used[7]=0;
	}
	if(a&&b&&!used[6]){
		used[6]=1;
		DFS(a-1,b-1,c,s+1);
		used[6]=0;
	}
	if(a&&c&&!used[5]){
		used[5]=1;
		DFS(a-1,b,c-1,s+1);
		used[5]=0;
	}
	if(a&&!used[4]){
		used[4]=1;
		DFS(a-1,b,c,s+1);
		used[4]=0;
	}
	if(b&&c&&!used[3]){
		used[3]=1;
		DFS(a,b-1,c-1,s+1);
		used[3]=0;
	}
	if(b&&!used[2]){
		used[2]=1;
		DFS(a,b-1,c,s+1);
		used[2]=0;
	}
	if(c&&!used[1]){
		used[1]=1;
		DFS(a,b,c-1,s+1);
		used[1]=0;
	}
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		memset(used,0,sizeof(used));
		int a,b,c;
		ss=0;
		scanf("%d%d%d",&a,&b,&c);
		DFS(a,b,c,0);
		cout<<ss<<endl;
	}
}