#include<cstdio>
#define rep(i,x,y) for(int i=(x);i<=(y);i++)
#define N 2000
using namespace std;
int n,m,x,y,tp,ans;char c,s[N];
int main(){
	scanf("%d",&n);scanf("%s",s+1);
	scanf("%d",&m);
	rep(i,1,m){
		scanf("%d %c",&x,&c);y=1;tp=x;ans=0;
		rep(j,1,n){
			for(;y<=n;y++)if(s[y]!=c){
				if(!tp)break;tp--;
			}
			if(s[j]!=c)tp++;
			if(y-j>ans)ans=y-j;
		}
		printf("%d\n",ans);
	}
}