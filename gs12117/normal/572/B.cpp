#include<stdio.h>
#include<algorithm>
int n,s;
char tmp[10];
struct ord{
	int d,p,q;
	bool operator<(const ord&r)const{
		if(d>r.d||(d==r.d&&p<r.p))return 1;
		return 0;
	}
};
ord data[1010];
int ans[1010][2];
int main(){
	int i,j,k;
	scanf("%d%d",&n,&s);
	for(i=0;i<n;i++){
		scanf("%s",tmp);
		if(tmp[0]=='S')data[i].d=1;
		scanf("%d%d",&data[i].p,&data[i].q);
	}
	std::sort(data,data+n);
	j=0;
	k=0;
	for(i=0;;i++){
		if(i!=0&&(i==n||data[i].d==0||data[i].p!=data[i-1].p)){
			ans[j][0]=data[i-1].p;
			ans[j][1]=k;
			k=0;
			j++;
		}
		if(j==s||i==n||data[i].d==0){
			break;
		}
		k+=data[i].q;
	}
	for(i=j-1;i>=0;i--){
		printf("S %d %d\n",ans[i][0],ans[i][1]);
	}
	j=0;
	k=0;
	for(i=n-1;;i--){
		if(i!=n-1&&(i==-1||data[i].d==1||data[i].p!=data[i+1].p)){
			printf("B %d %d\n",data[i+1].p,k);
			k=0;
			j++;
		}
		if(j==s||i==-1||data[i].d==1){
			break;
		}
		k+=data[i].q;
	}
}