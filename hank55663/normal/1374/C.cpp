#include <bits/stdc++.h>
#define mp make_pair
#define LL long long 
#define pii pair<int,int>
#define x first
#define y second
#define pb push_back
#define sqr(x) ((x)*(x))
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
int main() {
	int t;
	scanf("%d",&t);
	while(t--){
		int n;
		scanf("%d",&n);
		char c[55];
		scanf("%s",c);
		int now=0;
		int ans=0;
		for(int i = 0;c[i]!=0;i++){
			if(c[i]=='(')now++;
			else now--;
			ans=min(ans,now);
		}
		printf("%d\n",-ans);
	}
	return 0;
}