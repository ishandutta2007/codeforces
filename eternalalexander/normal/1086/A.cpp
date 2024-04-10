#include <bits/stdc++.h>
struct pr {
	int x,y;
}p[10];
int cmp(pr a,pr b){return a.y<b.y;}
int minx=100000,miny=100000,maxx=0,maxy=0;
int main(){
	for(int i=1;i<=3;++i){
		scanf("%d%d",&p[i].x,&p[i].y);
		minx=std::min(minx,p[i].x);
		miny=std::min(miny,p[i].y);
		maxx=std::max(maxx,p[i].x);
		maxy=std::max(maxy,p[i].y);
	}printf("%d\n",maxx-minx+maxy-miny+1);
	std::sort(p+1,p+4,cmp);
	for(int i=minx;i<=maxx;++i)printf("%d %d\n",i,p[2].y);
	for(int i=miny;i<p[2].y;++i)printf("%d %d\n",p[1].x,i);
	for(int i=p[2].y+1;i<=maxy;++i)printf("%d %d\n",p[3].x,i);
	return 0;
}