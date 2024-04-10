#include<stdio.h>
int n;
int a[66000];
int s[66000];
int m;
int edge[100100][2];
int chk[66000];
int que[66000];
int qs,qe;
int main(){
	int i;
	scanf("%d",&n);
	qs=qe=0;
	for(i=0;i<n;i++){
		scanf("%d%d",&a[i],&s[i]);
		if(a[i]==1){
			chk[i]=1;
			que[qe]=i;
			qe++;
		}
	}
	for(qs=0;qs<qe;qs++){
		if(a[que[qs]]==0)continue;
		edge[m][0]=que[qs];
		edge[m][1]=s[que[qs]];
		m++;
		a[que[qs]]--;
		a[s[que[qs]]]--;
		s[s[que[qs]]]^=que[qs];
		if(a[s[que[qs]]]==1){
			chk[s[que[qs]]]=1;
			que[qe]=s[que[qs]];
			qe++;
		}
		s[que[qs]]=0;
	}
	printf("%d\n",m);
	for(i=0;i<m;i++){
		printf("%d %d\n",edge[i][0],edge[i][1]);
	}
}