#include<stdio.h>
int n;
int a[200200];
int b[200200];
int orda[200200];
int ordb[200200];
int ordc[200200];
int c[200200];
int it[1<<19];
void push(int loc,int val){
	loc+=1<<18;
	it[loc]=val;
	loc/=2;
	while(loc!=0){
		it[loc]=it[loc*2]+it[loc*2+1];
		loc/=2;
	}
}
int calc(int start,int end){
	int res=0;
	start+=1<<18;
	end+=1<<18;
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
int cloc(int val){
	int ans=1;
	int sum=0;
	while(ans<(1<<18)){
		if(sum+it[ans*2]>val)ans*=2;
		else{
			sum+=it[ans*2];
			ans=ans*2+1;
		}
	}
	return ans-(1<<18);
}
int main(){
	int i;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	for(i=0;i<n;i++){
		push(i,1);
	}
	for(i=0;i<n;i++){
		push(a[i],0);
		orda[i]=calc(0,a[i]);
	}
	for(i=0;i<n;i++){
		scanf("%d",&b[i]);
	}
	for(i=0;i<n;i++){
		push(i,1);
	}
	for(i=0;i<n;i++){
		push(b[i],0);
		ordb[i]=calc(0,b[i]);
		ordc[i]=orda[i]+ordb[i];
	}
	for(i=n-1;i>=0;i--){
		if(i!=0)ordc[i-1]+=ordc[i]/(n-i);
		ordc[i]%=(n-i);
	}
	for(i=0;i<n;i++){
		push(i,1);
	}
	for(i=0;i<n;i++){
		c[i]=cloc(ordc[i]);
		push(c[i],0);
	}
	for(i=0;i<n;i++){
		printf("%d ",c[i]);
	}
}