#include<bits/stdc++.h>
#define pii pair<int,int>
#define pb(x) push_back(x)
#define sqr(x) ((x)*(x))
#define mp(x,y) make_pair((x),(y))
#define N 1000005
typedef long long LL;
using namespace std;
int main(){
	char c[100];
	scanf("%s",c);
	int num=0;
	for(int i=0,j=strlen(c)-1;c[i]!=0;i++,j--){
		if(c[i]!=c[j])
		num++;
	}
	if(num==2||(num==0&&strlen(c)%2==1))
	printf("YES\n");
	else
	printf("NO\n");
}