#include<stdio.h>
#include<algorithm>
#include<queue>
int n,m,s;
int a[100100];
int b[100100];
int c[100100];
int ans[100100];
struct snode{
	int val;
	int loc;
	bool operator<(const snode &r)const{
		return val<r.val;
	}
};
struct lnode{
	int val;
	int loc;
	bool operator<(const lnode &r)const{
		return val>r.val;
	}
};
snode d[100100];
lnode e[100100];
std::priority_queue<lnode>q;
int f(int x){
	int i,j,k,l;
	lnode p;
	j=0;
	k=0;
	l=0;
	while(!q.empty())q.pop();
	for(i=m-1;i>=0;i--){
		while(j<n&&e[j].val>i){
			p.loc=e[j].loc;
			p.val=c[e[j].loc];
			q.push(p);
			j++;
		}
		if(k==0){
			if(q.empty())return 0;
			k+=x;
			l+=q.top().val;
			if(l>s)return 0;
			q.pop();
		}
		k--;
	}
	return 1;
}
int main(){
	int i,j,k,l,solver;
	scanf("%d%d%d",&n,&m,&s);
	for(i=0;i<m;i++){
		scanf("%d",&a[i]);
		d[i].val=a[i];
		d[i].loc=i;
	}
	for(i=0;i<n;i++){
		scanf("%d",&b[i]);
	}
	for(i=0;i<n;i++){
		scanf("%d",&c[i]);
	}
	std::sort(d,d+m);
	for(i=0;i<n;i++){
		k=-1;
		for(j=18;j>=0;j--){
			k+=(1<<j);
			if(k>=m||d[k].val>b[i])k-=(1<<j);
		}
		e[i].val=k+1;
		e[i].loc=i;
	}
	std::sort(e,e+n);
	i=0;
	for(j=20;j>=0;j--){
		i+=(1<<j);
		if(f(i)==1)i-=(1<<j);
	}
	i++;
	if(i>m){
		printf("NO\n");
	}
	else{
		printf("YES\n");
		lnode p;
		j=0;
		k=0;
		l=i;
		while(!q.empty())q.pop();
		for(i=m-1;i>=0;i--){
			while(j<n&&e[j].val>i){
				p.loc=e[j].loc;
				p.val=c[e[j].loc];
				q.push(p);
				j++;
			}
			if(k==0){
				if(q.empty())return 0;
				k+=l;
				solver=q.top().loc;
				q.pop();
			}
			k--;
			ans[d[i].loc]=solver;
		}
		for(i=0;i<m;i++){
			printf("%d ",ans[i]+1);
		}
	}
}