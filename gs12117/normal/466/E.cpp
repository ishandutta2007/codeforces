#include<stdio.h>
int n,m;
int qry[100100][3];
int en[100100];
int elist[100100];
int root[100100];
int dloc[100100];
int dend[100100];
int darr[100100];
int dtime;
int ndep[100100];
int chk[100100];
int it[1<<19];
int mailn;
int msl[100100];
int mend[100100];
int uft[100100];
void push(int start,int end,int val){
	start+=1<<18;
	end+=1<<18;
	while(start<=end){
		if(start%2==1){
			if(it[start]<val)it[start]=val;
			start++;
		}
		if(end%2==0){
			if(it[end]<val)it[end]=val;
			end--;
		}
		start/=2;
		end/=2;
	}
}
int calc(int loc){
	int res=0;
	loc+=(1<<18);
	while(loc!=0){
		if(it[loc]>res)res=it[loc];
		loc/=2;
	}
	return res;
}
void erase(int start,int end,int val){
	start+=1<<18;
	end+=1<<18;
	while(start<=end){
		if(start%2==1){
			if(it[start]==val)it[start]=0;
			start++;
		}
		if(end%2==0){
			if(it[end]==val)it[end]=0;
			end--;
		}
		start/=2;
		end/=2;
	}
}
int uftf(int loc){
	if(loc==uft[loc])return loc;
	return uft[loc]=uftf(uft[loc]);
}
void dfs(int loc,int dep){
	int i;
	ndep[loc]=dep;
	dloc[loc]=dtime;
	darr[dtime]=loc;
	dtime++;
	chk[loc]=1;
	for(i=en[loc];i<en[loc+1];i++){
		dfs(elist[i],dep+1);
	}
	dend[loc]=dtime-1;
}
int main(){
	int i,j;
	scanf("%d%d",&n,&m);
	for(i=0;i<m;i++){
		scanf("%d",&qry[i][0]);
		if(qry[i][0]==2){
			scanf("%d",&qry[i][1]);
		}
		else{
			scanf("%d%d",&qry[i][1],&qry[i][2]);
		}
		if(qry[i][0]==3)qry[i][2]--;
		if(qry[i][0]==1){
			en[qry[i][2]+2]++;
			root[qry[i][1]]=qry[i][2];
		}
	}
	for(i=0;i<n+3;i++){
		en[i+1]+=en[i];
	}
	for(i=0;i<m;i++){
		if(qry[i][0]==1){
			elist[en[qry[i][2]+1]]=qry[i][1];
			en[qry[i][2]+1]++;
		}
	}
	for(i=1;i<=n;i++){
		if(chk[i]==0&&root[i]==0)dfs(i,1);
		uft[i]=i;
	}
	for(i=1;i<=n;i++){
		push(dloc[i],dend[i],ndep[i]);
	}
	for(i=0;i<m;i++){
		if(qry[i][0]==2){
			msl[mailn]=qry[i][1];
			mend[mailn]=calc(dloc[qry[i][1]]);
			mailn++;
		}
		else if(qry[i][0]==1){
			erase(dloc[qry[i][1]],dend[qry[i][1]],ndep[qry[i][1]]);
			push(dloc[uftf(qry[i][2])],dend[uftf(qry[i][2])],ndep[uftf(qry[i][2])]);
			uft[qry[i][1]]=uftf(qry[i][2]);
		}
		else{
			if(dloc[msl[qry[i][2]]]<dloc[qry[i][1]]||dloc[msl[qry[i][2]]]>dend[qry[i][1]]){
				puts("NO");
			}
			else if(mend[qry[i][2]]>ndep[qry[i][1]]){
				puts("NO");
			}
			else{
				puts("YES");
			}
		}
	}
}