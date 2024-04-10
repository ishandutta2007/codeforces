#include<bits/stdc++.h>
using namespace std;
int road[100001],sum[100001],from[101],to[101];
int main(){
	int l,b,f;
	scanf("%d %d %d",&l,&b,&f);
//	l+=1;
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		int type,num;
		scanf("%d %d",&type,&num);
		if(type==1){
			bool ansflag=0;
			if(num>l) {
				printf("-1\n");
				continue;
			}
			for(int j=1;j<=l-num+1;j++){
				if(sum[min(l,j+num-1+f)]-sum[max(0,j-b-1)]==0){
//					cout<<min(l,j+num-1+f)<<"minu"<<max(1,j-b-1)<<endl;
					ansflag=1;
					printf("%d\n",j-1);
					from[i]=j;
					to[i]=j+num-1;
					for(int k=j;k<=j+num-1;k++){
						road[k]=1;
					}
					for(int k=1;k<=l;k++) sum[k]=sum[k-1]+road[k];
					
//					for(int k=1;k<=l;k++) cout<<road[k]<<" ";
//					cout<<endl;
//					for(int k=1;k<=l;k++) cout<<sum[k]<<" ";
//					cout<<endl<<endl;;
					break;
				}
			}
			if(!ansflag){
				printf("-1\n");
			}
		}
		else{
			for(int j=from[num];j<=to[num];j++){
				road[j]=0;
			}
			for(int k=1;k<=l;k++) sum[k]=sum[k-1]+road[k];
//			for(int k=1;k<=l;k++) cout<<road[k]<<" ";
//					cout<<endl;
		}
	}
	return 0;
}