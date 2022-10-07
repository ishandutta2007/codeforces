#include<stdio.h>
#include<algorithm>
int n,m;
int ax[200100];
int ay[200100];
int az[200100];
char c[200100][10];
struct qry{
	int loc,orig;
	bool operator<(const qry&r)const{
		return loc<r.loc;
	}
};
qry b[200100];
int it[1<<19];
int left[200100];
int up[200100];
void push(int x){
	x+=3;
	int val=x;
	x+=1<<18;
	while(x!=0){
		if(val>it[x]){
			it[x]=val;
		}
		x/=2;
	}
}
int calc(int x){
	x+=3;
	int res=-99999;
	x+=1<<18;
	int y=1<<18;
	while(x>=y){
		if(x%2==0){
			if(it[x]>res){
				res=it[x];
			}
			x--;
		}
		x/=2;
		y/=2;
	}
	return res-3;
}
int main(){
	int i,j,k;
	scanf("%d%d",&n,&m);
	for(i=0;i<m;i++){
		scanf("%d%d%s",&ax[i],&ay[i],c[i]);
		if(c[i][0]=='U')ay[i]=1;
		else ay[i]=0;
		b[i].orig=i;
		b[i].loc=ax[i];
	}
	push(0);
	std::sort(b,b+m);
	k=1;
	for(i=0;i<m;i++){
		az[b[i].orig]=k;
		if(b[i].loc!=b[i+1].loc)k++;
	}
	left[0]=0;
	up[0]=0;
	for(i=0;i<m;i++){
		j=calc(az[i]);
		if(j==az[i]){
			printf("0\n");
		}
		else if(ay[i]==1){
			printf("%d\n",n+1-ax[i]-up[j]);
			up[az[i]]=up[j];
			left[az[i]]=ax[i];
		}
		else{
			printf("%d\n",ax[i]-left[j]);
			up[az[i]]=up[j];
			left[az[i]]=left[j];
			up[j]=n+1-ax[i];
		}
		push(az[i]);
	}
}