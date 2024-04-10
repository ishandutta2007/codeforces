#include<cstdio>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;
#define pb push_back

const int st=1005;
int t[st];

int main()
{
	int n;int razem=0;
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		scanf("%d",&t[i]);
		razem+=t[i];
	}
	int a,b;
	scanf("%d%d",&a,&b);int s=0;
	for(int i=1;i<=n;++i){
		s+=t[i];
		if(s>=a && razem-s>=a && s<=b && razem-s<=b){
			printf("%d",i+1);
			return 0;
		}
	}
	printf("0");
	return 0;
}