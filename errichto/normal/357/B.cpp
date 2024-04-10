#include<cstdio>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;
#define pb push_back

const int st=1000123;
bool byl[st];
int col[st];


int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	while(m--){
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		if(byl[b])swap(a,b);if(byl[c])swap(a,c);
			col[b]=(col[a]+1)%3;
			col[c]=(col[a]+2)%3;
		byl[a]=byl[b]=byl[c]=1;
	}
	for(int i=1;i<=n;++i)printf("%d ",col[i]+1);
	return 0;
}