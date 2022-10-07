#include<stdio.h>
#include<algorithm>
int n,m;
int a[200100];
int q[200100][2];
int ers[1001000];
int it[1<<19];
int mod=1000000007;
int ans[200100];
int last[1001000];
struct qry{
	int loc;
	int xs,xd;
	bool operator<(const qry&r)const{
		return xd<r.xd;
	}
};
qry ql[200100];
long long int mpow(long long int x,long long int y){
	if(y==0)return 1;
	long long int d=mpow(x,y/2);
	d*=d;
	d%=mod;
	if(y%2==1){
		d*=x;
		d%=mod;
	}
	return d;
}
long long int inv(int x){
	return mpow(x,mod-2);
}
void push(int start,int end,long long int val){
	start+=1<<18;
	end+=1<<18;
	while(start<=end){
		if(start%2==1){
			it[start]=(it[start]*val)%mod;
			start++;
		}
		if(end%2==0){
			it[end]=(it[end]*val)%mod;
			end--;
		}
		start/=2;
		end/=2;
	}
}
int calc(int x){
	x+=1<<18;
	long long int d=1;
	while(x>0){
		d*=it[x];
		d%=mod;
		x/=2;
	}
	return d;
}
int main(){
	int i,j,k;
	for(i=1;i<(1<<19);i++)it[i]=1;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	scanf("%d",&m);
	for(i=0;i<m;i++){
		scanf("%d%d",&q[i][0],&q[i][1]);
		ql[i].loc=i;
		ql[i].xs=q[i][0]-1;
		ql[i].xd=q[i][1]-1;
	}
	std::sort(ql,ql+m);
	j=0;
	for(i=0;i<n;i++){
		push(0,i,a[i]);
		for(k=2;k*k<=a[i];k++){
			if(a[i]%k==0){
				while(a[i]%k==0)a[i]/=k;
				push(last[k],i,((k-1)*inv(k))%mod);
				last[k]=i+1;
			}
		}
		if(a[i]!=1){
			k=a[i];
			push(last[k],i,((k-1)*inv(k))%mod);
			last[k]=i+1;
		}
		while(j<m&&ql[j].xd==i){
			ans[ql[j].loc]=calc(ql[j].xs);
			j++;
		}
	}
	for(i=0;i<m;i++){
		printf("%d\n",ans[i]);
	}
}