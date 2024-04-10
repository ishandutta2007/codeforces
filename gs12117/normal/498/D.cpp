#include<stdio.h>
int n;
int a[100100];
int q;
int qry[100100][2];
char qkind[100100];
int it[1<<18][60];
const int mod=60;
int stk[50];
void upd(int loc,int val){
	int i;
	loc+=1<<17;
	for(i=0;i<mod;i++){
		if(i%val==0)it[loc][i]=2;
		else it[loc][i]=1;
	}
	loc/=2;
	while(loc!=0){
		for(i=0;i<mod;i++){
			it[loc][i]=it[loc*2][i]+it[loc*2+1][(i+it[loc*2][i])%mod];
		}
		loc/=2;
	}
}
int calc(int start,int end){
	start+=1<<17;
	end+=1<<17;
	int i=0,res=0;
	while(start<=end){
		if(start%2==1){
			res+=it[start][res%mod];
			start++;
		}
		if(end%2==0){
			stk[i]=end;
			i++;
			end--;
		}
		start/=2;
		end/=2;
	}
	i--;
	while(i>=0){
		res+=it[stk[i]][res%mod];
		i--;
	}
	return res;
}
int main(){
	int i,j,k;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
		upd(i,a[i]);
	}
	scanf("%d",&q);
	for(i=0;i<q;i++){
		scanf("%*c%c%d%d",&qkind[i],&qry[i][0],&qry[i][1]);
		if(qkind[i]=='C')upd(qry[i][0]-1,qry[i][1]);
		else printf("%d\n",calc(qry[i][0]-1,qry[i][1]-2));
	}
}