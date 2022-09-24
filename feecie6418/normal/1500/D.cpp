#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pr;
#define mp make_pair
int n,q,a[1505][1505],ans[1505],v[2250005];
vector<pr> col[1505][1505],t;
void Do(int x,int y){
	t.push_back(mp(1,a[x][y]));
	if(x<n)for(pr i:col[x+1][y])t.push_back(mp(i.first+1,i.second));
	if(y<n)for(pr i:col[x][y+1])t.push_back(mp(i.first+1,i.second));
	if(x<n&&y<n)for(pr i:col[x+1][y+1])t.push_back(mp(i.first+1,i.second));
	sort(t.begin(),t.end());
	for(pr i:t){
		if(v[i.second]||col[x][y].size()>q+1)continue;
		v[i.second]=1,col[x][y].push_back(i);
	}
	for(pr i:t)v[i.second]=0;
	t.clear();
}
int main(){
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)scanf("%d",&a[i][j]);
	for(int i=n;i;i--){
		for(int j=n;j;j--){
			Do(i,j);
			int p=min(n-i+1,n-j+1);
			if(col[i][j].size()>q)p=min(p,col[i][j][q].first-1);
			ans[p]++;
		}
	}
	for(int i=n;i;i--)ans[i]+=ans[i+1];
	for(int i=1;i<=n;i++)cout<<ans[i]<<'\n';
	return 0;
}