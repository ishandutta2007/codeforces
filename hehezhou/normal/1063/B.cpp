#include<bits/stdc++.h>
#define mk make_pair
using namespace std;
int n,m,mp[2010][2010],a[2010][2010],ay[2010][2010],r,c,x,y;
char s[2010];
deque<pair<int,int> >q;
int main(){
	q.clear();
	memset(a,-1,sizeof a);
	scanf("%d%d%d%d%d%d",&n,&m,&r,&c,&x,&y);
	for(int i=1;i<=n;i++){
		scanf("%s",s+1);
		for(int j=1;j<=m;j++)mp[i][j]=(s[j]=='.'?1:0);
	}
	a[r][c]=0;
	q.push_back(mk(r,c));
	while(!q.empty()){
		pair<int,int> now=q.front();q.pop_front();
		int nowx=now.first,nowy=now.second;
		int newx=nowx+1,newy=nowy;
		if(mp[newx][newy]&&(a[newx][newy]==-1||a[newx][newy]>a[nowx][nowy])){
			a[newx][newy]=a[nowx][nowy];
			ay[newx][newy]=ay[nowx][nowy];
			q.push_front(mk(newx,newy));
		}
		newx-=2;
		if(mp[newx][newy]&&(a[newx][newy]==-1||a[newx][newy]>a[nowx][nowy])){
			a[newx][newy]=a[nowx][nowy];
			ay[newx][newy]=ay[nowx][nowy];
			q.push_front(mk(newx,newy));
		}
		newx++,newy--;
		if(mp[newx][newy]&&(a[newx][newy]==-1||a[newx][newy]>a[nowx][nowy])){
			if(ay[nowx][nowy]+1<=x)
				a[newx][newy]=a[nowx][nowy],
				ay[newx][newy]=ay[nowx][nowy]+1,
				q.push_front(mk(newx,newy));
		}
		newy+=2;
		if(mp[newx][newy]&&(a[newx][newy]==-1||a[newx][newy]>a[nowx][nowy])){
			if(a[nowx][nowy]+1<=y)
				a[newx][newy]=a[nowx][nowy]+1,
				ay[newx][newy]=ay[nowx][nowy],
				q.push_back(mk(newx,newy));
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)if(a[i][j]!=-1)ans++;
	return printf("%d\n",ans),0;
}