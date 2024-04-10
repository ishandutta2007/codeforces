#include<bits/stdc++.h>
using namespace std;

const int N=510;
int a[N],h[N];

bool cmp(int n1,int n2) {return (a[n1]<a[n2]);}

char s[N];

int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	
	memset(s,0,sizeof(s));
	for(int i=1;i<=m;i++) s[i]='0';
	
	for(int i=1;i<=m;i++){
		s[i]='1';
		printf("? %s\n",s+1);
		fflush(stdout);
		scanf("%d",&a[i]);
		s[i]='0';
	}
	
	int Sum=0;
	for(int i=1;i<=m;i++) h[i]=i;
	sort(h+1,h+m+1,cmp);
	
	for(int i=1;i<=m;i++){
		int x=h[i];
		s[x]='1';
		printf("? %s\n",s+1);
		fflush(stdout);
		int t;
		scanf("%d",&t);
		if(t!=Sum+a[x]) s[x]='0';
		else Sum+=a[x];
	}
	
	printf("! %d\n",Sum);
	
	return 0;
}