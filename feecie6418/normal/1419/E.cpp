#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,p[10005],pk[10005];
vector<int> vec[105];
int main(){
	int t;
	cin>>t;
	while(t--){
		int tn,mxk=0;
		memset(pk,0,sizeof(pk));
		cin>>n,p[0]=0,tn=n;
		for(int i=2;i*i<=tn;i++){
			if(tn%i==0){
				p[++p[0]]=i;
				while(tn%i==0)tn/=i,mxk=max(mxk,++pk[p[0]]);
			}
		}
		if(tn>1)p[++p[0]]=tn,pk[p[0]]=1;
		if(p[0]==2&&pk[1]==1&&pk[2]==1){
			printf("%d %d %d\n%d\n",p[1],p[2],n,1);
			continue;
		}
		for(int i=2;i*i<=n;i++){
			if(n%i==0){
				for(int j=1;j<=p[0];j++){
					if(i%p[j]==0){
						vec[j].push_back(i);
						break;
					}
				}
				if(i*i!=n){
					for(int j=1;j<=p[0];j++){
						if((n/i)%p[j]==0){
							vec[j].push_back(n/i);
							break;
						}
					}
				}
			}
		}
		for(int i=1;i<=p[0];i++)sort(vec[i].begin(),vec[i].end());
		if(pk[1]>1||pk[2]>1){
			for(int i=1;i<=p[0];i++)for(int j:vec[i])cout<<j<<' ';
			printf("%d\n0\n",n);
			for(int i=1;i<=p[0];i++)vec[i].clear();
		}
		else if(p[0]==3&&mxk==1){
			printf("%d %d %d %d %d %d %d\n0\n",p[1],n,p[1]*p[2],p[2],p[2]*p[3],p[3],p[3]*p[1]);
			for(int i=1;i<=p[0];i++)vec[i].clear();
		}
		else {
			int p1=0,p2=0;
			for(int j:vec[1])if(j%p[2]==0&&!p1)p1=j;else if(j%p[2]==0&&!p2)p2=j;
			printf("%d %d %d %d ",p[1],p1,p[2],p2);
			for(int j:vec[1])if(j!=p1&&j!=p2&&j!=p[1])printf("%d ",j);
			for(int i=2;i<=p[0];i++)for(int j:vec[i])if(j!=p[2])cout<<j<<' ';
			printf("%d\n0\n",n);
			for(int i=1;i<=p[0];i++)vec[i].clear();
		}
	}
}