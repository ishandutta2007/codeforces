#include<stdio.h>
#include<algorithm>
int n,a,b;
struct node{
	int loc,val;
	bool operator<(const node&r)const{
		return val<r.val;
	}
};
node c[100100];
int d[100100];
int e[100100];
int q[100100];
int qs,qe;
int find(int x){
	int i,j;
	j=-1;
	for(i=17;i>=0;i--){
		j+=(1<<i);
		if(j>=n||c[j].val>x)j-=(1<<i);
	}
	if(j<0||c[j].val!=x)return -1;
	return j;
}
int main(){
	int i,j,k;
	scanf("%d%d%d",&n,&a,&b);
	for(i=0;i<n;i++){
		scanf("%d",&c[i].val);
		c[i].loc=i;
	}
	std::sort(c,c+n);
	qs=qe=0;
	for(i=0;i<n;i++){
		if(find(a-c[i].val)==-1){
			d[i]=1;
			q[qe]=i;
			qe++;
		}
		else{
			d[i]=0;
		}
	}
	for(;qs<qe;qs++){
		if(find(b-c[q[qs]].val)==-1){
			printf("NO");
			return 0;
		}
		if(d[find(b-c[q[qs]].val)]==0){
			d[find(b-c[q[qs]].val)]=1;
			q[qe]=find(b-c[q[qs]].val);
			qe++;
		}
		if(find(a-c[q[qs]].val)!=-1&&d[find(a-c[q[qs]].val)]==0){
			d[find(a-c[q[qs]].val)]=1;
			q[qe]=find(a-c[q[qs]].val);
			qe++;
		}
	}
	for(i=0;i<n;i++){
		e[c[i].loc]=d[i];
	}
	puts("YES");
	for(i=0;i<n;i++){
		printf("%d ",e[i]);
	}
}