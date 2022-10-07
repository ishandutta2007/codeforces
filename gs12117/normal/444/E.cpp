#include<stdio.h>
#include<algorithm>
int n;
struct edge{
	int a,b,cost;
	bool operator<(const edge&r)const{
		return cost<r.cost;
	}
};
edge data[3010];
int x[3010];
int uft[3010];
int pnt[3010];
int xsum;
int uftf(int loc){
	if(loc==uft[loc])return loc;
	return uft[loc]=uftf(uft[loc]);
}
int main(){
	int i;
	scanf("%d",&n);
	for(i=0;i<n-1;i++){
		scanf("%d%d%d",&data[i].a,&data[i].b,&data[i].cost);
	}
	for(i=1;i<=n;i++){
		scanf("%d",&x[i]);
	}
	std::sort(data,data+(n-1));
	for(i=1;i<=n;i++){
		xsum+=x[i];
		uft[i]=i;
		pnt[i]=x[i]+1;
	}
	for(i=0;i<n-1;i++){
		pnt[uftf(data[i].b)]+=pnt[uftf(data[i].a)];
		uft[uftf(data[i].a)]=uftf(data[i].b);
		if(pnt[uftf(data[i].b)]>xsum){
			break;
		}
	}
	printf("%d",data[i].cost);
}