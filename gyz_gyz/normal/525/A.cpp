#include<cstdio>
#define rep(i,x,y) for(int i=(x);i<=(y);i++)
using namespace std;
int a[26],ans,n;char c[500000];
int main(){
	scanf("%d",&n);scanf("%s",c);
	rep(i,0,n-2){
		int x=c[i*2]-'a';
		int y=c[i*2+1]-'A';
		a[x]++;if(!a[y])ans++;else a[y]--;
	}
	printf("%d\n",ans);
}