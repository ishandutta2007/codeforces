#include<stdio.h>
#include<queue>
int n,m,d,p;
int a[1010][1010];
long long int ans;
long long int ls[1010];
long long int rs[1010];
long long int ldp[1001000];
long long int rdp[1001000];
std::priority_queue<long long int>q;
int main(){
	int i,j;
	long long int tmp;
	scanf("%d%d%d%d",&n,&m,&d,&p);
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			scanf("%d",&a[i][j]);
			ls[i]+=a[i][j];
			rs[j]+=a[i][j];
		}
	}
	for(i=0;i<n;i++){
		q.push(ls[i]);
	}
	for(i=0;i<d;i++){
		tmp=q.top();
		q.pop();
		q.push(tmp-p*m);
		ldp[i+1]=ldp[i]+tmp;
	}
	while(q.size()!=0){
		q.pop();
	}
	for(i=0;i<m;i++){
		q.push(rs[i]);
	}
	for(i=0;i<d;i++){
		tmp=q.top();
		q.pop();
		q.push(tmp-p*n);
		rdp[i+1]=rdp[i]+tmp;
	}
	for(i=0;i<=d;i++){
		tmp=ldp[i]+rdp[d-i]-((long long int)i)*(d-i)*p;
		if(i==0||tmp>ans)ans=tmp;
	}
	printf("%I64d",ans);
}