#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <math.h>
using namespace std;
#define N 100050
int n,cl[N],ce[N],v,q,m;
int fabs(int x) {return x>0?x:-x;}
int main() {
	scanf("%d%d%d%d%d",&n,&m,&cl[0],&ce[0],&v);
	int i,x,y,z,w;
	for(i=1;i<=cl[0];i++) scanf("%d",&cl[i]);
	for(i=1;i<=ce[0];i++) scanf("%d",&ce[i]);
	scanf("%d",&q);
	while(q--) {
		int ans=1<<30;
		scanf("%d%d%d%d",&x,&y,&z,&w);
		if(x==z) {
			printf("%d\n",fabs(y-w)); continue;
		}
		int str1=upper_bound(cl+1,cl+cl[0]+1,y)-cl,str2=str1-1;
		if(str1>=1&&str1<=cl[0]) {
			ans=min(ans,cl[str1]-y+fabs(x-z)+fabs(w-cl[str1]));
		}
		if(str2>=1&&str2<=cl[0]) {
			ans=min(ans,y-cl[str2]+fabs(x-z)+fabs(w-cl[str2]));
		}
		int elv1=upper_bound(ce+1,ce+ce[0]+1,y)-ce,elv2=elv1-1;
		if(elv1>=1&&elv1<=ce[0]) {
			ans=min(ans,ce[elv1]-y+(int)ceil(1.0*fabs(x-z)/v)+fabs(w-ce[elv1]));
		}
		if(elv2>=1&&elv2<=ce[0]) {
			ans=min(ans,y-ce[elv2]+(int)ceil(1.0*fabs(x-z)/v)+fabs(w-ce[elv2]));
		}
		printf("%d\n",ans);
	}

	return 0;
}