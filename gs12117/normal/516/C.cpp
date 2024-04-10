#include<stdio.h>
int n,m;
int d[200100];
long long int td[200100];
int h[200100];
int qry[100100][2];
struct itnod{
	long long int maxtd;
	long long int mintd;
	long long int ait;
	int nulli;
	itnod operator+(itnod a){
		if(nulli==0)return a;
		if(a.nulli==0)return *this;
		itnod b=a;
		if(mintd<b.mintd)b.mintd=mintd;
		if(maxtd>b.maxtd)b.maxtd=maxtd;
		if(ait>b.ait)b.ait=ait;
		if(a.maxtd-mintd>b.ait)b.ait=a.maxtd-mintd;
		return b;
	}
};
itnod it[1<<19];
long long int calc(int start,int end){
	start+=1<<18;
	end+=1<<18;
	itnod res,fres;
	res.nulli=0;
	fres.nulli=0;
	while(start<=end){
		if(start%2==1){
			res=res+it[start];
			start++;
		}
		if(end%2==0){
			fres=it[end]+fres;
			end--;
		}
		start/=2;
		end/=2;
	}
	res=res+fres;
	return res.ait;
}
int main(){
	int i;
	scanf("%d%d",&n,&m);
	for(i=0;i<n;i++){
		scanf("%d",&d[i]);
		d[n+i]=d[i];
	}
	for(i=0;i<n;i++){
		scanf("%d",&h[i]);
		h[n+i]=h[i];
	}
	for(i=0;i<2*n;i++){
		td[i+1]=d[i]+td[i];
		it[i+(1<<18)].nulli=1;
		it[i+(1<<18)].ait=0;
		it[i+(1<<18)].mintd=td[i]-2*h[i];
		it[i+(1<<18)].maxtd=td[i]+2*h[i];
	}
	for(i=(1<<18)-1;i>0;i--){
		it[i]=it[i*2]+it[i*2+1];
	}
	for(i=0;i<m;i++){
		scanf("%d%d",&qry[i][0],&qry[i][1]);
		if(qry[i][0]<=qry[i][1]){
			qry[i][0]+=n;
		}
		printf("%I64d\n",calc(qry[i][1],qry[i][0]-2));
	}
}