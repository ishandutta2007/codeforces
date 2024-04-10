#include<stdio.h>
#include<algorithm>
using namespace std;
int v[100000];
int d[100000];
int main(){
	int a,b;scanf("%d%d",&a,&b);
	for(int i=0;i<b;i++){
		int c,d;
		scanf("%d%d",&c,&d);
		d--;c--;
		v[c]++;
		v[d]++;
	}
	if(b==a-1){
		bool ok=true;
		for(int i=0;i<a;i++){
			d[v[i]]++;
		}
		if(d[1]==2&&d[2]==a-2)printf("bus topology\n");
		else if(d[a-1]==1&&d[1]==a-1)printf("star topology\n");
		else printf("unknown topology\n");
	}else if(b==a){
		bool ok=true;
		for(int i=0;i<a;i++)if(v[i]!=2)ok=false;
		if(ok)printf("ring topology\n");
		else printf("unknown topology\n");
	}else{
		printf("unknown topology\n");
	}
}