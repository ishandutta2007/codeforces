#include<bits/stdc++.h>
using namespace std;
int t[1000110];
bool vis[1000],vt[1000];
char s[1000011];
int main(){
	int n,b;
	scanf("%d%d%s",&n,&b,s+1);
	for(int i=n;i;i--)
		if(!vt[s[i]])vt[s[i]]=1,t[i]=1;
	int tmp=0;
	for(int i=1;i<=n;i++){
		if(!vis[s[i]])tmp++,vis[s[i]]=1;
		tmp-=t[i-1];
		if(tmp>b){puts("YES");return 0;};
	}
	puts("NO");
}