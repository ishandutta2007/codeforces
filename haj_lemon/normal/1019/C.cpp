#include<bits/stdc++.h>
using namespace std;
int m,n,x,y,i;
bool v[1000010];
vector<int>e[1000010],a;
int main(){
	scanf("%d%d",&n,&m);
	while(m--)scanf("%d%d",&x,&y),e[x].push_back(y);
	for(i=1;i<=n;i++)if(!v[i])for(auto j:e[i])if(j>i)v[j]=1;
	for(i=n;i;i--)if(!v[i]){for(auto j:e[i])v[j]=1;a.push_back(i);}
	printf("%d\n",a.size());
	for(auto j:a)printf("%d ",j);
	return 0;
}