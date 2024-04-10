#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
inline int rd(void) {
	int x = 0, c = 0, f = 1;
	for(;c<'0'||c>'9';c=getchar())f=c!='-';
	for(;c>='0'&&c<='9';c=getchar())x=x*10+c-'0';
	return f ? x : -x;
}
const int N=55;
int a[N][N],n;
int vis[100010],tim;
bool judge(int x,int y){
	tim++;
	for(int i=1;i<=n;i++)
		if(i!=y)vis[a[x][i]]=tim;
	for(int i=1;i<=n;i++)
		if(i!=x&&a[x][y]-a[i][y]>=0&&vis[a[x][y]-a[i][y]]==tim)return 1;
	return 0;
}
int main(){
	n=rd();
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			a[i][j]=rd();
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)
		if(a[i][j]^1){
			if(!judge(i,j)){
				puts("No");
				return 0;
			}
		}
	puts("Yes");
}