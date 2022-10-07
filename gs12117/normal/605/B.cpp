#include<stdio.h>
#include<algorithm>
int n,m;
struct eg{
	int a,b,loc;
	bool operator<(const eg&r)const{
		return a<r.a||(a==r.a&&b>r.b);
	}
};
eg s[100100];
int res[100100][2];
int main(){
	int i,j,k,l;
	scanf("%d%d",&n,&m);
	for(i=0;i<m;i++){
		scanf("%d%d",&s[i].a,&s[i].b);
		s[i].loc=i;
	}
	std::sort(s,s+m);
	j=1;
	k=3;
	l=1;
	for(i=0;i<m;i++){
		if(s[i].b==1){
			res[s[i].loc][0]=j;
			res[s[i].loc][1]=j+1;
			j++;
		}
		else{
			if(k>j){
				printf("-1");
				return 0;
			}
			res[s[i].loc][0]=l;
			res[s[i].loc][1]=k;
			l++;
			if(l==k-1){
				l=1;
				k++;
			}
		}
	}
	for(i=0;i<m;i++){
		printf("%d %d\n",res[i][0],res[i][1]);
	}
	return 0;
}