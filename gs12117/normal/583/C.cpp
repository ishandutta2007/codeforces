#include<stdio.h>
#include<queue>
int n;
int a[510];
int b[300100];
std::priority_queue<int> pq;
std::priority_queue<int> del;
int mgcd(int x,int y){
	if(x==0)return y;
	return mgcd(y%x,x);
}
int main(){
	int i,j;
	scanf("%d",&n);
	for(i=0;i<n*n;i++){
		scanf("%d",&b[i]);
		pq.push(b[i]);
	}
	for(i=0;i<n;i++){
		while(del.size()!=0&&del.top()==pq.top()){
			pq.pop();
			del.pop();
		}
		a[i]=pq.top();
		pq.pop();
		for(j=0;j<i;j++){
			del.push(mgcd(a[i],a[j]));
			del.push(mgcd(a[i],a[j]));
		}
		printf("%d ",a[i]);
	}
}