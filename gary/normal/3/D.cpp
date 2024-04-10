#include<bits/stdc++.h>
using namespace std;
struct node{
	int A;
	int B;
	int num;
	int next;
	int last;
}cost[50001];
int len,tot,sum[50001];long long ans=0;
string str;
map<int,bool> m1;
bool cmp(node a,node b){
	return a.B-a.A>b.B-b.A;
}
int main(){
	cin>>str;
	len=str.length();
	for(int i=0;i<len;i++){
		if(str[i]=='?'){
			tot++;
			scanf("%d %d",&cost[tot].A,&cost[tot].B);
			ans+=cost[tot].B;
			cost[tot].num=i;	
			str[i]=')';
		}
	}
//	cout<<str<<endl;
//	if(str[0]=='(') sum[0]=1;
//	else sum[0]=-1;
	sort(cost+1,cost+1+tot,cmp);
	for(int i=0;i<=tot;i++){
		cost[i].next=i+1;
		cost[i].last=i-1;
	} 
	cost[0].num=0x3f3f3f3f;
	for(int i=0;i<len;i++){
		if(str[i]==')') sum[i]=sum[max(0,i-1)]-1;
		else sum[i]=sum[max(i-1,0)]+1;
		if(sum[i]<0){
			int j; 
			for(j=0;j<=tot;j=cost[j].next){
				if(cost[j].num<=i){
//					m1[cost[j].num]=true;
					break;
				} 
			}
			if(j==tot+1) {
				printf("-1\n");
				return 0;
			}
			cost[cost[j].last].next=cost[j].next;
			cost[cost[j].next].last=cost[j].last;
//			cout<<str<<endl;
//			cout<<"j:"<<j<<"sum:"<<sum[i]<<"I:"<<i<<endl;
			ans-=cost[j].B-cost[j].A;
			str[cost[j].num]='(';
			sum[i]+=2;
//			cout<<str<<" "<<sum[i]<<endl;
		}
	}
	if(sum[len-1]) {
		printf("-1\n");
		return 0;
	}
//	for(int i=0;i<len;i++) cout<<sum[i]<<" ";
//	cout<<endl;
	cout<<ans<<endl;
	cout<<str<<endl;
	return 0;
}