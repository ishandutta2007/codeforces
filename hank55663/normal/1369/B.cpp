#include <bits/stdc++.h>
#define mp make_pair
#define LL long long 
#define pii pair<int,int>
#define x first
#define y second
#define pb push_back
#define MEM(x) memset(x,0,sizeof(x))
using namespace std;
int main() {
	int t;
	scanf("%d",&t);
	while(t--){
		int n;
		scanf("%d",&n);
		char c[100005];
		scanf("%s",c);
		int l=0,r=0;
		for(int i=0;c[i]!=0;i++){
			if(c[i]=='0')l++;
			else break;
		}
		int len=strlen(c)-1;
		for(int i = len;i>=0;i--){
			if(c[i]=='1')r++;
			else break;
		}
		if(!l&&!r){
			printf("0\n");
		}
		else{
			for(int i = 0;i<l;i++)printf("0");
			if(l+r!=len+1)printf("0");
			for(int i = 0;i<r;i++)printf("1");
			printf("\n");
		}
	}
	return 0;
}