#include<bits/stdc++.h>
#define pii pair<int,int>
#define x first
#define y second
#define mp(x,y) make_pair((x),(y))
#include<vector>
using namespace std;

int main(){
	int n;
	scanf("%d",&n);
	char c[100005];
	scanf("%s",c);
	int a[200];
	memset(a,0,sizeof(a));
	for(int i=0;i<n;i++)
	a[c[i]]++;
	if(a['A']>a['D'])
	printf("Anton\n");
	else if(a['A']==a['D'])
	printf("Friendship\n");
	else
	printf("Danik\n");
}