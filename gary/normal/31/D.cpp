#include<cstdio>
#include<algorithm>
int w,h,n,startx,starty,finalx,finaly,walls[300][300]={0},tempans,ans[10010]={0};
void dfs(int x,int y){
	if(x<0||y<0||x>h+h||y>w+w) return;// 
	if(walls[x][y]==1||walls[x][y]==3) return;
	if(walls[x][y]==0)// 
	tempans++;
	walls[x][y]=3;// 
	dfs(x+1,y);
	dfs(x,y+1);
	dfs(x-1,y);
	dfs(x,y-1);
	return;
}
int main(){
	scanf("%d %d %d",&h,&w,&n);
	for(int i=1;i<=n;i++){
		scanf("%d %d %d %d",&startx,&starty,&finalx,&finaly);
		startx+=startx;
		starty+=starty;
		finalx+=finalx;
		finaly+=finaly;
		if(startx==finalx){
			for(int i=starty;i<=finaly;i++)	walls[startx][i]=1;//walls 
		}
		else{
			for(int i=startx;i<=finalx;i++) {walls[i][starty]=1;//walls
			}
			
		}
	}
	for(int i=0;i<=h+h;i++){
		if(i%2==0)//
		{
			for(int j=0;j<=w+w;j++) if(walls[i][j]==0) walls[i][j]=2;
		 } 
		else{
			for(int j=0;j<=w+w;j++) if(walls[i][j]==0&&j%2==0) walls[i][j]=2;
		}
	}
//	for(int i=0;i<=h+h;i++){
//		for(int j=0;j<=w+w;j++){
//		printf("%d ",walls[i][j]);
//	}
//	printf("\n");
//	}	 
	for(int i=0;i<=h+h;i++)
	for(int j=0;j<=w+w;j++){
		tempans=0;dfs(i,j);
		ans[tempans]++;
	} 
	for(int i=1;i<=w*h;i++) for(int j=1;j<=ans[i];j++) printf("%d ",i);
	return 0;
}