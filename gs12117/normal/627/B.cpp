#include<stdio.h>
int n,k,a,b,q;
long long int ofn[200100];
long long int ita[1<<19];
long long int itb[1<<19];
int qry[200100][3];
void itpush(long long int *it,int loc,long long int val){
	loc+=1<<18;
	it[loc]=val;
	loc/=2;
	while(loc>=1){
		it[loc]=it[loc*2]+it[loc*2+1];
		loc/=2;
	}
}
long long int itcalc(long long int *it,int start,int end){
	long long int res;
	start+=1<<18;
	end+=1<<18;
	res=0;
	while(start<=end){
		if(start%2==1){
			res+=it[start];
			start++;
		}
		if(end%2==0){
			res+=it[end];
			end--;
		}
		start/=2;
		end/=2;
	}
	return res;
}
int main(){
	int i;
	long long int ans;
	scanf("%d%d%d%d%d",&n,&k,&a,&b,&q);
	for(i=0;i<q;i++){
		scanf("%d",&qry[i][0]);
		if(qry[i][0]==1){
			scanf("%d%d",&qry[i][1],&qry[i][2]);
			ofn[qry[i][1]]+=qry[i][2];
			if(ofn[qry[i][1]]>a)itpush(ita,qry[i][1],a);
			else itpush(ita,qry[i][1],ofn[qry[i][1]]);
			if(ofn[qry[i][1]]>b)itpush(itb,qry[i][1],b);
			else itpush(itb,qry[i][1],ofn[qry[i][1]]);
		}
		else{
			scanf("%d",&qry[i][1]);
			ans=itcalc(itb,0,qry[i][1]-1)+itcalc(ita,qry[i][1]+k,n+3);
			printf("%I64d\n",ans);
		}
	}
	return 0;
}