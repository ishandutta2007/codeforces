#include <bits/stdc++.h>
#define mp make_pair
#define LL long long 
#define pii pair<int,int>
#define x first
#define y second
#define pb push_back
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
int main() {
	int t;
	scanf("%d",&t);
	while(t--){
		int cnt1=0,cnt2=0;
		char c[105];
		scanf("%s",c);
		for(int i=0;c[i]!=0;i++){
			if(c[i]=='0')cnt1++;
			else cnt2++;
		}
		if(min(cnt1,cnt2)&1){
			printf("DA\n");
		}
		else{
			printf("NET\n");
		}
	}
	return 0;
}