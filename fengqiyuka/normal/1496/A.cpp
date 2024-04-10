#include<cstdio>
#include<cstring>
using namespace std;
const int N=110;
char s[N];
int main()
{
	int T;scanf("%d",&T);
	while(T--){
		int n,K;scanf("%d%d",&n,&K);
		scanf("%s",s+1);
		int pd=0;
		for(int i=1;i<=n/2;i++){
			if(s[i]!=s[n-i+1]) break;
			pd=i;
		}
		if(pd*2==n) pd--;
		if(pd>=K) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}