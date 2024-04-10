#include<stdio.h>
#include<algorithm>
int n;
struct spell{
	int a,b,c,d;
	int ord;
	bool operator<(const spell&r)const{
		return a<r.a;
	}
};
spell p[100100];
int it[1<<18];
int chk[100100];
int tm[100100];
int bef[100100];
int cl[100100];
int cln;
int nl[100100];
int nln;
int res[100100];
int bsrc(int x){
	int i,j,k;
	i=-1;
	for(j=18;j>=0;j--){
		if(i+(1<<j)<n&&p[i+(1<<j)].a<=x)i+=1<<j;
	}
	return i;
}
int calc(int x){
	if(x==-1)return n;
	int start=1<<17;
	int end=x+(1<<17);
	int res=n;
	while(start<=end){
		if(start%2==1){
			if(p[res].b>p[it[start]].b)res=it[start];
			start++;
		}
		if(end%2==0){
			if(p[res].b>p[it[end]].b)res=it[end];
			end--;
		}
		start/=2;
		end/=2;
	}
	return res;
}
void pop(int x){
	x+=1<<17;
	it[x]=n;
	x/=2;
	while(x!=0){
		if(p[it[x*2+1]].b>p[it[x*2]].b){
			it[x]=it[x*2];
		}
		else{
			it[x]=it[x*2+1];
		}
		x/=2;
	}
}
int main(){
	int i,j,flag=0;
	int x,y;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d%d%d%d",&p[i].a,&p[i].b,&p[i].c,&p[i].d);
		p[i].ord=i;
		if(p[i].a==0&&p[i].b==0){
			flag=1;
		}
	}
	if(flag==0){
		printf("-1");
		return 0;
	}
	std::sort(p,p+n);
	p[n].b=1234567890;
	p[n+1].ord=n+1;
	for(i=0;i<n;i++){
		it[i+(1<<17)]=i;
	}
	for(i=(1<<17)-1;i>=0;i--){
		if(p[it[i*2+1]].b>p[it[i*2]].b){
			it[i]=it[i*2];
		}
		else{
			it[i]=it[i*2+1];
		}
	}
	cl[0]=n+1;
	cln=1;
	while(cln!=0){
		nln=0;
		for(i=0;i<cln;i++){
			x=bsrc(p[cl[i]].c);
			while(1){
				y=calc(x);
				if(p[y].b>p[cl[i]].d)break;
				pop(y);
				tm[p[y].ord]=tm[p[cl[i]].ord]+1;
				bef[p[y].ord]=p[cl[i]].ord;
				chk[p[y].ord]=1;
				nl[nln]=y;
				nln++;
			}
		}
		cln=nln;
		for(i=0;i<cln;i++){
			cl[i]=nl[i];
		}
	}
	if(chk[n-1]==0){
		printf("-1");
		return 0;
	}
	printf("%d\n",tm[n-1]);
	i=0;
	j=n-1;
	while(j!=n+1){
		res[i]=j;
		i++;
		j=bef[j];
	}
	i--;
	while(i>=0){
		printf("%d ",res[i]+1);
		i--;
	}
	return 0;
}