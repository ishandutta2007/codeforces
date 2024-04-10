#include<stdio.h>
#include<algorithm>
const int itsize=1<<19;
int n,m;
int d[200100][2];
int qry[200100][2];
struct point{
	int cord,dn,de;
	bool operator<(const point &r)const{
		return cord<r.cord||(cord==r.cord&&de<r.de);
	}
};
point pcmp[400100];
struct query{
	int start,end,num;
	bool operator<(const query &r)const{
		return start>r.start;
	}
};
query ql[200100];
int dlc[200100][2];
int it[itsize*2];
int itz[itsize*2];
int ans[200100];
void push(int start,int end){
	start+=itsize;
	end+=itsize;
	int tstart,tend;
	tstart=start;
	tend=end;
	while(start<=end){
		if(start%2==1){
			itz[start]=1;
			it[start]=0;
			start++;
		}
		if(end%2==0){
			itz[end]=1;
			it[end]=0;
			end--;
		}
		start/=2;
		end/=2;
	}
	start=tstart/2;
	end=tend/2;
	while(start>0){
		if(itz[start]==0){
			it[start]=it[start*2]+it[start*2+1];
		}
		if(start+1<itsize&&itz[start+1]==0){
			it[start+1]=it[start*2+2]+it[start*2+3];
		}
		if(itz[end]==0){
			it[end]=it[end*2]+it[end*2+1];
		}
		if(end-1>0&&itz[end-1]==0){
			it[end-1]=it[end*2-2]+it[end*2-1];
		}
		start/=2;
		end/=2;
	}
}
int calc(int start,int end){
	start+=itsize;
	end+=itsize;
	int i,res;
	for(i=20;i>0;i--){
		if(itz[start>>i]==1){
			itz[(start>>i)*2]=1;
			it[(start>>i)*2]=0;
			itz[(start>>i)*2+1]=1;
			it[(start>>i)*2+1]=0;
		}
		if(itz[end>>i]==1){
			itz[(end>>i)*2]=1;
			it[(end>>i)*2]=0;
			itz[(end>>i)*2+1]=1;
			it[(end>>i)*2+1]=0;
		}
	}
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
	int i,j;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d%d",&d[i][0],&d[i][1]);
		pcmp[i*2].cord=d[i][0];
		pcmp[i*2].dn=i;
		pcmp[i*2].de=0;
		pcmp[i*2+1].cord=d[i][0]+d[i][1];
		pcmp[i*2+1].dn=i;
		pcmp[i*2+1].de=1;
	}
	std::sort(pcmp,pcmp+2*n);
	for(i=0;i<2*n;i++){
		if(pcmp[i].de==0){
			dlc[pcmp[i].dn][0]=i;
		}
		else{
			dlc[pcmp[i].dn][1]=i-1;
		}
	}
	for(i=0;i<2*n-1;i++){
		it[i+itsize]=pcmp[i+1].cord-pcmp[i].cord;
	}
	for(i=itsize-1;i>0;i--){
		it[i]=it[i*2]+it[i*2+1];
	}
	scanf("%d",&m);
	for(i=0;i<m;i++){
		scanf("%d%d",&qry[i][0],&qry[i][1]);
		ql[i].start=qry[i][0]-1;
		ql[i].end=qry[i][1]-1;
		ql[i].num=i;
	}
	std::sort(ql,ql+m);
	j=0;
	for(i=n-1;i>=0;i--){
		push(dlc[i][0],dlc[i][1]);
		while(j<m&&ql[j].start==i){
			ans[ql[j].num]=calc(dlc[ql[j].start][0],dlc[ql[j].end][0]-1);
			j++;
		}
	}
	for(i=0;i<m;i++){
		printf("%d\n",ans[i]);
	}
}