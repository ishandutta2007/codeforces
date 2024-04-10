#include<bits/stdc++.h>
#define rep(i,x,y) for(auto i=(x);i<=(y);++i)
#define dep(i,x,y) for(auto i=(x);i>=(y);--i)
#define fr first
#define sc second
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
const int N=2e6+10;
const int mo=1e9+7;
char a[N],b[N],c[N];
void sol(){
	scanf("%s%s%s",a+1,b+1,c+1);
	int n=strlen(a+1);
	rep(i,1,n)if(a[i]!=c[i]&&b[i]!=c[i]){
		printf("NO\n");return;
	}
	printf("YES\n");
}
int main(){int t;
	scanf("%d",&t);
	rep(i,1,t)sol();
}