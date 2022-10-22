#include<vector>
#include<cstdio>

using namespace std;

vector<int> E[100000];

int A[100000],i,n,x,r1,r2;

void go(int x)
{
	for(vector<int>::iterator it=E[x].begin();it!=E[x].end();++it)
		if(A[*it]==0)
			A[*it]=x,go(*it);
}

int main()
{
	scanf("%d%d%d",&n,&r1,&r2);
    for(i=1;i<=n;++i)
		if(i!=r1)
			scanf("%d",&x),E[x].push_back(i),E[i].push_back(x);
	A[r2]=r2;
	go(r2);
	for(i=1;i<=n;++i)
		if(i!=r2)
			printf("%d ",A[i]);
}