#include<bits/stdc++.h>
#define pii pair<int,int>
#define x first
#define y second
#define mp(x,y) make_pair((x),(y))
#include<vector>
using namespace std;

int main(){
	int k[4];
	for(int i=0;i<4;i++)
	scanf("%d",&k[i]);
	long long int a=min(min(k[0],k[2]),k[3]);
	long long int ans=a*256;
	k[0]-=a;
	int b=min(k[1],max(0,k[0]));
	ans+=b*32;
	printf("%d\n",ans);
}