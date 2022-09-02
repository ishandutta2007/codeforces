#include <stdio.h>
  int main(){
    int na,nb,ma,mb,i,j,k,l,x,y,sum=0,max=0;
    int maxx,maxy;
    char q[250][250]={},r[250][250]={};
    int aq[250][250],ar[250][250];
    scanf("%d %d",&na,&ma);
    for(i=0;i<na;i++){
scanf("%s",&q[i]);
    for(j=0;j<ma;j++){
	aq[i][j]=q[i][j]-'0';
	}
	}
    scanf("%d %d",&nb,&mb);
    for(i=0;i<nb;i++){
scanf("%s",&r[i]);
    for(j=0;j<mb;j++){
	ar[i][j]=r[i][j]-'0';
    }
	}
for(i=0;i<na;i++){
for(j=0;j<ma;j++){
aq[100+i][100+j]=aq[i][j];
}
}
for(i=0;i<nb;i++){
for(j=0;j<mb;j++){
ar[100+i][100+j]=ar[i][j];
}
}
     for(x=-na;x<=nb;x++){
    for(y=-ma;y<=mb;y++){
    for(i=0;i<na;i++){
    for(j=0;j<ma;j++){
    if(-i<=x && x<=nb-i-1){
if(-j<=y && y<=mb-j-1){
    sum+=aq[100+i][j+100]*ar[100+i+x][100+j+y];
    }}}}if(max<=sum){max=sum; maxx=x; maxy=y;}sum=0;
    }}
printf("%d %d\n",maxx,maxy);
return 0;
}