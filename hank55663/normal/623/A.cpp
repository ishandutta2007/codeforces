#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,m;
	scanf("%d %d",&n,&m);
	int map[501][501];
	memset(map,0,sizeof(map));
	for(int i=0;i<m;i++){
		int a,b;
		scanf("%d %d",&a,&b);
		a--;
		b--;
		map[a][b]=1;
		map[b][a]=1;
	}
	char ans[501];
	int ok=1;
	memset(ans,0,sizeof(ans));
	for(int i=0;i<n;i++)
	for(int j=0;j<n;j++)
	if(i!=j){
		if(map[i][j]==0){
			if(ans[i]=='c')
			{
				if(ans[j]=='a');
				else if(ans[j]=='c')
				ok=0;
				else
				ans[j]='a';
			}
			else if(ans[i]=='a'){
				if(ans[j]=='a')
				ok=0;
				else if(ans[j]=='c');
				else
				ans[j]='c'; 
			}
			else
			ans[i]='a',ans[j]='c';
		}
	}
	for(int i=0;i<n;i++)
	if(ans[i]==0)
	ans[i]='b';
	for(int i=0;i<n;i++)
	for(int j=0;j<n;j++)
	if(map[i][j]){
		if((ans[i]=='c'&&ans[j]=='a')||(ans[i]=='a'&&ans[j]=='c'))
		ok=0;
	}
	if(!ok)
	printf("No\n");
	else
	printf("Yes\n%s\n",ans);
}