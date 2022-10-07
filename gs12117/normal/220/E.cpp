#include<stdio.h>
#include<algorithm>
int n;
long long int m;
int a[100100];
int ita[1<<18];
int itb[1<<18];
long long int ans;
struct st{
	int loc,val;
	bool operator<(const st&r)const{
		return val<r.val;
	}
};
st rnb[100100];
void apush(int loc,int val){
	loc+=7;
	loc+=1<<17;
	while(loc!=0){
		ita[loc]+=val;
		loc/=2;
	}
}
void bpush(int loc,int val){
	loc+=7;
	loc+=1<<17;
	while(loc!=0){
		itb[loc]+=val;
		loc/=2;
	}
}
int acalc(int loc){
	loc+=7;
	int res=0;
	loc+=1<<17;
	while(loc!=0){
		if(loc%2==1){
			res+=ita[loc];
			if(((loc+1)&(-(loc+1)))>loc)break;
			loc++;
		}
		loc/=2;
	}
	return res;
}
int bcalc(int loc){
	loc+=7;
	int res=0;
	loc+=1<<17;
	while(loc!=0){
		if(loc%2==0){
			res+=itb[loc];
			if((loc&(-loc))==loc)break;
			loc--;
		}
		loc/=2;
	}
	return res;
}
int main(){
	int i,j,k;
	scanf("%d%I64d",&n,&m);
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
		rnb[i].loc=i;
		rnb[i].val=a[i];
	}
	std::sort(rnb,rnb+n);
	j=3;
	for(i=0;i<n;i++){
		a[rnb[i].loc]=j;
		if(i==n-1||rnb[i].val!=rnb[i+1].val)j++;
	}
	for(i=n-1;i>=0;i--){
		if(m<bcalc(a[i]-1))break;
		m-=bcalc(a[i]-1);
		bpush(a[i],1);
	}
	j=0;
	for(;i<n-1;i++){
		while(j<=i&&m>=bcalc(a[j]-1)+acalc(a[j]+1)){
			m-=bcalc(a[j]-1)+acalc(a[j]+1);
			apush(a[j],1);
			j++;
		}
		ans+=j;
		bpush(a[i+1],-1);
		m+=bcalc(a[i+1]-1)+acalc(a[i+1]+1);
	}
	printf("%I64d",ans);
}