#include<cstdio>
#include<vector>
#include<algorithm>
#include<set>
#include<cstring>
#define pb push_back
#define ll long long
using namespace std;

int n,m;
char s[1000005];
int t[1000005];
int a,b;

int main()
{
	scanf("%s",s);
	n=strlen(s);
	if(s[0]==s[1])t[0]=1;
	for(int i=1;i<n-1;++i){
		t[i]=t[i-1];
		if(s[i]==s[i+1])t[i]++;
	}
	t[n-1]=t[n-2];
	scanf("%d",&m);
	while(m--){
		scanf("%d%d",&a,&b);
		a--;
		b--;
		if(a>0)printf("%d\n",t[b-1]-t[a-1]);
		else printf("%d\n",t[b-1]);
	}
	return 0;
}