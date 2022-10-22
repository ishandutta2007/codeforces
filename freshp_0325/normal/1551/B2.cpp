#include<bits/stdc++.h>
using namespace std;
#define mp make_pair
vector<int> Pos[200005];
int n,k,a[200005],st[200005],b[200005];
int main(){
	int T;
	scanf("%d",&T);
	while(T-->0)
	{
		scanf("%d %d",&n,&k);
		for(int i=1;i<=n;++i)	st[i]=b[i]=0,Pos[i].clear();
		for(int i=1;i<=n;++i)scanf("%d",&a[i]),++st[a[i]],Pos[a[i]].push_back(i);
		vector<int> P;
		for(int i=1;i<=n;++i)
		{
			if(st[i]>=k)
			{
				for(int j=0;j<k;++j)
					b[Pos[i][j]]=j+1;
			}
			else if(st[i])
			{
				for(auto ss:Pos[i])	P.push_back(ss);
			}
		}
		int sp=int(P.size())/k*k;
		for(int i=0;i<sp;++i)	b[P[i]]=(i%k)+1;
		for(int i=1;i<=n;++i)	printf("%d ",b[i]);
		puts("");
	}
	return 0;
}