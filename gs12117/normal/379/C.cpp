#include<stdio.h>
#include<algorithm>
int n;
struct node{
	int val,loc;
	bool operator<(const node&r)const{
		return val<r.val;
	}
}a[300100];
int ans[300100];
int main(){
	int i,j;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&a[i].val);
		a[i].loc=i;
	}
	std::sort(a,a+n);
	j=0;
	for(i=0;i<n;i++){
		if(j<a[i].val)j=a[i].val;
		ans[a[i].loc]=j;
		j++;
	}
	for(i=0;i<n;i++){
		printf("%d ",ans[i]);
	}
}